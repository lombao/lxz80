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

#include "z80.h"
#include "z80-helper.h"


/**********************************************************************/
/* THE z80 															  */
t_z80 z80;
/**********************************************************************/

/**********************************************************************/
/* EXTERNALLY DEFINED FUNCTIONS										  */
extern void z80_decoding();
/**********************************************************************/		


//----------------------------------------------------------------------
void z80_init( struct z80interface * interface ) {
	
	/* set the interface */
	z80.interface = interface;
	z80_reset();
}


//----------------------------------------------------------------------
int z80_run ( ) {

 struct timespec tpstart;
 struct timespec tpend;
  
 struct timespec thesleep;
 long int virtualclock=0; 	/* in nanoseconds */
 long int realclock=0; /* in nanoseconds */
 	
		thesleep.tv_sec = 0;
		clock_gettime(CLOCK_REALTIME,&tpstart);
		
		while( (z80.interface->signals.HALT != Z80_TRUE) && ( z80.interface->error.number == 0 ) ) {
			
			if ( z80.interface->signals.RST == Z80_TRUE ) 	{ z80_reset(); }
			
			/* non mask interrupt */
			if ( z80.interface->signals.NMI == Z80_TRUE ) {
				_Z80_PUSH_REG16 ( PC );
				z80.regs[PC].REG16 = 0x0066;
				z80.status.IFF2 = z80.status.IFF1;
				z80.status.IFF1 = 0;
				z80.interface->signals.NMI = Z80_FALSE;
			}
			else {
				/* masked int, only supported MODE 1 *****/
				/* there is a little problem with checking if last intruction was EI */
				if ( z80.interface->signals.INT == Z80_TRUE && z80.status.IFF1 == 1 && z80.status.REGINST != 0xFB ) {
					_Z80_PUSH_REG16 ( PC );
					z80.regs[PC].REG16 = 0x0038;
					z80.interface->signals.INT = Z80_FALSE;	
				}
			}
			
			/* decode instruction */
			_Z80_FETCH_INST;
			
			/* Decode */
			z80_decoding();
			z80.interface->totalts += z80.status.ts;
			
			/* wait or not wait */
			virtualclock += z80.status.ts *  (1000 / z80.interface->clock );
			clock_gettime(CLOCK_REALTIME,&tpend);	
			realclock = (tpend.tv_nsec - tpstart.tv_nsec) +  ((tpend.tv_sec - tpstart.tv_sec)*1000000000L); 
			
			/* this is never accurate, the nanosleep resolution is far from perfect */
			if ( virtualclock > realclock ) {
				thesleep.tv_nsec = ((virtualclock - realclock));				
				clock_nanosleep(CLOCK_REALTIME,0,&thesleep,NULL);
			}
		}		
	

	return EXIT_SUCCESS;
}


//----------------------------------------------------------------------
// Signals
void z80_signal_rst() 	{ z80.interface->signals.RST 	= Z80_TRUE; }
void z80_signal_halt() 	{ z80.interface->signals.HALT 	= Z80_TRUE; }
void z80_signal_int() 	{ z80.interface->signals.INT 	= Z80_TRUE; }
void z80_signal_nmi() 	{ z80.interface->signals.NMI 	= Z80_TRUE; }


//----------------------------------------------------------------------
// read registers into the z80interface struct
void z80_readstatus() {
	
	z80.interface->registers.AF = z80.regs[AF].REG16; 
	z80.interface->registers.BC = z80.regs[BC].REG16;
	z80.interface->registers.DE = z80.regs[DE].REG16; 
	z80.interface->registers.HL = z80.regs[HL].REG16;
	z80.interface->registers.AFPLUS = z80.regs[AFPLUS].REG16;
	z80.interface->registers.BCPLUS = z80.regs[BCPLUS].REG16;
	z80.interface->registers.DEPLUS = z80.regs[DEPLUS].REG16; 
	z80.interface->registers.HLPLUS = z80.regs[HLPLUS].REG16;
	z80.interface->registers.IX = z80.regs[IX].REG16;
	z80.interface->registers.IY = z80.regs[IY].REG16; 
	z80.interface->registers.SP = z80.regs[SP].REG16;
	z80.interface->registers.PC = z80.regs[PC].REG16; 
	
}

//----------------------------------------------------------------------
// change value of internal registers
void z80_init_reg_a(const uint8_t v) { z80.regs[AF].H = v; }
void z80_init_reg_b(const uint8_t v) { z80.regs[BC].H = v; }
void z80_init_reg_c(const uint8_t v) { z80.regs[BC].L = v; }
void z80_init_reg_d(const uint8_t v) { z80.regs[DE].H = v; }
void z80_init_reg_e(const uint8_t v) { z80.regs[DE].L = v; }
void z80_init_reg_h(const uint8_t v) { z80.regs[HL].H = v; }
void z80_init_reg_l(const uint8_t v) { z80.regs[HL].L = v; }
void z80_init_reg_f(const uint8_t v) { z80.regs[AF].L = v; }
void z80_init_reg_bc(const uint16_t v) { z80.regs[BC].REG16 = v; }
void z80_init_reg_de(const uint16_t v) { z80.regs[DE].REG16 = v; }
void z80_init_reg_hl(const uint16_t v) { z80.regs[HL].REG16 = v; }
void z80_init_reg_ix(const uint16_t v) { z80.regs[IX].REG16 = v; }
void z80_init_reg_iy(const uint16_t v) { z80.regs[IY].REG16 = v; }
void z80_init_reg_pc(const uint16_t v) { z80.regs[PC].REG16 = v; }


// NON API functions

//----------------------------------------------------------------------
//* Error handler.
void z80_error ( int e ) {

	z80.interface->error.number = e;
	z80.interface->error.pc		= z80.regs[PC].REG16;
	
}


//----------------------------------------------------------------------
void z80_reset () {
	z80.regs[PC].REG16 		= 0;
	z80.regs[IR].REG16 		= 0;
	z80.status.IFF1 		= 0;
	z80.status.IFF2 		= 0;
	z80.regs[AF].REG16 		= 0xFFFF;
	z80.regs[SP].REG16		= 0xFFFF;   
	z80.interface->signals.HALT  	= Z80_FALSE;
	z80.interface->signals.NMI  		= Z80_FALSE;
	z80.interface->signals.RST  		= Z80_FALSE;
	z80.interface->signals.INT  		= Z80_FALSE;
	z80.status.IMODE		= 0;
	z80.interface->totalts	= 0;			
	z80.interface->error.number	=	0;
}

//----------------------------------------------------------------------
// I honestly this should be improved
uint8_t z80_alu_check_parity( uint8_t input ) {
	
  input =  input ^ ( input >>  4 );
  input =  input ^ ( input >>  2 );  
  return ( input ^ ( input >>  1 ) ) & 0x1;
}
