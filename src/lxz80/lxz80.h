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

#ifndef _LXZ80_H
#define _LXZ80_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LXZ80_VERSION "0.0.8"


struct z80interface {
	float clock; /* in Mhz, typically 1, 2, 3, 4 */
	void (*io)(struct z80interface *);
	int type;		/* 0: read ram, 1: write ram, 2: read io, 3: write io */
    uint16_t busaddr;
    uint8_t  busdata;
};


/**********************************************************************/
/* API FUNCTIONS													  */
void z80_init( struct z80interface * interface );		
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
