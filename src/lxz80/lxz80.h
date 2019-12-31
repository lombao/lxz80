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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* The possible type of errors */	
typedef enum { 
		ERROR_UNKNOWN_OPCODE,  	/* Opcode has not been recognized */
		IM2_MISSING_VECTOR		/* Vector not provided when INT in IM2 called */
	} t_z80_errors;
	

typedef enum { 
		Z80_TRUE,
		Z80_FALSE
	} t_z80_bool;
	
/* interruption modes */
typedef enum {
	Z80_IM0,
	Z80_IM1,
	Z80_IM2
    } t_interrupt_mode;


/* this is the index with the z80.regs that identify each of of them */	
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



/* type for the I/O functions */
typedef	void( *t_callback_readio)(	const uint16_t addr, uint8_t * data );
typedef	void( *t_callback_writeio)( const uint16_t addr );


/* type for the RAM functions */
typedef	void( *t_callback_readram)(	const uint16_t addr, uint8_t * data );
typedef	void( *t_callback_writeram)( const uint16_t addr, const uint8_t * data );


//----------------------------------------------------------------------
//  THE z80 STRUCTURE
// This represents the CPU , with its registers and status 
typedef struct {

	float clock;	/* in Mhz, typically between 2 and 4 */

	
	/* the registers */
	#define Z80_NUM_REGS 15
	#define Z80_MAX_NAME 10
	char nameregs[Z80_NUM_REGS][Z80_MAX_NAME];   
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
	#define MAX_ASM_LINE 80
	struct {
		t_z80_bool			HALT;		/* Signal Halt */
		t_z80_bool			RST;		/* Signal Halt */
		t_z80_bool			INT;		/* Signal Halt */
		t_z80_bool			NMI;		/* Signal Halt */
		
		uint8_t  			IFF1;
		uint8_t  			IFF2;		
		
		t_interrupt_mode	IMODE;		/* interrupt mode ONLY IMPLEMENTED MODE 1*/
			
		uint8_t  			REGINST; 	/* do not confuse with IR register */
		
		int ts;							/* number of tstates of the last instruction */
		uint64_t totalts;				/* the total of tstates since the start */
		
	} status;
	
	/* callbacks for I/O an RAM access */
	t_callback_readio read_io;
	t_callback_writeio write_io;
	t_callback_readram read_ram;
	t_callback_writeram write_ram;
	
	
	
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
/* API FUNCTIONS													  */
void z80_init( const int clock, 
		t_callback_readio read_io ,
		t_callback_writeio write_io ,
		t_callback_readram read_ram ,
		t_callback_writeram write_ram  );
		
int z80_run ();

void z80_signal_rst(); 	
void z80_signal_halt(); 
void z80_signal_int(); 	
void z80_signal_nmi(); 	

uint16_t z80_show_af();
uint16_t z80_show_bc();
uint16_t z80_show_de();
uint16_t z80_show_hl();
uint16_t z80_show_ix();
uint16_t z80_show_iy();

void z80_write_reg_a(uint8_t v);
void z80_write_reg_b(uint8_t v);
void z80_write_reg_c(uint8_t v);
void z80_write_reg_d(uint8_t v);
void z80_write_reg_e(uint8_t v);
void z80_write_reg_h(uint8_t v);
void z80_write_reg_l(uint8_t v);

uint64_t z80_show_totalts();

/**********************************************************************/



#endif
