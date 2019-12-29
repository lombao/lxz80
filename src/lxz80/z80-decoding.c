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


#include "lxz80.h"
#include "z80-helper.h"


/**********************************************************************/
/* EXTERNALLY DEFINED FUNCTIONS										  */

void z80_ddfd_decoding( int type );
void z80_ed_decoding();
void z80_cb_decoding();
/**********************************************************************/

/**********************************************************************/
/* EXTERNALLY DEFINED VARIABLES										  */
extern t_z80 z80;

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/
/* INTERNAL DEFINED FUNCTIONS										  */
void z80_alu_daa();
	

/**********************************************************************/
/**********************************************************************/



void z80_decoding() {
		
	switch ( z80.status.REGINST ) {

			case 0x76:	_Z80_ITS(4,1,"HALT"); z80.status.HALT = Z80_TRUE; break;
			case 0x00:	_Z80_ITS(4,1,"NOP"); break;

			case 0xED:	z80_ed_decoding(); 			break;
			case 0xDD:	z80_ddfd_decoding( IX ); 	break;
			case 0xFD:	z80_ddfd_decoding( IY ); 	break;
			case 0xCB:	z80_cb_decoding();			break;
			
			case 0x27:	z80_alu_daa();				break;
	
			case 0xDB:	_Z80_FETCH_BYTE; z80.read_io(((z80.regs[AF].H << 8) | z80.regs[WZ].L ),&z80.regs[AF].H); _Z80_ITS_1(11,2,"IN A,(%02Xh)",(uint8_t)z80.regs[WZ].L); break;
			case 0xD3:	_Z80_FETCH_BYTE; z80.write_io(((z80.regs[AF].H << 8) | z80.regs[WZ].L )); _Z80_ITS_1(11,2,"OUT (%02Xh),A",(uint8_t)z80.regs[WZ].L); break;
					
			case 0x01:	_Z80_FETCH_WORD_REG(z80.regs[BC]); _Z80_ITS_1(10,3,"LD BC, %04Xh",z80.regs[BC].REG16); break; 
			case 0x11:	_Z80_FETCH_WORD_REG(z80.regs[DE]); _Z80_ITS_1(10,3,"LD DE, %04Xh",z80.regs[DE].REG16); break; 
			case 0x21:	_Z80_FETCH_WORD_REG(z80.regs[HL]); _Z80_ITS_1(10,3,"LD HL, %04Xh",z80.regs[HL].REG16); break; 
			case 0x31:	_Z80_FETCH_WORD_REG(z80.regs[SP]); _Z80_ITS_1(10,3,"LD SP, %04Xh",z80.regs[SP].REG16); break; 

			case 0x3E:	_Z80_FETCH_BYTE; z80.regs[AF].H = z80.regs[WZ].L; _Z80_ITS_1(7,2,"LD A, %02Xh",z80.regs[WZ].L); break; 
			case 0x06:	_Z80_FETCH_BYTE; z80.regs[BC].H = z80.regs[WZ].L; _Z80_ITS_1(7,2,"LD B, %02Xh",z80.regs[WZ].L); break; 
			case 0x0E:	_Z80_FETCH_BYTE; z80.regs[BC].L = z80.regs[WZ].L; _Z80_ITS_1(7,2,"LD C, %02Xh",z80.regs[WZ].L); break; 
			case 0x16:	_Z80_FETCH_BYTE; z80.regs[DE].H = z80.regs[WZ].L; _Z80_ITS_1(7,2,"LD D, %02Xh",z80.regs[WZ].L); break; 
			case 0x1E:	_Z80_FETCH_BYTE; z80.regs[DE].L = z80.regs[WZ].L; _Z80_ITS_1(7,2,"LD E, %02Xh",z80.regs[WZ].L); break; 
			case 0x26:	_Z80_FETCH_BYTE; z80.regs[HL].H = z80.regs[WZ].L; _Z80_ITS_1(7,2,"LD H, %02Xh",z80.regs[WZ].L); break; 
			case 0x2E:	_Z80_FETCH_BYTE; z80.regs[HL].L = z80.regs[WZ].L; _Z80_ITS_1(7,2,"LD L, %02Xh",z80.regs[WZ].L); break; 

			case 0x7F:	_Z80_ITS(4,1,"LD A,A"); break;
			case 0x78:	z80.regs[AF].H = z80.regs[BC].H; _Z80_ITS(4,1,"LD A,B"); break;
			case 0x79:	z80.regs[AF].H = z80.regs[BC].L; _Z80_ITS(4,1,"LD A,C"); break;
			case 0x7A:	z80.regs[AF].H = z80.regs[DE].H; _Z80_ITS(4,1,"LD A,D"); break;
			case 0x7B:	z80.regs[AF].H = z80.regs[DE].L; _Z80_ITS(4,1,"LD A,E"); break;
			case 0x7C:	z80.regs[AF].H = z80.regs[HL].H; _Z80_ITS(4,1,"LD A,H"); break;
			case 0x7D:	z80.regs[AF].H = z80.regs[HL].L; _Z80_ITS(4,1,"LD A,L"); break;
			
			case 0x47:	z80.regs[BC].H = z80.regs[AF].H; _Z80_ITS(4,1,"LD B,A"); break;
			case 0x40:	_Z80_ITS(4,1,"LD B,B"); break;
			case 0x41:	z80.regs[BC].H = z80.regs[BC].L; _Z80_ITS(4,1,"LD B,C"); break;
			case 0x42:	z80.regs[BC].H = z80.regs[DE].H; _Z80_ITS(4,1,"LD B,D"); break;
			case 0x43:	z80.regs[BC].H = z80.regs[DE].L; _Z80_ITS(4,1,"LD B,E"); break;
			case 0x44:	z80.regs[BC].H = z80.regs[HL].H; _Z80_ITS(4,1,"LD B,H"); break;
			case 0x45:	z80.regs[BC].H = z80.regs[HL].L; _Z80_ITS(4,1,"LD B,L"); break;
			
			case 0x4F:	z80.regs[BC].L = z80.regs[AF].H; _Z80_ITS(4,1,"LD C,A"); break;
			case 0x48:	z80.regs[BC].L = z80.regs[BC].H; _Z80_ITS(4,1,"LD C,B"); break;
			case 0x49:	_Z80_ITS(4,1,"LD C,C"); break;
			case 0x4A:	z80.regs[BC].L = z80.regs[DE].H; _Z80_ITS(4,1,"LD C,D"); break;
			case 0x4B:	z80.regs[BC].L = z80.regs[DE].L; _Z80_ITS(4,1,"LD C,E"); break;
			case 0x4C:	z80.regs[BC].L = z80.regs[HL].H; _Z80_ITS(4,1,"LD C,H"); break;
			case 0x4D:	z80.regs[BC].L = z80.regs[HL].L; _Z80_ITS(4,1,"LD C,L"); break;
			
			case 0x57:	z80.regs[DE].H = z80.regs[AF].H; _Z80_ITS(4,1,"LD D,A"); break;
			case 0x50:	z80.regs[DE].H = z80.regs[BC].H; _Z80_ITS(4,1,"LD D,B"); break;
			case 0x51:	z80.regs[DE].H = z80.regs[BC].L; _Z80_ITS(4,1,"LD D,C"); break;
			case 0x52:	_Z80_ITS(4,1,"LD D,D"); break;
			case 0x53:	z80.regs[DE].H = z80.regs[DE].L; _Z80_ITS(4,1,"LD D,E"); break;
			case 0x54:	z80.regs[DE].H = z80.regs[HL].H; _Z80_ITS(4,1,"LD D,H"); break;
			case 0x55:	z80.regs[DE].H = z80.regs[HL].L; _Z80_ITS(4,1,"LD D,L"); break;
			
			case 0x5F:	z80.regs[DE].L = z80.regs[AF].H; _Z80_ITS(4,1,"LD E,A"); break;
			case 0x58:	z80.regs[DE].L = z80.regs[BC].H; _Z80_ITS(4,1,"LD E,B"); break;
			case 0x59:	z80.regs[DE].L = z80.regs[BC].L; _Z80_ITS(4,1,"LD E,C"); break;
			case 0x5A:	z80.regs[DE].L = z80.regs[DE].H; _Z80_ITS(4,1,"LD E,D"); break;
			case 0x5B:	_Z80_ITS(4,1,"LD E,E"); break;
			case 0x5C:	z80.regs[DE].L = z80.regs[HL].H; _Z80_ITS(4,1,"LD E,H"); break;
			case 0x5D:	z80.regs[DE].L = z80.regs[HL].L; _Z80_ITS(4,1,"LD E,L"); break;
			
			case 0x67:	z80.regs[HL].H = z80.regs[AF].H; _Z80_ITS(4,1,"LD H,A"); break;
			case 0x60:	z80.regs[HL].H = z80.regs[BC].H; _Z80_ITS(4,1,"LD H,B"); break;
			case 0x61:	z80.regs[HL].H = z80.regs[BC].L; _Z80_ITS(4,1,"LD H,C"); break;
			case 0x62:	z80.regs[HL].H = z80.regs[DE].H; _Z80_ITS(4,1,"LD H,D"); break;
			case 0x63:	z80.regs[HL].H = z80.regs[DE].L; _Z80_ITS(4,1,"LD H,E"); break;
			case 0x64:	_Z80_ITS(4,1,"LD H,H"); break;
			case 0x65:	z80.regs[HL].H = z80.regs[HL].L; _Z80_ITS(4,1,"LD H,L"); break;
			
			case 0x6F:	z80.regs[HL].L = z80.regs[AF].H; _Z80_ITS(4,1,"LD L,A"); break;
			case 0x68:	z80.regs[HL].L = z80.regs[BC].H; _Z80_ITS(4,1,"LD L,B"); break;
			case 0x69:	z80.regs[HL].L = z80.regs[BC].L; _Z80_ITS(4,1,"LD L,C"); break;
			case 0x6A:	z80.regs[HL].L = z80.regs[DE].H; _Z80_ITS(4,1,"LD L,D"); break;
			case 0x6B:	z80.regs[HL].L = z80.regs[DE].L; _Z80_ITS(4,1,"LD L,E"); break;
			case 0x6C:	z80.regs[HL].L = z80.regs[HL].H; _Z80_ITS(4,1,"LD L,H"); break;
			case 0x6D:	_Z80_ITS(4,1,"LD L,L"); break;
			

			case 0x02: 	_Z80_WRITE_BYTE( z80.regs[BC].REG16, z80.regs[AF].H ); _Z80_ITS(7,1,"LD (BC),A"); break;
			case 0x12: 	_Z80_WRITE_BYTE( z80.regs[DE].REG16, z80.regs[AF].H ); _Z80_ITS(7,1,"LD (DE),A"); break;

			case 0x36:	_Z80_FETCH_BYTE; _Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L) ; _Z80_ITS_1(10,2,"LD (HL),%02Xh",z80.regs[WZ].L); break;

			case 0x77:	_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[AF].H); _Z80_ITS(7,1,"LD (HL),A"); break;
			case 0x70:	_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[BC].H); _Z80_ITS(7,1,"LD (HL),B"); break;
			case 0x71:	_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[BC].L); _Z80_ITS(7,1,"LD (HL),C"); break;
			case 0x72:	_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[DE].H); _Z80_ITS(7,1,"LD (HL),D"); break;
			case 0x73:	_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[DE].L); _Z80_ITS(7,1,"LD (HL),E"); break;
			case 0x74:	_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[HL].H); _Z80_ITS(7,1,"LD (HL),H"); break;
			case 0x75:	_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[HL].L); _Z80_ITS(7,1,"LD (HL),L"); break;

			case 0x3A:	_Z80_FETCH_WORD; _Z80_READ_RAM( z80.regs[WZ].REG16, z80.regs[AF].H); _Z80_ITS_1(13,3,"LD A,(%04Xh)",z80.regs[WZ].REG16); break;
			case 0x32:	_Z80_FETCH_WORD; _Z80_WRITE_RAM(z80.regs[WZ].REG16, z80.regs[AF].H); _Z80_ITS_1(13,3,"LD (%04Xh),A",z80.regs[WZ].REG16); break;
			case 0x22:	_Z80_FETCH_WORD; _Z80_WRITE_REG16(z80.regs[WZ].REG16, HL); _Z80_ITS_1(16,3,"LD (%04Xh),HL",z80.regs[WZ].REG16); break;
			case 0x0A:  _Z80_READ_RAM(z80.regs[BC].REG16,z80.regs[AF].H); _Z80_ITS(7,1,"LD A,(BC)"); break;
			case 0x1A:  _Z80_READ_RAM(z80.regs[DE].REG16,z80.regs[AF].H); _Z80_ITS(7,1,"LD A,(DE)"); break;
			case 0x2A:	_Z80_FETCH_WORD; _Z80_READ_REG16( z80.regs[WZ].REG16 , HL ) ; _Z80_ITS_1(16,3,"LD HL, (%04Xh)",z80.regs[WZ].REG16); break;
			
			case 0xF9: 	z80.regs[SP].REG16 = z80.regs[HL].REG16; _Z80_ITS(6,1,"LD SP,HL"); break;
			
			case 0x7E:	_Z80_READ_RAM(z80.regs[HL].REG16,z80.regs[AF].H); _Z80_ITS(7,1,"LD A,(HL)");  break;
			case 0x46:	_Z80_READ_RAM(z80.regs[HL].REG16,z80.regs[BC].H); _Z80_ITS(7,1,"LD B,(HL)");  break;
			case 0x4E:	_Z80_READ_RAM(z80.regs[HL].REG16,z80.regs[BC].L); _Z80_ITS(7,1,"LD C,(HL)");  break;
			case 0x56:	_Z80_READ_RAM(z80.regs[HL].REG16,z80.regs[DE].H); _Z80_ITS(7,1,"LD D,(HL)");  break;
			case 0x5E:	_Z80_READ_RAM(z80.regs[HL].REG16,z80.regs[DE].L); _Z80_ITS(7,1,"LD E,(HL)");  break;
			case 0x66:	_Z80_READ_RAM(z80.regs[HL].REG16,z80.regs[HL].H); _Z80_ITS(7,1,"LD H,(HL)");  break;
			case 0x6E:	_Z80_READ_RAM(z80.regs[HL].REG16,z80.regs[HL].L); _Z80_ITS(7,1,"LD L,(HL)");  break;
			
			case 0x37:	z80.regs[AF].CFLAG = 1; z80.regs[AF].HFLAG = 0; z80.regs[AF].NFLAG = 0; _Z80_ITS(4,1,"SCF"); break;
			case 0x3F:	z80.regs[AF].CFLAG = (z80.regs[AF].CFLAG == 0); z80.regs[AF].NFLAG = 0; _Z80_ITS(4,1,"CCF"); break;
			case 0x2F:	z80.regs[AF].H = ~z80.regs[AF].H; z80.regs[AF].HFLAG = 1; z80.regs[AF].NFLAG = 1; _Z80_ITS(4,1,"CPL"); break;
			
			
			case 0xF3:	z80.status.IFF1 = 0; z80.status.IFF2 = 0; _Z80_ITS(4,1,"DI"); break;
			case 0xFB:	z80.status.IFF1 = 1; z80.status.IFF2 = 1; _Z80_ITS(4,1,"EI"); break; 
			
			case 0x08: z80.regs[WZ].REG16 = z80.regs[AF].REG16; z80.regs[AF].REG16 = z80.regs[AFPLUS].REG16; z80.regs[AFPLUS].REG16 = z80.regs[WZ].REG16; _Z80_ITS(4,1,"EX AF, AF'"); break; 
			case 0xEB: z80.regs[WZ].REG16 = z80.regs[DE].REG16; z80.regs[DE].REG16 = z80.regs[HL].REG16; z80.regs[HL].REG16 = z80.regs[WZ].REG16;  _Z80_ITS(4,1,"EX DE, HL"); break;
			case 0xE3: z80.regs[WZ].REG16 = z80.regs[HL].REG16; _Z80_READ_REG16( z80.regs[SP].REG16, HL ); _Z80_WRITE_REG16 ( z80.regs[SP].REG16, WZ ); _Z80_ITS(19,1,"EX (SP),HL" ); break; 
			 
			case 0xD9: 	z80.regs[WZ].REG16 = z80.regs[BC].REG16; z80.regs[BC].REG16 = z80.regs[BCPLUS].REG16; z80.regs[BCPLUS].REG16 = z80.regs[WZ].REG16;
						z80.regs[WZ].REG16 = z80.regs[DE].REG16; z80.regs[DE].REG16 = z80.regs[DEPLUS].REG16; z80.regs[DEPLUS].REG16 = z80.regs[WZ].REG16;
						z80.regs[WZ].REG16 = z80.regs[HL].REG16; z80.regs[HL].REG16 = z80.regs[HLPLUS].REG16; z80.regs[HLPLUS].REG16 = z80.regs[WZ].REG16;
						_Z80_ITS(4,1,"EXX"); break;

			case 0xCE:  _Z80_FETCH_BYTE; ALU_ADC(z80.regs[WZ].L); _Z80_ITS_1(7,2,"ADC A,%02Xh",z80.regs[WZ].L); break;
			case 0x88:  ALU_ADC(z80.regs[BC].H); _Z80_ITS(4,1,"ADC A,B"); break;
			case 0x89:  ALU_ADC(z80.regs[BC].L); _Z80_ITS(4,1,"ADC A,C"); break;
			case 0x8A:  ALU_ADC(z80.regs[DE].H); _Z80_ITS(4,1,"ADC A,D"); break;
			case 0x8B:  ALU_ADC(z80.regs[DE].L); _Z80_ITS(4,1,"ADC A,E"); break;
			case 0x8C:  ALU_ADC(z80.regs[HL].H); _Z80_ITS(4,1,"ADC A,H"); break;
			case 0x8D:  ALU_ADC(z80.regs[HL].L); _Z80_ITS(4,1,"ADC A,L"); break;
			case 0x8F:  ALU_ADC(z80.regs[AF].H); _Z80_ITS(4,1,"ADC A,A"); break;
			case 0x8E:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_ADC(z80.regs[WZ].L); _Z80_ITS(7,1,"ADC A,(HL)");break;
		
			case 0xDE:  _Z80_FETCH_BYTE; ALU_SBC(z80.regs[WZ].L); _Z80_ITS_1(7,2,"SBC A,%02Xh",z80.regs[WZ].L); break;
			case 0x98:  ALU_SBC(z80.regs[BC].H); _Z80_ITS(4,1,"SBC A,B"); break;
			case 0x99:  ALU_SBC(z80.regs[BC].L); _Z80_ITS(4,1,"SBC A,C"); break;
			case 0x9A:  ALU_SBC(z80.regs[DE].H); _Z80_ITS(4,1,"SBC A,D"); break;
			case 0x9B:  ALU_SBC(z80.regs[DE].L); _Z80_ITS(4,1,"SBC A,E"); break;
			case 0x9C:  ALU_SBC(z80.regs[HL].H); _Z80_ITS(4,1,"SBC A,H"); break;
			case 0x9D:  ALU_SBC(z80.regs[HL].L); _Z80_ITS(4,1,"SBC A,L"); break;
			case 0x9F:  ALU_SBC(z80.regs[AF].H); _Z80_ITS(4,1,"SBC A,A"); break;
			case 0x9E:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SBC(z80.regs[WZ].L); _Z80_ITS(7,1,"SBC A,(HL)");break;
		
			
			case 0x86:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_ADD(z80.regs[WZ].L); _Z80_ITS(7,1,"ADD A,(HL)");break;
			case 0xC6:  _Z80_FETCH_BYTE; ALU_ADD(z80.regs[WZ].L); _Z80_ITS_1(7,2,"ADD A,%02Xh",z80.regs[WZ].L);break;
			case 0x80:  ALU_ADD(z80.regs[BC].H); _Z80_ITS(4,1,"ADD A,B");break;
			case 0x81:  ALU_ADD(z80.regs[BC].L); _Z80_ITS(4,1,"ADD A,C");break;
			case 0x82:  ALU_ADD(z80.regs[DE].H); _Z80_ITS(4,1,"ADD A,D");break;
			case 0x83:  ALU_ADD(z80.regs[DE].L); _Z80_ITS(4,1,"ADD A,E");break;
			case 0x84:  ALU_ADD(z80.regs[HL].H); _Z80_ITS(4,1,"ADD A,H");break;
			case 0x85:  ALU_ADD(z80.regs[HL].L); _Z80_ITS(4,1,"ADD A,L");break;
			case 0x87:  ALU_ADD(z80.regs[AF].H); _Z80_ITS(4,1,"ADD A,A");break;

			case 0x09:  ALU_ADD_16(z80.regs[HL].REG16,z80.regs[BC].REG16); _Z80_ITS(11,1,"ADD HL,BC"); break;
			case 0x19:  ALU_ADD_16(z80.regs[HL].REG16,z80.regs[DE].REG16); _Z80_ITS(11,1,"ADD HL,DE"); break;
			case 0x29:  ALU_ADD_16(z80.regs[HL].REG16,z80.regs[HL].REG16); _Z80_ITS(11,1,"ADD HL,HL"); break;
			case 0x39:  ALU_ADD_16(z80.regs[HL].REG16,z80.regs[SP].REG16); _Z80_ITS(11,1,"ADD HL,SP"); break;
			
			
			case 0x96:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); ALU_SUB(z80.regs[WZ].L); _Z80_ITS(7,1,"SUB A,(HL)");break;
			case 0xD6:  _Z80_FETCH_BYTE; ALU_SUB(z80.regs[WZ].L); _Z80_ITS_1(7,2,"SUB A,%02Xh",(uint8_t)z80.regs[WZ].L);break;
			case 0x90:  ALU_SUB(z80.regs[BC].H); _Z80_ITS(4,1,"SUB A,B");break;
			case 0x91:  ALU_SUB(z80.regs[BC].L); _Z80_ITS(4,1,"SUB A,C");break;
			case 0x92:  ALU_SUB(z80.regs[DE].H); _Z80_ITS(4,1,"SUB A,D");break;
			case 0x93:  ALU_SUB(z80.regs[DE].L); _Z80_ITS(4,1,"SUB A,E");break;
			case 0x94:  ALU_SUB(z80.regs[HL].H); _Z80_ITS(4,1,"SUB A,H");break;
			case 0x95:  ALU_SUB(z80.regs[HL].L); _Z80_ITS(4,1,"SUB A,L");break;
			case 0x97:  ALU_SUB(z80.regs[AF].H); _Z80_ITS(4,1,"SUB A,A");break;

			case 0x35:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); 
						ALU_DEC( z80.regs[WZ].L );
						_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); 
						_Z80_ITS(11,1,"DEC (HL)");break;
			case 0x05:  ALU_DEC(z80.regs[BC].H); _Z80_ITS(4,1,"DEC B");break;
			case 0x0D:  ALU_DEC(z80.regs[BC].L); _Z80_ITS(4,1,"DEC C");break;
			case 0x15:  ALU_DEC(z80.regs[DE].H); _Z80_ITS(4,1,"DEC D");break;
			case 0x1D:  ALU_DEC(z80.regs[DE].L); _Z80_ITS(4,1,"DEC E");break;
			case 0x25:  ALU_DEC(z80.regs[HL].H); _Z80_ITS(4,1,"DEC H");break;
			case 0x2D:  ALU_DEC(z80.regs[HL].L); _Z80_ITS(4,1,"DEC L");break;
			case 0x3D:  ALU_DEC(z80.regs[AF].H); _Z80_ITS(4,1,"DEC A");break;

			case 0x0B:	z80.regs[BC].REG16--; _Z80_ITS(6,1,"DEC BC"); break;
			case 0x1B:	z80.regs[DE].REG16--; _Z80_ITS(6,1,"DEC DE"); break;
			case 0x2B:	z80.regs[HL].REG16--; _Z80_ITS(6,1,"DEC HL"); break;
			case 0x3B:	z80.regs[SP].REG16--; _Z80_ITS(6,1,"DEC SP"); break;
			
			case 0x34:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); 
						ALU_INC( z80.regs[WZ].L ); 
						_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); 
						_Z80_ITS(11,1,"INC (HL)");break;
			case 0x04:  ALU_INC( z80.regs[BC].H ); _Z80_ITS(4,1,"INC B");break;
			case 0x0C:  ALU_INC( z80.regs[BC].L ); _Z80_ITS(4,1,"INC C");break;
			case 0x14:  ALU_INC( z80.regs[DE].H ); _Z80_ITS(4,1,"INC D");break;
			case 0x1C:  ALU_INC( z80.regs[DE].L ); _Z80_ITS(4,1,"INC E");break;
			case 0x24:  ALU_INC( z80.regs[HL].H ); _Z80_ITS(4,1,"INC H");break;
			case 0x2C:  ALU_INC( z80.regs[HL].L ); _Z80_ITS(4,1,"INC L");break;
			case 0x3C:  ALU_INC( z80.regs[AF].H ); _Z80_ITS(4,1,"INC A");break;

			case 0x03:	z80.regs[BC].REG16++; _Z80_ITS(6,1,"INC BC"); break;
			case 0x13:	z80.regs[DE].REG16++; _Z80_ITS(6,1,"INC DE"); break;
			case 0x23:	z80.regs[HL].REG16++; _Z80_ITS(6,1,"INC HL"); break;
			case 0x33:	z80.regs[SP].REG16++; _Z80_ITS(6,1,"INC SP"); break;

			case 0xA6:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); 
						ALU_AND( z80.regs[WZ].L );
						_Z80_ITS(7,1,"AND A,(HL)");
						break;
			case 0xE6:  _Z80_FETCH_BYTE; ALU_AND( z80.regs[WZ].L ); _Z80_ITS_1(7,2,"AND A,%02Xh",z80.regs[WZ].L); break;
			case 0xA0:  ALU_AND( z80.regs[BC].H ); _Z80_ITS(4,1,"AND A,B");break;
			case 0xA1:  ALU_AND( z80.regs[BC].L ); _Z80_ITS(4,1,"AND A,C");break;
			case 0xA2:  ALU_AND( z80.regs[DE].H ); _Z80_ITS(4,1,"AND A,D");break;
			case 0xA3:  ALU_AND( z80.regs[DE].L ); _Z80_ITS(4,1,"AND A,E");break;
			case 0xA4:  ALU_AND( z80.regs[HL].H ); _Z80_ITS(4,1,"AND A,H");break;
			case 0xA5:  ALU_AND( z80.regs[HL].L ); _Z80_ITS(4,1,"AND A,L");break;
			case 0xA7:  ALU_AND( z80.regs[BC].H ); _Z80_ITS(4,1,"AND A,A");break;

			case 0xB6:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); 
						ALU_OR( z80.regs[WZ].L );
						_Z80_ITS(7,1,"OR A,(HL)");break;
			case 0xF6:  _Z80_FETCH_BYTE; ALU_OR( z80.regs[WZ].L ); _Z80_ITS_1(7,2,"OR A,%02Xh",z80.regs[WZ].L);break;
			case 0xB0:  ALU_OR( z80.regs[BC].H ); _Z80_ITS(4,1,"OR A,B");break;
			case 0xB1:  ALU_OR( z80.regs[BC].L ); _Z80_ITS(4,1,"OR A,C");break;
			case 0xB2:  ALU_OR( z80.regs[DE].H ); _Z80_ITS(4,1,"OR A,D");break;
			case 0xB3:  ALU_OR( z80.regs[DE].L ); _Z80_ITS(4,1,"OR A,E");break;
			case 0xB4:  ALU_OR( z80.regs[HL].H ); _Z80_ITS(4,1,"OR A,H");break;
			case 0xB5:  ALU_OR( z80.regs[HL].L ); _Z80_ITS(4,1,"OR A,L");break;
			case 0xB7:  ALU_OR( z80.regs[AF].H ); _Z80_ITS(4,1,"OR A,A");break;


			case 0xAE:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); 
						ALU_XOR( z80.regs[WZ].L );
						_Z80_ITS(7,1,"XOR A,(HL)");break;
			case 0xEE:  _Z80_FETCH_BYTE; ALU_XOR( z80.regs[WZ].L ); _Z80_ITS_1(7,2,"XOR A,%02Xh",z80.regs[WZ].L);break;
			case 0xA8:  ALU_XOR( z80.regs[BC].H ); _Z80_ITS(4,1,"XOR A,B");break;
			case 0xA9:  ALU_XOR( z80.regs[BC].L ); _Z80_ITS(4,1,"XOR A,C");break;
			case 0xAA:  ALU_XOR( z80.regs[DE].H ); _Z80_ITS(4,1,"XOR A,D");break;
			case 0xAB:  ALU_XOR( z80.regs[DE].L ); _Z80_ITS(4,1,"XOR A,E");break;
			case 0xAC:  ALU_XOR( z80.regs[HL].H ); _Z80_ITS(4,1,"XOR A,H");break;
			case 0xAD:  ALU_XOR( z80.regs[HL].L ); _Z80_ITS(4,1,"XOR A,L");break;
			case 0xAF:  ALU_XOR( z80.regs[AF].H ); _Z80_ITS(4,1,"XOR A,A");break;

			
			case 0xBE:	_Z80_READ_RAM( z80.regs[HL].REG16, z80.regs[WZ].L); 
						ALU_CP( z80.regs[WZ].L );
						_Z80_ITS(7,1,"CP (HL)");
						break;
			case 0xFE:  _Z80_FETCH_BYTE; ALU_CP( z80.regs[WZ].L ); _Z80_ITS_1(7,2,"CP %02Xh",z80.regs[WZ].L);break;
			case 0xB8:  ALU_CP( z80.regs[BC].H ); _Z80_ITS(4,1,"CP B");break;
			case 0xB9:  ALU_CP( z80.regs[BC].L ); _Z80_ITS(4,1,"CP C");break;
			case 0xBA:  ALU_CP( z80.regs[DE].H ); _Z80_ITS(4,1,"CP D");break;
			case 0xBB:  ALU_CP( z80.regs[DE].L ); _Z80_ITS(4,1,"CP E");break;
			case 0xBC:  ALU_CP( z80.regs[HL].H ); _Z80_ITS(4,1,"CP H");break;
			case 0xBD:  ALU_CP( z80.regs[HL].L ); _Z80_ITS(4,1,"CP L");break;
			case 0xBF:  ALU_CP( z80.regs[AF].H ); _Z80_ITS(4,1,"CP A");break;
					

			case 0x10:	_Z80_FETCH_BYTE; 
						if ( --z80.regs[BC].H != 0 ) { z80.regs[PC].REG16 += (int8_t) z80.regs[WZ].L; _Z80_ITS_1(13,2,"DJNZ %04Xh",z80.regs[PC].REG16);}
						else { _Z80_ITS_1(7,2,"DJNZ %04Xh",z80.regs[PC].REG16 + (int8_t) z80.regs[WZ].L); }
						break;
						
			case 0xC4:	_Z80_FETCH_WORD; if ( ! z80.regs[AF].ZFLAG ) { _Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(17,3,"CALL NZ, %04Xh",z80.regs[WZ].REG16); } else { _Z80_ITS_1(10,3,"CALL NZ, %04Xh",z80.regs[WZ].REG16); } ;  break;
			case 0xCC:  _Z80_FETCH_WORD; if (   z80.regs[AF].ZFLAG ) { _Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(17,3,"CALL Z, %04Xh",z80.regs[WZ].REG16); } else { _Z80_ITS_1(10,3,"CALL Z, %04Xh",z80.regs[WZ].REG16); } ; break;
			case 0xD4:	_Z80_FETCH_WORD; if ( ! z80.regs[AF].CFLAG ) { _Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(17,3,"CALL NC, %04Xh",z80.regs[WZ].REG16); } else { _Z80_ITS_1(10,3,"CALL NC, %04Xh",z80.regs[WZ].REG16); } ; break;
			case 0xDC:	_Z80_FETCH_WORD; if (   z80.regs[AF].CFLAG ) { _Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(17,3,"CALL Z, %04Xh",z80.regs[WZ].REG16); } else { _Z80_ITS_1(10,3,"CALL Z, %04Xh",z80.regs[WZ].REG16); } ;  break;
			case 0xE4:	_Z80_FETCH_WORD; if ( ! z80.regs[AF].PFLAG ) { _Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(17,3,"CALL PO, %04Xh",z80.regs[WZ].REG16); } else { _Z80_ITS_1(10,3,"CALL PO, %04Xh",z80.regs[WZ].REG16); } ; break;
			case 0xEC:	_Z80_FETCH_WORD; if (   z80.regs[AF].PFLAG ) { _Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(17,3,"CALL PE, %04Xh",z80.regs[WZ].REG16); } else { _Z80_ITS_1(10,3,"CALL PE, %04Xh",z80.regs[WZ].REG16); } ; break;
			case 0xF4:	_Z80_FETCH_WORD; if ( ! z80.regs[AF].SFLAG ) { _Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(17,3,"CALL P, %04Xh",z80.regs[WZ].REG16); } else { _Z80_ITS_1(10,3,"CALL P, %04Xh",z80.regs[WZ].REG16); } ;  break;
			case 0xFC:  _Z80_FETCH_WORD; if (   z80.regs[AF].SFLAG ) { _Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(17,3,"CALL M, %04Xh",z80.regs[WZ].REG16); } else { _Z80_ITS_1(10,3,"CALL M, %04Xh",z80.regs[WZ].REG16); } ;  break;
			case 0xCD:  _Z80_FETCH_WORD; _Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(17,3,"CALL %04Xh",z80.regs[WZ].REG16); break;

			case 0xC2:	_Z80_FETCH_WORD; if ( ! z80.regs[AF].ZFLAG ) { z80.regs[PC].REG16 = z80.regs[WZ].REG16; } _Z80_ITS_1(10,3,"JP NZ %04Xh",z80.regs[WZ].REG16); break;
			case 0xCA:  _Z80_FETCH_WORD; if (   z80.regs[AF].ZFLAG ) { z80.regs[PC].REG16 = z80.regs[WZ].REG16; } _Z80_ITS_1(10,3,"JP Z %04Xh",z80.regs[WZ].REG16); break;
			case 0xD2:	_Z80_FETCH_WORD; if ( ! z80.regs[AF].CFLAG ) { z80.regs[PC].REG16 = z80.regs[WZ].REG16; } _Z80_ITS_1(10,3,"JP NC %04Xh",z80.regs[WZ].REG16); break;
			case 0xDA:	_Z80_FETCH_WORD; if (   z80.regs[AF].CFLAG ) { z80.regs[PC].REG16 = z80.regs[WZ].REG16; } _Z80_ITS_1(10,3,"JP C %04Xh",z80.regs[WZ].REG16);  break;
			case 0xE2:	_Z80_FETCH_WORD; if ( ! z80.regs[AF].PFLAG ) { z80.regs[PC].REG16 = z80.regs[WZ].REG16; } _Z80_ITS_1(10,3,"JP PO $%04Xh",z80.regs[WZ].REG16); break;
			case 0xEA:	_Z80_FETCH_WORD; if (   z80.regs[AF].PFLAG ) { z80.regs[PC].REG16 = z80.regs[WZ].REG16; } _Z80_ITS_1(10,3,"JP PE %04Xh",z80.regs[WZ].REG16);  break;
			case 0xF2:	_Z80_FETCH_WORD; if ( ! z80.regs[AF].SFLAG ) { z80.regs[PC].REG16 = z80.regs[WZ].REG16; } _Z80_ITS_1(10,3,"JP P %04Xh",z80.regs[WZ].REG16); break;
			case 0xFA:  _Z80_FETCH_WORD; if (   z80.regs[AF].SFLAG ) { z80.regs[PC].REG16 = z80.regs[WZ].REG16; } _Z80_ITS_1(10,3,"JP M %04Xh",z80.regs[WZ].REG16); break;
			case 0xC3:  _Z80_FETCH_WORD; z80.regs[PC].REG16 = z80.regs[WZ].REG16; _Z80_ITS_1(10,3,"JP %04Xh",z80.regs[WZ].REG16); break;
		
			case 0xE9:	z80.regs[PC].REG16 = z80.regs[HL].REG16; _Z80_ITS(4,1,"JP (HL)"); break;
			
			case 0x20:	_Z80_FETCH_BYTE; if ( ! ZX ) { z80.regs[PC].REG16 += (int8_t)z80.regs[WZ].L; _Z80_ITS_1(12,2,"JR NZ %04Xh",z80.regs[PC].REG16); } else { _Z80_ITS_1(7,2,"JR NZ %04Xh",z80.regs[PC].REG16 + (int8_t)z80.regs[WZ].L); } ; break;
			case 0x28:	_Z80_FETCH_BYTE; if (   ZX ) { z80.regs[PC].REG16 += (int8_t)z80.regs[WZ].L; _Z80_ITS_1(12,2,"JR Z %04Xh",z80.regs[PC].REG16); } else { _Z80_ITS_1(7,2,"JR Z %04Xh",z80.regs[PC].REG16 + (int8_t)z80.regs[WZ].L); } ; break;
			case 0x30:	_Z80_FETCH_BYTE; if ( ! CX ) { z80.regs[PC].REG16 += (int8_t)z80.regs[WZ].L; _Z80_ITS_1(12,2,"JR NC %04Xh",z80.regs[PC].REG16); } else { _Z80_ITS_1(7,2,"JR NC %04Xh",z80.regs[PC].REG16 + (int8_t)z80.regs[WZ].L); } ; break;
			case 0x38:	_Z80_FETCH_BYTE; if (   CX ) { z80.regs[PC].REG16 += (int8_t)z80.regs[WZ].L; _Z80_ITS_1(12,2,"JR C %04Xh",z80.regs[PC].REG16); } else { _Z80_ITS_1(7,2,"JR C %04Xh",z80.regs[PC].REG16 + (int8_t)z80.regs[WZ].L); } ; break;
			case 0x18:	_Z80_FETCH_BYTE; z80.regs[PC].REG16 += (int8_t)z80.regs[WZ].L; _Z80_ITS_1(12,2,"JR %04Xh",z80.regs[PC].REG16); break;
			
			case 0xC5:	_Z80_PUSH_REG16(BC); _Z80_ITS(11,1,"PUSH BC"); break;
			case 0xD5:	_Z80_PUSH_REG16(DE); _Z80_ITS(11,1,"PUSH DE"); break;
			case 0xE5:	_Z80_PUSH_REG16(HL); _Z80_ITS(11,1,"PUSH HL"); break;
			case 0xF5:	_Z80_PUSH_REG16(AF); _Z80_ITS(11,1,"PUSH AF"); break;
	
			case 0xC1:	_Z80_POP_REG16(BC); _Z80_ITS(10,1,"POP BC"); break;
			case 0xD1:	_Z80_POP_REG16(DE); _Z80_ITS(10,1,"POP DE"); break;
			case 0xE1:	_Z80_POP_REG16(HL); _Z80_ITS(10,1,"POP HL"); break;
			case 0xF1:	_Z80_POP_REG16(AF); _Z80_ITS(10,1,"POP AF"); break;
	
			case 0xC9:	_Z80_POP_REG16(PC); _Z80_ITS(10,1,"RET"); break;

			case 0xC0:	if ( ! z80.regs[AF].ZFLAG ) { _Z80_POP_REG16(PC); _Z80_ITS(11,1,"RET NZ"); } else { _Z80_ITS(5,1,"RET NZ"); }  break;
			case 0xC8:  if (   z80.regs[AF].ZFLAG ) { _Z80_POP_REG16(PC); _Z80_ITS(11,1,"RET Z"); }  else { _Z80_ITS(5,1,"RET Z"); }   break;
			case 0xD0:	if ( ! z80.regs[AF].CFLAG ) { _Z80_POP_REG16(PC); _Z80_ITS(11,1,"RET NC"); } else { _Z80_ITS(5,1,"RET NC"); }  break;
			case 0xD8:	if (   z80.regs[AF].CFLAG ) { _Z80_POP_REG16(PC); _Z80_ITS(11,1,"RET C"); }  else { _Z80_ITS(5,1,"RET C"); }   break;
			case 0xE0:	if ( ! z80.regs[AF].PFLAG ) { _Z80_POP_REG16(PC); _Z80_ITS(11,1,"RET PO"); } else { _Z80_ITS(5,1,"RET PO"); }  break;
			case 0xE8:	if (   z80.regs[AF].PFLAG ) { _Z80_POP_REG16(PC); _Z80_ITS(11,1,"RET PE"); } else { _Z80_ITS(5,1,"RET PE"); }  break;
			case 0xF0:	if ( ! z80.regs[AF].SFLAG ) { _Z80_POP_REG16(PC); _Z80_ITS(11,1,"RET P"); }  else { _Z80_ITS(5,1,"RET P"); }   break;
			case 0xF8:  if (   z80.regs[AF].SFLAG ) { _Z80_POP_REG16(PC); _Z80_ITS(11,1,"RET M"); }  else { _Z80_ITS(5,1,"RET M"); }   break;
			
			case 0xC7:	_Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = 0x00; _Z80_ITS(11,1,"RST 00H"); break;
			case 0xCF:	_Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = 0x08; _Z80_ITS(11,1,"RST 08H"); break;
			case 0xD7:	_Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = 0x10; _Z80_ITS(11,1,"RST 10H"); break;
			case 0xDF:	_Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = 0x18; _Z80_ITS(11,1,"RST 18H"); break;
			case 0xE7:	_Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = 0x20; _Z80_ITS(11,1,"RST 20H"); break;
			case 0xEF:	_Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = 0x28; _Z80_ITS(11,1,"RST 28H"); break;
			case 0xF7:	_Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = 0x30; _Z80_ITS(11,1,"RST 30H"); break;
			case 0xFF:	_Z80_PUSH_REG16(PC); z80.regs[PC].REG16 = 0x38; _Z80_ITS(11,1,"RST 38H"); break;
			
			case 0x17:	z80.regs[WZ].L = z80.regs[AF].H >> 7; 
						z80.regs[AF].H = (z80.regs[AF].H << 1) + z80.regs[AF].CFLAG; 
						z80.regs[AF].CFLAG = z80.regs[WZ].L; 
						z80.regs[AF].HFLAG = z80.regs[AF].NFLAG = 0; 
						_Z80_ITS(4,1,"RLA"); 
						break;
			case 0x07:	z80.regs[WZ].L = z80.regs[AF].H >> 7; 
						z80.regs[AF].H = (z80.regs[AF].H << 1) | z80.regs[WZ].L; 
						z80.regs[AF].CFLAG = z80.regs[WZ].L; 
						z80.regs[AF].HFLAG = z80.regs[AF].NFLAG = 0; 
						_Z80_ITS(4,1,"RLCA"); break;	
			case 0x1F:	z80.regs[WZ].L = z80.regs[AF].H & 0x01; 
						z80.regs[AF].H = (z80.regs[AF].H >> 1) | (z80.regs[AF].CFLAG << 7); 
						CX = z80.regs[WZ].L; 
						HX = NX = 0; 
						_Z80_ITS(4,1,"RRA"); break;
			case 0x0F:	z80.regs[WZ].L = z80.regs[AF].H & 0x01; 
						z80.regs[AF].H = (z80.regs[AF].H >> 1) | (z80.regs[WZ].L << 7); 
						CX = z80.regs[WZ].L; 
						HX = NX = 0; 
						_Z80_ITS(4,1,"RRCA"); break;
			 
			default: z80_error(ERROR_UNKNOWN_OPCODE); break;	
	}	
}




void z80_alu_daa() {
	
	switch(NX) {
		     case 0: switch(CX) {
			      case 0: switch(HX) {
					       case 0: if (((z80.regs[AF].H & 0x0F ) <= 9 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) <= 9) ) {
										  CX=0;
									  }
					               if (((z80.regs[AF].H & 0x0F ) >= 0x0A ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) <= 8) ) {
										  CX=0;
										  z80.regs[AF].H += 6;
									  }
								   if (((z80.regs[AF].H & 0x0F ) <= 9 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) >= 0x0A) ) {
										  CX=1;
										  z80.regs[AF].H += 0x60;
									  }      
								   if (((z80.regs[AF].H & 0x0F ) > 0x0A ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) >= 9) ) {
										  CX=1;
										  z80.regs[AF].H += 0x66;
									  }      
					               break;
					       case 1: if (((z80.regs[AF].H & 0x0F ) <= 3 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) <= 9) ) {
										  CX=0;
										  z80.regs[AF].H += 6 ;
									  }
								   if (((z80.regs[AF].H & 0x0F ) <= 3 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) >= 0x0A) ) {
										  CX=1;
										  z80.regs[AF].H += 0x66;
									  }      
					               break;
					      }
			             break;
			      case 1: switch(HX) {
					       case 0: if (((z80.regs[AF].H & 0x0F ) <= 9 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) <= 2) ) {
										  CX=1;
										  z80.regs[AF].H += 0x60;
									  }
									if (((z80.regs[AF].H & 0x0F ) >= 0x0A ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) <= 2) ) {
										  CX=1;
										  z80.regs[AF].H += 0x66;
									  }
					               break;
					       case 1: if (((z80.regs[AF].H & 0x0F ) <= 3 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) <= 3) ) {
										  CX=1;
										  z80.regs[AF].H += 0x66;
									  }
					               break;
					      }
			             break;
		        }
		       break;
		case 1: switch(CX) {
			      case 0: switch(HX) {
					       case 0: if (((z80.regs[AF].H & 0x0F ) <= 9 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) <= 9) ) {
										  CX=0;
										  
									  }
					               break;
					       case 1:  if (((z80.regs[AF].H & 0x0F ) >= 6 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) <= 8) ) {
										  CX=0;
										  z80.regs[AF].H += 0xFA;
									  }
					               break;
					      }
			             break;
			      case 1: switch(HX) {
					       case 0: if (((z80.regs[AF].H & 0x0F ) <= 9 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) >= 7) ) {
										  CX=1;
										  z80.regs[AF].H += 0xA0;
									  }
					               break;
					       case 1: if (((z80.regs[AF].H & 0x0F ) >= 6 ) &&
					                  (((z80.regs[AF].H & 0xF0 ) >> 4) >= 6) ) {
										  CX=1;
										  z80.regs[AF].H += 0x9A;
									  }
					               break;
					      }
			             break;
		        }
		       break;
	} 
	       
	ZX = ( z80.regs[AF].H == 0 );
	SX = ( z80.regs[AF].H  >> 7 ); 
	PX = z80_alu_check_parity( z80.regs[AF].H);
	_Z80_ITS(4,1,"DAA");
 	/* missing the H FLAG and the P flag */
	       
}
