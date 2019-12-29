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

#include "lxz80.h"
#include "z80-helper.h"

/**********************************************************************/
/* EXTERNALLY DEFINED VARIABLES										  */
extern t_z80 z80;


/**********************************************************************/
/* INTERNALLY DEFINED FUNCTIONS										  */
void z80_cb_decoding( );
/**********************************************************************/


void z80_cb_decoding (  ) {
	
	_Z80_FETCH_INST;
	
	switch (z80.status.REGINST) {
		
			
		case 0xC7:	ALU_SET(z80.regs[AF].H,0); _Z80_ITS(8,2,"SET 0,A"); break; 
		case 0xCF:	ALU_SET(z80.regs[AF].H,1); _Z80_ITS(8,2,"SET 1,A"); break; 
		case 0xD7:	ALU_SET(z80.regs[AF].H,2); _Z80_ITS(8,2,"SET 2,A"); break; 
		case 0xDF:	ALU_SET(z80.regs[AF].H,3); _Z80_ITS(8,2,"SET 3,A"); break;
		case 0xE7:	ALU_SET(z80.regs[AF].H,4); _Z80_ITS(8,2,"SET 4,A"); break; 
		case 0xEF:	ALU_SET(z80.regs[AF].H,5); _Z80_ITS(8,2,"SET 5,A"); break; 
		case 0xF7:	ALU_SET(z80.regs[AF].H,6); _Z80_ITS(8,2,"SET 6,A"); break; 
		case 0xFF:	ALU_SET(z80.regs[AF].H,7); _Z80_ITS(8,2,"SET 7,A"); break;
		
		case 0xC0:	ALU_SET(z80.regs[BC].H,0); _Z80_ITS(8,2,"SET 0,B"); break; 
		case 0xC8:	ALU_SET(z80.regs[BC].H,1); _Z80_ITS(8,2,"SET 1,B"); break; 
		case 0xD0:	ALU_SET(z80.regs[BC].H,2); _Z80_ITS(8,2,"SET 2,B"); break; 
		case 0xD8:	ALU_SET(z80.regs[BC].H,3); _Z80_ITS(8,2,"SET 3,B"); break;
		case 0xE0:	ALU_SET(z80.regs[BC].H,4); _Z80_ITS(8,2,"SET 4,B"); break; 
		case 0xE8:	ALU_SET(z80.regs[BC].H,5); _Z80_ITS(8,2,"SET 5,B"); break; 
		case 0xF0:	ALU_SET(z80.regs[BC].H,6); _Z80_ITS(8,2,"SET 6,B"); break; 
		case 0xF8:	ALU_SET(z80.regs[BC].H,7); _Z80_ITS(8,2,"SET 7,B"); break;
	
		case 0xC1:	ALU_SET(z80.regs[BC].L,0); _Z80_ITS(8,2,"SET 0,C"); break; 
		case 0xC9:	ALU_SET(z80.regs[BC].L,1); _Z80_ITS(8,2,"SET 1,C"); break; 
		case 0xD1:	ALU_SET(z80.regs[BC].L,2); _Z80_ITS(8,2,"SET 2,C"); break; 
		case 0xD9:	ALU_SET(z80.regs[BC].L,3); _Z80_ITS(8,2,"SET 3,C"); break;
		case 0xE1:	ALU_SET(z80.regs[BC].L,4); _Z80_ITS(8,2,"SET 4,C"); break; 
		case 0xE9:	ALU_SET(z80.regs[BC].L,5); _Z80_ITS(8,2,"SET 5,C"); break; 
		case 0xF1:	ALU_SET(z80.regs[BC].L,6); _Z80_ITS(8,2,"SET 6,C"); break; 
		case 0xF9:	ALU_SET(z80.regs[BC].L,7); _Z80_ITS(8,2,"SET 7,C"); break;
		
		case 0xC2:	ALU_SET(z80.regs[DE].H,0); _Z80_ITS(8,2,"SET 0,D"); break; 
		case 0xCA:	ALU_SET(z80.regs[DE].H,1); _Z80_ITS(8,2,"SET 1,D"); break; 
		case 0xD2:	ALU_SET(z80.regs[DE].H,2); _Z80_ITS(8,2,"SET 2,D"); break; 
		case 0xDA:	ALU_SET(z80.regs[DE].H,3); _Z80_ITS(8,2,"SET 3,D"); break;
		case 0xE2:	ALU_SET(z80.regs[DE].H,4); _Z80_ITS(8,2,"SET 4,D"); break; 
		case 0xEA:	ALU_SET(z80.regs[DE].H,5); _Z80_ITS(8,2,"SET 5,D"); break; 
		case 0xF2:	ALU_SET(z80.regs[DE].H,6); _Z80_ITS(8,2,"SET 6,D"); break; 
		case 0xFA:	ALU_SET(z80.regs[DE].H,7); _Z80_ITS(8,2,"SET 7,D"); break;
	
		case 0xC3:	ALU_SET(z80.regs[DE].L,0); _Z80_ITS(8,2,"SET 0,E"); break; 
		case 0xCB:	ALU_SET(z80.regs[DE].L,1); _Z80_ITS(8,2,"SET 1,E"); break; 
		case 0xD3:	ALU_SET(z80.regs[DE].L,2); _Z80_ITS(8,2,"SET 2,E"); break; 
		case 0xDB:	ALU_SET(z80.regs[DE].L,3); _Z80_ITS(8,2,"SET 3,E"); break;
		case 0xE3:	ALU_SET(z80.regs[DE].L,4); _Z80_ITS(8,2,"SET 4,E"); break; 
		case 0xEB:	ALU_SET(z80.regs[DE].L,5); _Z80_ITS(8,2,"SET 5,E"); break; 
		case 0xF3:	ALU_SET(z80.regs[DE].L,6); _Z80_ITS(8,2,"SET 6,E"); break; 
		case 0xFB:	ALU_SET(z80.regs[DE].L,7); _Z80_ITS(8,2,"SET 7,E"); break;
		
		case 0xC4:	ALU_SET(z80.regs[HL].H,0); _Z80_ITS(8,2,"SET 0,H"); break; 
		case 0xCC:	ALU_SET(z80.regs[HL].H,1); _Z80_ITS(8,2,"SET 1,H"); break; 
		case 0xD4:	ALU_SET(z80.regs[HL].H,2); _Z80_ITS(8,2,"SET 2,H"); break; 
		case 0xDC:	ALU_SET(z80.regs[HL].H,3); _Z80_ITS(8,2,"SET 3,H"); break;
		case 0xE4:	ALU_SET(z80.regs[HL].H,4); _Z80_ITS(8,2,"SET 4,H"); break; 
		case 0xEC:	ALU_SET(z80.regs[HL].H,5); _Z80_ITS(8,2,"SET 5,H"); break; 
		case 0xF4:	ALU_SET(z80.regs[HL].H,6); _Z80_ITS(8,2,"SET 6,H"); break; 
		case 0xFC:	ALU_SET(z80.regs[HL].H,7); _Z80_ITS(8,2,"SET 7,H"); break;
	
		case 0xC5:	ALU_SET(z80.regs[HL].L,0); _Z80_ITS(8,2,"SET 0,L"); break; 
		case 0xCD:	ALU_SET(z80.regs[HL].L,1); _Z80_ITS(8,2,"SET 1,L"); break; 
		case 0xD5:	ALU_SET(z80.regs[HL].L,2); _Z80_ITS(8,2,"SET 2,L"); break; 
		case 0xDD:	ALU_SET(z80.regs[HL].L,3); _Z80_ITS(8,2,"SET 3,L"); break;
		case 0xE5:	ALU_SET(z80.regs[HL].L,4); _Z80_ITS(8,2,"SET 4,L"); break; 
		case 0xED:	ALU_SET(z80.regs[HL].L,5); _Z80_ITS(8,2,"SET 5,L"); break; 
		case 0xF5:	ALU_SET(z80.regs[HL].L,6); _Z80_ITS(8,2,"SET 6,L"); break; 
		case 0xFD:	ALU_SET(z80.regs[HL].L,7); _Z80_ITS(8,2,"SET 7,L"); break;
		
		case 0xC6:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SET(z80.regs[WZ].L,0); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SET 0,(HL)"); break; 
		case 0xCE:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SET(z80.regs[WZ].L,1); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SET 1,(HL)"); break;
		case 0xD6:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SET(z80.regs[WZ].L,2); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SET 2,(HL)"); break; 
		case 0xDE:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SET(z80.regs[WZ].L,3); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SET 3,(HL)"); break;
		case 0xE6:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SET(z80.regs[WZ].L,4); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SET 4,(HL)"); break; 
		case 0xEE:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SET(z80.regs[WZ].L,5); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SET 5,(HL)"); break;
		case 0xF6:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SET(z80.regs[WZ].L,6); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SET 6,(HL)"); break; 
		case 0xFE:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SET(z80.regs[WZ].L,7); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SET 7,(HL)"); break;

		
		/*************************/
		
		case 0x47:	ALU_BIT(z80.regs[AF].H,0); _Z80_ITS(8,2,"BIT 0,A"); break; 
		case 0x4F:	ALU_BIT(z80.regs[AF].H,1); _Z80_ITS(8,2,"BIT 1,A"); break; 
		case 0x57:	ALU_BIT(z80.regs[AF].H,2); _Z80_ITS(8,2,"BIT 2,A"); break; 
		case 0x5F:	ALU_BIT(z80.regs[AF].H,3); _Z80_ITS(8,2,"BIT 3,A"); break;
		case 0x67:	ALU_BIT(z80.regs[AF].H,4); _Z80_ITS(8,2,"BIT 4,A"); break; 
		case 0x6F:	ALU_BIT(z80.regs[AF].H,5); _Z80_ITS(8,2,"BIT 5,A"); break; 
		case 0x77:	ALU_BIT(z80.regs[AF].H,6); _Z80_ITS(8,2,"BIT 6,A"); break; 
		case 0x7F:	ALU_BIT(z80.regs[AF].H,7); _Z80_ITS(8,2,"BIT 7,A"); break;
		
		case 0x40:	ALU_BIT(z80.regs[BC].H,0); _Z80_ITS(8,2,"BIT 0,B"); break; 
		case 0x48:	ALU_BIT(z80.regs[BC].H,1); _Z80_ITS(8,2,"BIT 1,B"); break; 
		case 0x50:	ALU_BIT(z80.regs[BC].H,2); _Z80_ITS(8,2,"BIT 2,B"); break; 
		case 0x58:	ALU_BIT(z80.regs[BC].H,3); _Z80_ITS(8,2,"BIT 3,B"); break;
		case 0x60:	ALU_BIT(z80.regs[BC].H,4); _Z80_ITS(8,2,"BIT 4,B"); break; 
		case 0x68:	ALU_BIT(z80.regs[BC].H,5); _Z80_ITS(8,2,"BIT 5,B"); break; 
		case 0x70:	ALU_BIT(z80.regs[BC].H,6); _Z80_ITS(8,2,"BIT 6,B"); break; 
		case 0x78:	ALU_BIT(z80.regs[BC].H,7); _Z80_ITS(8,2,"BIT 7,B"); break;
	
		case 0x41:	ALU_BIT(z80.regs[BC].L,0); _Z80_ITS(8,2,"BIT 0,C"); break; 
		case 0x49:	ALU_BIT(z80.regs[BC].L,1); _Z80_ITS(8,2,"BIT 1,C"); break; 
		case 0x51:	ALU_BIT(z80.regs[BC].L,2); _Z80_ITS(8,2,"BIT 2,C"); break; 
		case 0x59:	ALU_BIT(z80.regs[BC].L,3); _Z80_ITS(8,2,"BIT 3,C"); break;
		case 0x61:	ALU_BIT(z80.regs[BC].L,4); _Z80_ITS(8,2,"BIT 4,C"); break; 
		case 0x69:	ALU_BIT(z80.regs[BC].L,5); _Z80_ITS(8,2,"BIT 5,C"); break; 
		case 0x71:	ALU_BIT(z80.regs[BC].L,6); _Z80_ITS(8,2,"BIT 6,C"); break; 
		case 0x79:	ALU_BIT(z80.regs[BC].L,7); _Z80_ITS(8,2,"BIT 7,C"); break;
		
		case 0x42:	ALU_BIT(z80.regs[DE].H,0); _Z80_ITS(8,2,"BIT 0,D"); break; 
		case 0x4A:	ALU_BIT(z80.regs[DE].H,1); _Z80_ITS(8,2,"BIT 1,D"); break; 
		case 0x52:	ALU_BIT(z80.regs[DE].H,2); _Z80_ITS(8,2,"BIT 2,D"); break; 
		case 0x5A:	ALU_BIT(z80.regs[DE].H,3); _Z80_ITS(8,2,"BIT 3,D"); break;
		case 0x62:	ALU_BIT(z80.regs[DE].H,4); _Z80_ITS(8,2,"BIT 4,D"); break; 
		case 0x6A:	ALU_BIT(z80.regs[DE].H,5); _Z80_ITS(8,2,"BIT 5,D"); break; 
		case 0x72:	ALU_BIT(z80.regs[DE].H,6); _Z80_ITS(8,2,"BIT 6,D"); break; 
		case 0x7A:	ALU_BIT(z80.regs[DE].H,7); _Z80_ITS(8,2,"BIT 7,D"); break;
	
		case 0x43:	ALU_BIT(z80.regs[DE].L,0); _Z80_ITS(8,2,"BIT 0,E"); break; 
		case 0x4B:	ALU_BIT(z80.regs[DE].L,1); _Z80_ITS(8,2,"BIT 1,E"); break; 
		case 0x53:	ALU_BIT(z80.regs[DE].L,2); _Z80_ITS(8,2,"BIT 2,E"); break; 
		case 0x5B:	ALU_BIT(z80.regs[DE].L,3); _Z80_ITS(8,2,"BIT 3,E"); break;
		case 0x63:	ALU_BIT(z80.regs[DE].L,4); _Z80_ITS(8,2,"BIT 4,E"); break; 
		case 0x6B:	ALU_BIT(z80.regs[DE].L,5); _Z80_ITS(8,2,"BIT 5,E"); break; 
		case 0x73:	ALU_BIT(z80.regs[DE].L,6); _Z80_ITS(8,2,"BIT 6,E"); break; 
		case 0x7B:	ALU_BIT(z80.regs[DE].L,7); _Z80_ITS(8,2,"BIT 7,E"); break;
		
		case 0x44:	ALU_BIT(z80.regs[HL].H,0); _Z80_ITS(8,2,"BIT 0,H"); break; 
		case 0x4C:	ALU_BIT(z80.regs[HL].H,1); _Z80_ITS(8,2,"BIT 1,H"); break; 
		case 0x54:	ALU_BIT(z80.regs[HL].H,2); _Z80_ITS(8,2,"BIT 2,H"); break; 
		case 0x5C:	ALU_BIT(z80.regs[HL].H,3); _Z80_ITS(8,2,"BIT 3,H"); break;
		case 0x64:	ALU_BIT(z80.regs[HL].H,4); _Z80_ITS(8,2,"BIT 4,H"); break; 
		case 0x6C:	ALU_BIT(z80.regs[HL].H,5); _Z80_ITS(8,2,"BIT 5,H"); break; 
		case 0x74:	ALU_BIT(z80.regs[HL].H,6); _Z80_ITS(8,2,"BIT 6,H"); break; 
		case 0x7C:	ALU_BIT(z80.regs[HL].H,7); _Z80_ITS(8,2,"BIT 7,H"); break;
	
		case 0x45:	ALU_BIT(z80.regs[HL].L,0); _Z80_ITS(8,2,"BIT 0,L"); break; 
		case 0x4D:	ALU_BIT(z80.regs[HL].L,1); _Z80_ITS(8,2,"BIT 1,L"); break; 
		case 0x55:	ALU_BIT(z80.regs[HL].L,2); _Z80_ITS(8,2,"BIT 2,L"); break; 
		case 0x5D:	ALU_BIT(z80.regs[HL].L,3); _Z80_ITS(8,2,"BIT 3,L"); break;
		case 0x65:	ALU_BIT(z80.regs[HL].L,4); _Z80_ITS(8,2,"BIT 4,L"); break; 
		case 0x6D:	ALU_BIT(z80.regs[HL].L,5); _Z80_ITS(8,2,"BIT 5,L"); break; 
		case 0x75:	ALU_BIT(z80.regs[HL].L,6); _Z80_ITS(8,2,"BIT 6,L"); break; 
		case 0x7D:	ALU_BIT(z80.regs[HL].L,7); _Z80_ITS(8,2,"BIT 7,L"); break;
		
		case 0x46:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_BIT(z80.regs[WZ].L,0); _Z80_ITS(12,2,"BIT 0,(HL)"); break; 
		case 0x4E:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_BIT(z80.regs[WZ].L,1); _Z80_ITS(12,2,"BIT 1,(HL)"); break;
		case 0x56:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_BIT(z80.regs[WZ].L,2); _Z80_ITS(12,2,"BIT 2,(HL)"); break; 
		case 0x5E:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_BIT(z80.regs[WZ].L,3); _Z80_ITS(12,2,"BIT 3,(HL)"); break;
		case 0x66:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_BIT(z80.regs[WZ].L,4); _Z80_ITS(12,2,"BIT 4,(HL)"); break; 
		case 0x6E:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_BIT(z80.regs[WZ].L,5); _Z80_ITS(12,2,"BIT 5,(HL)"); break;
		case 0x76:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_BIT(z80.regs[WZ].L,6); _Z80_ITS(12,2,"BIT 6,(HL)"); break; 
		case 0x7E:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_BIT(z80.regs[WZ].L,7); _Z80_ITS(12,2,"BIT 7,(HL)"); break;

					
		case 0x87:	ALU_RES(z80.regs[AF].H,0); _Z80_ITS(8,2,"RES 0,A"); break; 
		case 0x8F:	ALU_RES(z80.regs[AF].H,1); _Z80_ITS(8,2,"RES 1,A"); break; 
		case 0x97:	ALU_RES(z80.regs[AF].H,2); _Z80_ITS(8,2,"RES 2,A"); break; 
		case 0x9F:	ALU_RES(z80.regs[AF].H,3); _Z80_ITS(8,2,"RES 3,A"); break;
		case 0xA7:	ALU_RES(z80.regs[AF].H,4); _Z80_ITS(8,2,"RES 4,A"); break; 
		case 0xAF:	ALU_RES(z80.regs[AF].H,5); _Z80_ITS(8,2,"RES 5,A"); break; 
		case 0xB7:	ALU_RES(z80.regs[AF].H,6); _Z80_ITS(8,2,"RES 6,A"); break; 
		case 0xBF:	ALU_RES(z80.regs[AF].H,7); _Z80_ITS(8,2,"RES 7,A"); break;
		
		case 0x80:	ALU_RES(z80.regs[BC].H,0); _Z80_ITS(8,2,"RES 0,B"); break; 
		case 0x88:	ALU_RES(z80.regs[BC].H,1); _Z80_ITS(8,2,"RES 1,B"); break; 
		case 0x90:	ALU_RES(z80.regs[BC].H,2); _Z80_ITS(8,2,"RES 2,B"); break; 
		case 0x98:	ALU_RES(z80.regs[BC].H,3); _Z80_ITS(8,2,"RES 3,B"); break;
		case 0xA0:	ALU_RES(z80.regs[BC].H,4); _Z80_ITS(8,2,"RES 4,B"); break; 
		case 0xA8:	ALU_RES(z80.regs[BC].H,5); _Z80_ITS(8,2,"RES 5,B"); break; 
		case 0xB0:	ALU_RES(z80.regs[BC].H,6); _Z80_ITS(8,2,"RES 6,B"); break; 
		case 0xB8:	ALU_RES(z80.regs[BC].H,7); _Z80_ITS(8,2,"RES 7,B"); break;
		
		case 0x81:	ALU_RES(z80.regs[BC].L,0); _Z80_ITS(8,2,"RES 0,C"); break; 
		case 0x89:	ALU_RES(z80.regs[BC].L,1); _Z80_ITS(8,2,"RES 1,C"); break; 
		case 0x91:	ALU_RES(z80.regs[BC].L,2); _Z80_ITS(8,2,"RES 2,C"); break; 
		case 0x99:	ALU_RES(z80.regs[BC].L,3); _Z80_ITS(8,2,"RES 3,C"); break;
		case 0xA1:	ALU_RES(z80.regs[BC].L,4); _Z80_ITS(8,2,"RES 4,C"); break; 
		case 0xA9:	ALU_RES(z80.regs[BC].L,5); _Z80_ITS(8,2,"RES 5,C"); break; 
		case 0xB1:	ALU_RES(z80.regs[BC].L,6); _Z80_ITS(8,2,"RES 6,C"); break; 
		case 0xB9:	ALU_RES(z80.regs[BC].L,7); _Z80_ITS(8,2,"RES 7,C"); break;
		
		case 0x82:	ALU_RES(z80.regs[DE].H,0); _Z80_ITS(8,2,"RES 0,D"); break; 
		case 0x8A:	ALU_RES(z80.regs[DE].H,1); _Z80_ITS(8,2,"RES 1,D"); break; 
		case 0x92:	ALU_RES(z80.regs[DE].H,2); _Z80_ITS(8,2,"RES 2,D"); break; 
		case 0x9A:	ALU_RES(z80.regs[DE].H,3); _Z80_ITS(8,2,"RES 3,D"); break;
		case 0xA2:	ALU_RES(z80.regs[DE].H,4); _Z80_ITS(8,2,"RES 4,D"); break; 
		case 0xAA:	ALU_RES(z80.regs[DE].H,5); _Z80_ITS(8,2,"RES 5,D"); break; 
		case 0xB2:	ALU_RES(z80.regs[DE].H,6); _Z80_ITS(8,2,"RES 6,D"); break; 
		case 0xBA:	ALU_RES(z80.regs[DE].H,7); _Z80_ITS(8,2,"RES 7,D"); break;
		
		case 0x83:	ALU_RES(z80.regs[DE].L,0); _Z80_ITS(8,2,"RES 0,E"); break; 
		case 0x8B:	ALU_RES(z80.regs[DE].L,1); _Z80_ITS(8,2,"RES 1,E"); break; 
		case 0x93:	ALU_RES(z80.regs[DE].L,2); _Z80_ITS(8,2,"RES 2,E"); break; 
		case 0x9B:	ALU_RES(z80.regs[DE].L,3); _Z80_ITS(8,2,"RES 3,E"); break;
		case 0xA3:	ALU_RES(z80.regs[DE].L,4); _Z80_ITS(8,2,"RES 4,E"); break; 
		case 0xAB:	ALU_RES(z80.regs[DE].L,5); _Z80_ITS(8,2,"RES 5,E"); break; 
		case 0xB3:	ALU_RES(z80.regs[DE].L,6); _Z80_ITS(8,2,"RES 6,E"); break; 
		case 0xBB:	ALU_RES(z80.regs[DE].L,7); _Z80_ITS(8,2,"RES 7,E"); break;
		
		case 0x84:	ALU_RES(z80.regs[HL].H,0); _Z80_ITS(8,2,"RES 0,H"); break; 
		case 0x8C:	ALU_RES(z80.regs[HL].H,1); _Z80_ITS(8,2,"RES 1,H"); break; 
		case 0x94:	ALU_RES(z80.regs[HL].H,2); _Z80_ITS(8,2,"RES 2,H"); break; 
		case 0x9C:	ALU_RES(z80.regs[HL].H,3); _Z80_ITS(8,2,"RES 3,H"); break;
		case 0xA4:	ALU_RES(z80.regs[HL].H,4); _Z80_ITS(8,2,"RES 4,H"); break; 
		case 0xAC:	ALU_RES(z80.regs[HL].H,5); _Z80_ITS(8,2,"RES 5,H"); break; 
		case 0xB4:	ALU_RES(z80.regs[HL].H,6); _Z80_ITS(8,2,"RES 6,H"); break; 
		case 0xBC:	ALU_RES(z80.regs[HL].H,7); _Z80_ITS(8,2,"RES 7,H"); break;
		
		case 0x85:	ALU_RES(z80.regs[HL].L,0); _Z80_ITS(8,2,"RES 0,L"); break; 
		case 0x8D:	ALU_RES(z80.regs[HL].L,1); _Z80_ITS(8,2,"RES 1,L"); break; 
		case 0x95:	ALU_RES(z80.regs[HL].L,2); _Z80_ITS(8,2,"RES 2,L"); break; 
		case 0x9D:	ALU_RES(z80.regs[HL].L,3); _Z80_ITS(8,2,"RES 3,L"); break;
		case 0xA5:	ALU_RES(z80.regs[HL].L,4); _Z80_ITS(8,2,"RES 4,L"); break; 
		case 0xAD:	ALU_RES(z80.regs[HL].L,5); _Z80_ITS(8,2,"RES 5,L"); break; 
		case 0xB5:	ALU_RES(z80.regs[HL].L,6); _Z80_ITS(8,2,"RES 6,L"); break; 
		case 0xBD:	ALU_RES(z80.regs[HL].L,7); _Z80_ITS(8,2,"RES 7,L"); break;
							
		case 0x86:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RES(z80.regs[WZ].L,0); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RES 0,(HL)"); break; 
		case 0x8E:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RES(z80.regs[WZ].L,1); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RES 1,(HL)"); break;
		case 0x96:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RES(z80.regs[WZ].L,2); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RES 2,(HL)"); break; 
		case 0x9E:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RES(z80.regs[WZ].L,3); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RES 3,(HL)"); break;
		case 0xA6:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RES(z80.regs[WZ].L,4); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RES 4,(HL)"); break; 
		case 0xAE:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RES(z80.regs[WZ].L,5); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RES 5,(HL)"); break;
		case 0xB6:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RES(z80.regs[WZ].L,6); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RES 6,(HL)"); break; 
		case 0xBE:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RES(z80.regs[WZ].L,7); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RES 7,(HL)"); break;
		
		case 0x07:	ALU_RLC(z80.regs[AF].H); _Z80_ITS(8,2,"RLC A"); break;	
		case 0x00:	ALU_RLC(z80.regs[BC].H); _Z80_ITS(8,2,"RLC B"); break;	
		case 0x01:	ALU_RLC(z80.regs[BC].L); _Z80_ITS(8,2,"RLC C"); break;	
		case 0x02:	ALU_RLC(z80.regs[DE].H); _Z80_ITS(8,2,"RLC D"); break;	
		case 0x03:	ALU_RLC(z80.regs[DE].L); _Z80_ITS(8,2,"RLC E"); break;	
		case 0x04:	ALU_RLC(z80.regs[HL].H); _Z80_ITS(8,2,"RLC H"); break;	
		case 0x05:	ALU_RLC(z80.regs[HL].L); _Z80_ITS(8,2,"RLC L"); break;	
		case 0x06:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RLC(z80.regs[WZ].L); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RLC (HL)"); break;	
		
		case 0x0F:	ALU_RRC(z80.regs[AF].H); _Z80_ITS(8,2,"RRC A"); break;	
		case 0x08:	ALU_RRC(z80.regs[BC].H); _Z80_ITS(8,2,"RRC B"); break;	
		case 0x09:	ALU_RRC(z80.regs[BC].L); _Z80_ITS(8,2,"RRC C"); break;	
		case 0x0A:	ALU_RRC(z80.regs[DE].H); _Z80_ITS(8,2,"RRC D"); break;	
		case 0x0B:	ALU_RRC(z80.regs[DE].L); _Z80_ITS(8,2,"RRC E"); break;	
		case 0x0C:	ALU_RRC(z80.regs[HL].H); _Z80_ITS(8,2,"RRC H"); break;	
		case 0x0D:	ALU_RRC(z80.regs[HL].L); _Z80_ITS(8,2,"RRC L"); break;	
		case 0x0E:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RRC(z80.regs[WZ].L); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RRC (HL)"); break;	
	
		case 0x17:	ALU_RL(z80.regs[AF].H); _Z80_ITS(8,2,"RL A"); break;	
		case 0x10:	ALU_RL(z80.regs[BC].H); _Z80_ITS(8,2,"RL B"); break;	
		case 0x11:	ALU_RL(z80.regs[BC].L); _Z80_ITS(8,2,"RL C"); break;	
		case 0x12:	ALU_RL(z80.regs[DE].H); _Z80_ITS(8,2,"RL D"); break;	
		case 0x13:	ALU_RL(z80.regs[DE].L); _Z80_ITS(8,2,"RL E"); break;	
		case 0x14:	ALU_RL(z80.regs[HL].H); _Z80_ITS(8,2,"RL H"); break;	
		case 0x15:	ALU_RL(z80.regs[HL].L); _Z80_ITS(8,2,"RL L"); break;	
		case 0x16:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RL(z80.regs[WZ].L); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RL (HL)"); break;	
		
		case 0x1F:	ALU_RR(z80.regs[AF].H); _Z80_ITS(8,2,"RR A"); break;	
		case 0x18:	ALU_RR(z80.regs[BC].H); _Z80_ITS(8,2,"RR B"); break;	
		case 0x19:	ALU_RR(z80.regs[BC].L); _Z80_ITS(8,2,"RR C"); break;	
		case 0x1A:	ALU_RR(z80.regs[DE].H); _Z80_ITS(8,2,"RR D"); break;	
		case 0x1B:	ALU_RR(z80.regs[DE].L); _Z80_ITS(8,2,"RR E"); break;	
		case 0x1C:	ALU_RR(z80.regs[HL].H); _Z80_ITS(8,2,"RR H"); break;	
		case 0x1D:	ALU_RR(z80.regs[HL].L); _Z80_ITS(8,2,"RR L"); break;	
		case 0x1E:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_RR(z80.regs[WZ].L); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"RR (HL)"); break;	
	
		
		case 0x27:	ALU_SLA(z80.regs[AF].H); _Z80_ITS(8,2,"SLA A"); break;	
		case 0x20:	ALU_SLA(z80.regs[BC].H); _Z80_ITS(8,2,"SLA B"); break;	
		case 0x21:	ALU_SLA(z80.regs[BC].L); _Z80_ITS(8,2,"SLA C"); break;	
		case 0x22:	ALU_SLA(z80.regs[DE].H); _Z80_ITS(8,2,"SLA D"); break;	
		case 0x23:	ALU_SLA(z80.regs[DE].L); _Z80_ITS(8,2,"SLA E"); break;	
		case 0x24:	ALU_SLA(z80.regs[HL].H); _Z80_ITS(8,2,"SLA H"); break;	
		case 0x25:	ALU_SLA(z80.regs[HL].L); _Z80_ITS(8,2,"SLA L"); break;	
		case 0x26:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SLA(z80.regs[WZ].L); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SLA (HL)"); break;	
		
		
		case 0x37:	ALU_SLL(z80.regs[AF].H); _Z80_ITS(8,2,"SLL A"); break;	
		case 0x30:	ALU_SLL(z80.regs[BC].H); _Z80_ITS(8,2,"SLL B"); break;	
		case 0x31:	ALU_SLL(z80.regs[BC].L); _Z80_ITS(8,2,"SLL C"); break;	
		case 0x32:	ALU_SLL(z80.regs[DE].H); _Z80_ITS(8,2,"SLL D"); break;	
		case 0x33:	ALU_SLL(z80.regs[DE].L); _Z80_ITS(8,2,"SLL E"); break;	
		case 0x34:	ALU_SLL(z80.regs[HL].H); _Z80_ITS(8,2,"SLL H"); break;	
		case 0x35:	ALU_SLL(z80.regs[HL].L); _Z80_ITS(8,2,"SLL L"); break;	
		case 0x36:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SLL(z80.regs[WZ].L); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SLL (HL)"); break;	
		
		
		
		case 0x2F:	ALU_SRA(z80.regs[AF].H); _Z80_ITS(8,2,"SRA A"); break;	
		case 0x28:	ALU_SRA(z80.regs[BC].H); _Z80_ITS(8,2,"SRA B"); break;	
		case 0x29:	ALU_SRA(z80.regs[BC].L); _Z80_ITS(8,2,"SRA C"); break;	
		case 0x2A:	ALU_SRA(z80.regs[DE].H); _Z80_ITS(8,2,"SRA D"); break;	
		case 0x2B:	ALU_SRA(z80.regs[DE].L); _Z80_ITS(8,2,"SRA E"); break;	
		case 0x2C:	ALU_SRA(z80.regs[HL].H); _Z80_ITS(8,2,"SRA H"); break;	
		case 0x2D:	ALU_SRA(z80.regs[HL].L); _Z80_ITS(8,2,"SRA L"); break;	
		case 0x2E:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SRA(z80.regs[WZ].L); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SRA (HL)"); break;	
		
		
		case 0x3F:	ALU_SRL(z80.regs[AF].H); _Z80_ITS(8,2,"SRL A"); break;	
		case 0x38:	ALU_SRL(z80.regs[BC].H); _Z80_ITS(8,2,"SRL B"); break;	
		case 0x39:	ALU_SRL(z80.regs[BC].L); _Z80_ITS(8,2,"SRL C"); break;	
		case 0x3A:	ALU_SRL(z80.regs[DE].H); _Z80_ITS(8,2,"SRL D"); break;	
		case 0x3B:	ALU_SRL(z80.regs[DE].L); _Z80_ITS(8,2,"SRL E"); break;	
		case 0x3C:	ALU_SRL(z80.regs[HL].H); _Z80_ITS(8,2,"SRL H"); break;	
		case 0x3D:	ALU_SRL(z80.regs[HL].L); _Z80_ITS(8,2,"SRL L"); break;	
		case 0x3E:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SRL(z80.regs[WZ].L); _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); _Z80_ITS(15,2,"SRL (HL)"); break;	
		
	
		
		default: z80_error(ERROR_UNKNOWN_OPCODE); break;
	}

}
