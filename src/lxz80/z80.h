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

#ifndef _Z80_H
#define _Z80_H

#include "lxz80.h"
	
/* This is the index with the z80.regs 
 * that identify each of of them */	
typedef enum registers {
		AF,
		AFPLUS,
		BC,
		DE,
		HL,
		BCPLUS,
		DEPLUS,
		HLPLUS,
		IX,
		IY,
		SP,
		WZ,
		PC,
		IR
} t_registers_idx;


//----------------------------------------------------------------------
//  THE z80 STRUCTURE
// This represents the CPU , with its registers and status 

/* the registers */
#define Z80_NUM_REGS 15

typedef struct {
	
	/* the internal registers */
	union {
		uint16_t REG16;
		struct {			  	
			union {
				uint8_t L;
				struct  {
					uint8_t CFLAG: 1;
					uint8_t NFLAG: 1;
					uint8_t PFLAG: 1;
					uint8_t XFLAG: 1;
					uint8_t HFLAG: 1;
					uint8_t YFLAG: 1;
					uint8_t ZFLAG: 1;
					uint8_t SFLAG: 1; 
				};
			};
			uint8_t H;
		};
	} regs[Z80_NUM_REGS]; 
	
    /* the status */
	struct {
		
		uint8_t  			IFF1;
		uint8_t  			IFF2;		
		
		uint8_t				IMODE;		/* 0,1,2---> ONLY IMPLEMENTED MODE 1*/			
		uint8_t  			REGINST; 	/* do not confuse with IR register */
		
		int ts;							/* number of tstates of the last instruction */
		
	} status;
	
	struct z80interface * interface;
	
	
} t_z80;


/**********************************************************************/

/* shortcuts for Flags names */
#define HX z80.regs[AF].HFLAG
#define NX z80.regs[AF].NFLAG
#define PX z80.regs[AF].PFLAG
#define CX z80.regs[AF].CFLAG
#define ZX z80.regs[AF].ZFLAG
#define SX z80.regs[AF].SFLAG
#define YX z80.regs[AF].YFLAG
#define XX z80.regs[AF].XFLAG


/**********************************************************************/
/* Internal functions												  */

void z80_reset ();
void z80_error ( int e );
uint8_t z80_alu_check_parity( uint8_t input );
/**********************************************************************/



#endif
