/* Copyright (c) 2017 Cesar Lombao
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#include <sys/time.h>

#include "lxz80.h"
#include "z80-helper.h"


/**********************************************************************/
/* THE z80 															  */

t_z80 z80;
/**********************************************************************/

/**********************************************************************/
void z80_reset ();
extern void z80_decoding();
/**********************************************************************/		


//----------------------------------------------------------------------
t_z80 * z80_init( const int clock, t_callback_readio read_io , t_callback_writeio write_io ,  t_callback_readram read_ram , t_callback_writeram write_ram   ) {
	
	z80.clock = clock;
	
	/* set I/O and RAM callbacks */
	z80.read_io = read_io;
	z80.write_io = write_io;
	z80.read_ram = read_ram;
	z80.write_ram = write_ram;
	
	for(int a=0;a<Z80_NUM_REGS;a++) {
		switch(a) {
			case AF:		strcpy(z80.nameregs[a],"AF"); break;
			case AFPLUS:	strcpy(z80.nameregs[a],"AF'");break;
			case BC:		strcpy(z80.nameregs[a],"BC"); break;
			case DE:		strcpy(z80.nameregs[a],"DE"); break;
			case HL:		strcpy(z80.nameregs[a],"HL"); break;
			case BCPLUS:	strcpy(z80.nameregs[a],"BC'"); break;
			case DEPLUS:	strcpy(z80.nameregs[a],"DE'"); break;
			case HLPLUS:	strcpy(z80.nameregs[a],"HL'"); break;
			case IX:		strcpy(z80.nameregs[a],"IX"); break;
			case IY:		strcpy(z80.nameregs[a],"IY"); break;
			case SP:		strcpy(z80.nameregs[a],"SP"); break;
			case WZ:		strcpy(z80.nameregs[a],"WZ"); break;
			case PC:		strcpy(z80.nameregs[a],"PC"); break;
			case IR:		strcpy(z80.nameregs[a],"IR"); break;
		}
	}
	z80_reset();
	return &z80;
}


//----------------------------------------------------------------------
int z80_run ( ) {

 struct timespec tpstart;
 struct timespec tpend;
 struct timespec sleep;
 int virtualclock=0; 	/* in nanoseconds */
 int realclock=0; /* in nanoseconds */
 	
		sleep.tv_sec = 0;
		
		clock_gettime(CLOCK_REALTIME,&tpstart);
		
		while( z80.status.HALT != Z80_TRUE ) {
			if ( z80.status.RST == Z80_TRUE ) 	{ z80_reset(); }
			
			/* non mask interrupt */
			if ( z80.status.NMI == Z80_TRUE ) {
				_Z80_PUSH_REG16 ( PC );
				z80.regs[PC].REG16 = 0x0066;
				z80.status.IFF2 = z80.status.IFF1;
				z80.status.IFF1 = 0;
				z80.status.NMI = Z80_FALSE;
			}
			else {
				/* masked int, only supported MODE 1 *****/
				/* there is a little problem with checking if last intruction was EI */
				if ( z80.status.INT == Z80_TRUE && z80.status.IFF1 == 1 && z80.status.REGINST != 0xFB ) {
					_Z80_PUSH_REG16 ( PC );
					z80.regs[PC].REG16 = 0x0038;
					z80.status.INT = Z80_FALSE;	
				}
			}
			
			/* decode instruction */
			_Z80_FETCH_INST;
			
			/* Decode */
			z80_decoding();
			z80.status.totalts += z80.status.ts;
			
			/* wait or not wait */
			virtualclock += z80.status.ts *  (1000 / z80.clock );
			clock_gettime(CLOCK_REALTIME,&tpend);
			realclock += tpend.tv_nsec - tpstart.tv_nsec;
			tpstart = tpend;
			
			if ( virtualclock > realclock ) {
				virtualclock = 0 ; realclock = 0;
				sleep.tv_nsec = virtualclock - realclock;
				nanosleep(&sleep,NULL);
			}
		
		}		
		
	return EXIT_SUCCESS;
}

//----------------------------------------------------------------------
void z80_reset () {
	z80.regs[PC].REG16 		= 0;
	z80.regs[IR].REG16 		= 0;
	z80.status.IFF1 		= 0;
	z80.status.IFF2 		= 0;
	z80.regs[AF].REG16 		= 0xFFFF;
	z80.regs[SP].REG16		= 0xFFFF;   
	z80.status.HALT  		= Z80_FALSE;
	z80.status.NMI  		= Z80_FALSE;
	z80.status.RST  		= Z80_FALSE;
	z80.status.INT  		= Z80_FALSE;
	z80.status.IMODE		= Z80_IM0;
	z80.status.totalts		= 0;			
}



//----------------------------------------------------------------------
// Signals
void z80_signal_rst() 	{ z80.status.RST = Z80_TRUE; }
void z80_signal_halt() 	{ z80.status.HALT = Z80_TRUE; }
void z80_signal_int() 	{ z80.status.INT = Z80_TRUE; }
void z80_signal_nmi() 	{ z80.status.NMI = Z80_TRUE; }


//----------------------------------------------------------------------

uint16_t z80_show_af() { return (z80.regs[AF].REG16); }
uint16_t z80_show_bc() { return (z80.regs[BC].REG16); }
uint16_t z80_show_de() { return (z80.regs[DE].REG16); }
uint16_t z80_show_hl() { return (z80.regs[HL].REG16); }
uint16_t z80_show_ix() { return (z80.regs[IX].REG16); }
uint16_t z80_show_iy() { return (z80.regs[IY].REG16); }

uint64_t z80_show_totalts() { return (z80.status.totalts); }


//----------------------------------------------------------------------
void z80_write_reg_a(uint8_t v) { z80.regs[AF].H = v; }
