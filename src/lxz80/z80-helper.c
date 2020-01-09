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

#include "z80-helper.h"


/**********************************************************************/
/* EXTERNALLY DEFINED VARIABLES										  */
extern t_z80 z80;



void z80_error ( t_z80_errors e ) {

	printf("ERROR ERROR: %d\n",e);
	
}


uint8_t z80_alu_check_parity( uint8_t input ) {
	
  input =  input ^ ( input >>  4 );
  input =  input ^ ( input >>  2 );  
  return ( input ^ ( input >>  1 ) ) & 0x1;
}
