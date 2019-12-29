/* Copyright (c) 2019 Cesar Lombao
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
void z80_ddfd_decoding( int type );
void z80_ddfd_cb_decoding ( int type );
/**********************************************************************/


void z80_ddfd_decoding ( int type ) {
	
	_Z80_FETCH_INST;	
	
	/* NOTE SOME OF THESE SHOULD NOT CHANGE THE CARRY FLAG BUT THE CALL TO ALU CHANGES IT */
	
	switch ((uint8_t)z80.status.REGINST) {
		
		case 0x00:	_Z80_ITS(7,2,"NOP"); break;

		case 0x8E:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_ADC(z80.regs[WZ].H);
					_Z80_ITS_2(19,3,"ADC A,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); 
					break; 
								
		case 0x9E:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_SBC_HL(z80.regs[WZ].L);
					_Z80_ITS_2(19,3,"SBC A,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L);  
					break; 
					
		case 0x86:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_ADD(z80.regs[WZ].H);
					_Z80_ITS_2(19,3,"ADD A,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); 
					break; 
					
		case 0x96:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_SUB(z80.regs[WZ].H);
					_Z80_ITS_2(19,3,"SUB A,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); 
					break; 

		case 0x35:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_DEC(z80.regs[WZ].H);
					_Z80_WRITE_BYTE( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H );
					_Z80_ITS_2(19,3,"DEC (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); 
					break;
					 
		case 0x2B:	z80.regs[type].REG16--; 
					_Z80_ITS_1(10,2,"DEC %s",z80.nameregs[type]); 
					break;
					
					
		case 0x34:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_INC(z80.regs[WZ].H);
					_Z80_WRITE_BYTE( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H );
					_Z80_ITS_2(23,3,"INC (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); 
					break;
					 
		case 0x23:	z80.regs[type].REG16++; 
					_Z80_ITS_1(10,3," INC %s",z80.nameregs[type]); 
					break;
					
		case 0xA6:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_AND(z80.regs[WZ].H); 
					_Z80_ITS_2(19,3,"AND A,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); 
					break; 
		
		case 0xB6:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_OR(z80.regs[WZ].H);
					_Z80_ITS_2(19,3,"OR A,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); 
					break; 
		
					
		case 0xAE:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_XOR(z80.regs[WZ].H);
					_Z80_ITS_2(19,3,"XOR A,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); 
					break; 

		case 0xBE:	_Z80_FETCH_BYTE; _Z80_READ_RAM ( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[WZ].H);
					ALU_CP(z80.regs[WZ].H);
					_Z80_ITS_2(19,3,"CP A,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); 
					break; 
	
		case 0xE3: 	z80.regs[WZ].REG16 = z80.regs[type].REG16; 
					_Z80_READ_REG16( z80.regs[SP].REG16, type );
					_Z80_WRITE_REG16 ( z80.regs[SP].REG16, WZ );
					_Z80_ITS_1(23,2,"EX (SP),%s",z80.nameregs[type]); 
					break; 
									
		case 0xCB:  z80_ddfd_cb_decoding( type ); break;
		
		case 0x09:  ALU_ADD_16(z80.regs[type].REG16,z80.regs[BC].REG16); _Z80_ITS_1(15,2,"ADD %s,BC",z80.nameregs[type]); break;
		case 0x19:  ALU_ADD_16(z80.regs[type].REG16,z80.regs[DE].REG16); _Z80_ITS_1(15,2,"ADD %s,DE",z80.nameregs[type]); break;
		case 0x29:  ALU_ADD_16(z80.regs[type].REG16,z80.regs[type].REG16); _Z80_ITS_2(15,2,"ADD %s,%s",z80.nameregs[type],z80.nameregs[type]); break;
		case 0x39:  ALU_ADD_16(z80.regs[type].REG16,z80.regs[SP].REG16); _Z80_ITS_1(15,2,"ADD %s,SP",z80.nameregs[type]); break;
				
		case 0xE9:	z80.regs[PC].REG16 = z80.regs[type].REG16; 
					_Z80_ITS_1(8,2,"JP (%s)",z80.nameregs[type]); 
					break;  
						
		case 0x7E:	_Z80_FETCH_BYTE; _Z80_READ_RAM( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[AF].H); _Z80_ITS_2(19,3,"LD A,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x46:	_Z80_FETCH_BYTE; _Z80_READ_RAM( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[BC].H); _Z80_ITS_2(19,3,"LD B,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x4E:	_Z80_FETCH_BYTE; _Z80_READ_RAM( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[BC].L); _Z80_ITS_2(19,3,"LD C,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x56:	_Z80_FETCH_BYTE; _Z80_READ_RAM( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[DE].H); _Z80_ITS_2(19,3,"LD D,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x5E:	_Z80_FETCH_BYTE; _Z80_READ_RAM( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[DE].L); _Z80_ITS_2(19,2,"LD E,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x66:	_Z80_FETCH_BYTE; _Z80_READ_RAM( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[HL].H); _Z80_ITS_2(19,2,"LD H,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x6E:	_Z80_FETCH_BYTE; _Z80_READ_RAM( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[HL].L); _Z80_ITS_2(19,2,"LD L,(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		
		case 0x36:	_Z80_FETCH_WORD; _Z80_WRITE_BYTE ( ( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ), z80.regs[WZ].H ); _Z80_ITS_3(19,4,"LD (%s+%02Xh),%02Xh",z80.nameregs[type],z80.regs[WZ].L,z80.regs[WZ].H); break; 
		
		case 0x77:	_Z80_FETCH_BYTE; _Z80_WRITE_BYTE( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[AF].H); _Z80_ITS_2(19,3,"LD (%s+%02Xh),A",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x70:	_Z80_FETCH_BYTE; _Z80_WRITE_BYTE( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[AF].H); _Z80_ITS_2(19,3,"LD (%s+%02Xh),B",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x71:	_Z80_FETCH_BYTE; _Z80_WRITE_BYTE( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[AF].H); _Z80_ITS_2(19,3,"LD (%s+%02Xh),C",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x72:	_Z80_FETCH_BYTE; _Z80_WRITE_BYTE( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[AF].H); _Z80_ITS_2(19,3,"LD (%s+%02Xh),D",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x73:	_Z80_FETCH_BYTE; _Z80_WRITE_BYTE( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[AF].H); _Z80_ITS_2(19,3,"LD (%s+%02Xh),E",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x74:	_Z80_FETCH_BYTE; _Z80_WRITE_BYTE( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[AF].H); _Z80_ITS_2(19,3,"LD (%s+%02Xh),H",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x75:	_Z80_FETCH_BYTE; _Z80_WRITE_BYTE( (z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L), z80.regs[AF].H); _Z80_ITS_2(19,3,"LD (%s+%02Xh),L",z80.nameregs[type],z80.regs[WZ].L); break;

		case 0x22: 	_Z80_FETCH_WORD; _Z80_WRITE_REG16( z80.regs[WZ].REG16, type ); _Z80_ITS_2(20,4,"LD (%04Xh),%s",z80.regs[WZ].REG16,z80.nameregs[type]); break;			
		case 0x21: 	_Z80_FETCH_WORD; z80.regs[type].REG16 = z80.regs[WZ].REG16; _Z80_ITS_2(14,4,"LD %s,%04Xh",z80.nameregs[type],z80.regs[WZ].REG16); break;			
		case 0x2A:	_Z80_FETCH_WORD; _Z80_READ_REG16( z80.regs[WZ].REG16, type ); _Z80_ITS_2(20,4,"LD %s,(%04Xh)",z80.nameregs[type],z80.regs[WZ].REG16);  break;
		
		case 0xF9:	z80.regs[SP].REG16 = z80.regs[type].REG16; _Z80_ITS_1(10,2,"LD SP,%s",z80.nameregs[type]); break;
		
		case 0xE1:	_Z80_POP_REG16(type); _Z80_ITS_1(15,2,"POP %s",z80.nameregs[type]);  break;
		case 0xE5:	_Z80_PUSH_REG16(type); _Z80_ITS_1(15,2,"PUSH %s",z80.nameregs[type]); break;

	
		
		default: z80_error(ERROR_UNKNOWN_OPCODE); break;
	}

}


void z80_ddfd_cb_decoding ( int type ) {
	
	_Z80_FETCH_BYTE; 
	_Z80_FETCH_INST;
	
	switch ( (uint8_t)z80.status.REGINST ) {
		
		case 0x46: 	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_BIT(z80.regs[WZ].H,0); _Z80_ITS_2(20,4,"BIT 0.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x4E:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_BIT(z80.regs[WZ].H,1); _Z80_ITS_2(20,4,"BIT 1.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x56: 	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_BIT(z80.regs[WZ].H,2); _Z80_ITS_2(20,4,"BIT 2.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x5E: 	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_BIT(z80.regs[WZ].H,3); _Z80_ITS_2(20,4,"BIT 3.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x66: 	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_BIT(z80.regs[WZ].H,4); _Z80_ITS_2(20,4,"BIT 4.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x6E: 	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_BIT(z80.regs[WZ].H,5); _Z80_ITS_2(20,4,"BIT 5.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x76: 	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_BIT(z80.regs[WZ].H,6); _Z80_ITS_2(20,4,"BIT 6.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0x7E: 	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_BIT(z80.regs[WZ].H,7); _Z80_ITS_2(20,4,"BIT 7.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		
		case 0x86:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RES(z80.regs[WZ].H,0); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RES 0.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0x8E:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RES(z80.regs[WZ].H,1); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RES 1.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0x96:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RES(z80.regs[WZ].H,2); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RES 2.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0x9E:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RES(z80.regs[WZ].H,3); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RES 3.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0xA6:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RES(z80.regs[WZ].H,4); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RES 4.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0xAE:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RES(z80.regs[WZ].H,5); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RES 5.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0xB6:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RES(z80.regs[WZ].H,6); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RES 6.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0xBE:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RES(z80.regs[WZ].H,7); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RES 7.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		
		
		case 0xC6:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SET(z80.regs[WZ].H,0); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SET 0.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L);  break; 
		case 0xCE:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SET(z80.regs[WZ].H,1); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SET 1.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0xD6:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SET(z80.regs[WZ].H,2); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SET 2.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0xDE:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SET(z80.regs[WZ].H,3); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SET 3.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
		case 0xE6:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SET(z80.regs[WZ].H,4); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SET 4.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0xEE:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SET(z80.regs[WZ].H,5); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SET 5.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0xF6:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SET(z80.regs[WZ].H,6); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SET 6.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break; 
		case 0xFE:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SET(z80.regs[WZ].H,7); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SET 7.(%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
	
		case 0x06:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RLC(z80.regs[WZ].H); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RLC (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;	
		case 0x0E:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RRC(z80.regs[WZ].H); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RRC (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
	
	
		case 0x26:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SLA(z80.regs[WZ].H); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SLA (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;	
		case 0x2E:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SRA(z80.regs[WZ].H); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SRA (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;	
		case 0x3E:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SRL(z80.regs[WZ].H); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SRL (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;	
		case 0x36:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_SLL(z80.regs[WZ].H); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"SLL (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;	

	
		case 0x16:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RL(z80.regs[WZ].H); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RL (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;	
		case 0x1E:	_Z80_READ_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L ,z80.regs[WZ].H); ALU_RR(z80.regs[WZ].H); _Z80_WRITE_BYTE( z80.regs[type].REG16 + (int8_t)z80.regs[WZ].L , z80.regs[WZ].H ); _Z80_ITS_2(23,4,"RR (%s+%02Xh)",z80.nameregs[type],z80.regs[WZ].L); break;
	
		
		default: z80_error(ERROR_UNKNOWN_OPCODE); break;
	
	}
	
}
