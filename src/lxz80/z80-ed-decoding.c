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

#include "lx80.h"
#include "z80-helper.h"

/**********************************************************************/
/* EXTERNALLY DEFINED VARIABLES										  */
extern t_z80 z80;


/**********************************************************************/
/* INTERNALLY DEFINED FUNCTIONS										  */
void z80_ed_decoding( );
/**********************************************************************/


void z80_ed_decoding (  ) {

 int c;
 	
	_Z80_FETCH_INST;
		
	switch ((uint8_t)z80.status.REGINST) {
					
		case 0x4A:  ALU_ADC_HL(z80.regs[BC].REG16); _Z80_ITS(15,2,"ADC HL,BC"); break;
		case 0x5A:  ALU_ADC_HL(z80.regs[DE].REG16); _Z80_ITS(15,2,"ADC HL,DE"); break;
		case 0x6A:  ALU_ADC_HL(z80.regs[HL].REG16); _Z80_ITS(15,2,"ADC HL,HL"); break;
		case 0x7A:  ALU_ADC_HL(z80.regs[SP].REG16); _Z80_ITS(15,2,"ADC HL,SP"); break;

		case 0x42:  ALU_SBC_HL(z80.regs[BC].REG16); _Z80_ITS(15,2,"SBC HL,BC"); break;
		case 0x52:  ALU_SBC_HL(z80.regs[DE].REG16); _Z80_ITS(15,2,"SBC HL,DE"); break;
		case 0x62:  ALU_SBC_HL(z80.regs[HL].REG16); _Z80_ITS(15,2,"SBC HL,HL"); break;
		case 0x72:  ALU_SBC_HL(z80.regs[SP].REG16); _Z80_ITS(15,2,"SBC HL,SP"); break;

						
		case 0xA9:  c = CX; 
					_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); 
		            ALU_CP(z80.regs[WZ].L); z80.regs[HL].REG16--; z80.regs[BC].REG16--; 
					PX = ( z80.regs[BC].REG16 != 0); 
					CX = c;
					_Z80_ITS(16,2,"CPD"); 
					break;
		
		case 0xB9:  c = CX; 
		            _Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); 
		            ALU_CP(z80.regs[WZ].L); z80.regs[HL].REG16--; z80.regs[BC].REG16--; 
					PX = ( z80.regs[BC].REG16 != 0); 
					CX = c;
					_Z80_ITS(16,2,"CPDR"); 
					if ( z80.regs[BC].REG16 != 0 && z80.regs[AF].H != z80.regs[WZ].L ) {
						z80.regs[PC].REG16 -= 2;
						_Z80_ITS(21,2,"CPDR");
					}
					break;
					
		case 0xA1:  c = CX; 
		            _Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L); 
		            ALU_CP(z80.regs[WZ].L); z80.regs[HL].REG16++; z80.regs[BC].REG16--; 
					PX = ( z80.regs[BC].REG16 != 0); 
					CX = c;
					_Z80_ITS(16,2,"CPI");
					break;
	
		case 0xB1:  c = CX; 
		            _Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L); 
		            ALU_CP(z80.regs[WZ].L); z80.regs[HL].REG16++; z80.regs[BC].REG16--; 
					PX = ( z80.regs[BC].REG16 != 0); 
					CX = c;
					_Z80_ITS(16,2,"CPIR");
					if ( z80.regs[BC].REG16 != 0 && z80.regs[AF].H != z80.regs[WZ].L ) {
						z80.regs[PC].REG16 -= 2;
						_Z80_ITS(21,2,"CPIR");
					}
					break;	
					
		case 0x46:	z80.status.IMODE = Z80_IM0; _Z80_ITS(8,2,"IM 0"); break;
		case 0x56:	z80.status.IMODE = Z80_IM1; _Z80_ITS(8,2,"IM 1"); break;
		case 0x5E:	z80.status.IMODE = Z80_IM2; _Z80_ITS(8,2,"IM 2"); break;
		
		/* The HFLAG is missing in IN , how to calculate it? No idea */
		case 0x40:	z80.read_io(z80.regs[BC].REG16,&z80.regs[BC].H); NX = 0; SX = (z80.regs[BC].H >> 7); ZX = ( z80.regs[BC].H==0); PX=z80_alu_check_parity(z80.regs[BC].H); _Z80_ITS(12,2,"IN B,(C)"); break;
		case 0x48:	z80.read_io(z80.regs[BC].REG16,&z80.regs[BC].L); NX = 0; SX = (z80.regs[BC].L >> 7); ZX = ( z80.regs[BC].L==0); PX=z80_alu_check_parity(z80.regs[BC].L); _Z80_ITS(12,2,"IN C,(C)"); break;
		case 0x50:	z80.read_io(z80.regs[BC].REG16,&z80.regs[DE].H); NX = 0; SX = (z80.regs[DE].H >> 7); ZX = ( z80.regs[DE].H==0); PX=z80_alu_check_parity(z80.regs[DE].H); _Z80_ITS(12,2,"IN D,(C)"); break;
		case 0x58:	z80.read_io(z80.regs[BC].REG16,&z80.regs[DE].L); NX = 0; SX = (z80.regs[DE].L >> 7); ZX = ( z80.regs[DE].L==0); PX=z80_alu_check_parity(z80.regs[DE].L); _Z80_ITS(12,2,"IN E,(C)"); break;
		case 0x60:	z80.read_io(z80.regs[BC].REG16,&z80.regs[HL].H); NX = 0; SX = (z80.regs[HL].H >> 7); ZX = ( z80.regs[HL].H==0); PX=z80_alu_check_parity(z80.regs[HL].H); _Z80_ITS(12,2,"IN H,(C)"); break;
		case 0x68:	z80.read_io(z80.regs[BC].REG16,&z80.regs[HL].L); NX = 0; SX = (z80.regs[HL].L >> 7); ZX = ( z80.regs[HL].L==0); PX=z80_alu_check_parity(z80.regs[HL].L); _Z80_ITS(12,2,"IN L,(C)"); break;
		case 0x78:	z80.read_io(z80.regs[BC].REG16,&z80.regs[AF].H); NX = 0; SX = (z80.regs[AF].H >> 7); ZX = ( z80.regs[AF].H==0); PX=z80_alu_check_parity(z80.regs[AF].H); _Z80_ITS(12,2,"IN A,(C)"); break;

		case 0x41:	z80.write_io((z80.regs[BC].REG16 & 0xFF00) | z80.regs[BC].H ); _Z80_ITS(12,2,"OUT (C),B"); break;
		case 0x49:	z80.write_io(z80.regs[BC].REG16); _Z80_ITS(12,2,"OUT (C),C"); break;
		case 0x51:	z80.write_io((z80.regs[BC].REG16 & 0xFF00) | z80.regs[DE].H ); _Z80_ITS(12,2,"OUT (C),D"); break;
		case 0x59:	z80.write_io((z80.regs[BC].REG16 & 0xFF00) | z80.regs[DE].L ); _Z80_ITS(12,2,"OUT (C),E"); break;
		case 0x61:	z80.write_io((z80.regs[BC].REG16 & 0xFF00) | z80.regs[HL].H ); _Z80_ITS(12,2,"OUT (C),H"); break;
		case 0x69:	z80.write_io((z80.regs[BC].REG16 & 0xFF00) | z80.regs[HL].L ); _Z80_ITS(12,2,"OUT (C),L"); break;
		case 0x79:	z80.write_io((z80.regs[BC].REG16 & 0xFF00) | z80.regs[AF].H ); _Z80_ITS(12,2,"OUT (C),A"); break;


		case 0xAB:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L);
					z80.write_io( z80.regs[BC].REG16 );
					z80.regs[HL].REG16--; z80.regs[BC].H--;
					z80.regs[AF].ZFLAG = ( z80.regs[BC].H == 0 );
					z80.regs[AF].NFLAG = 1;
					_Z80_ITS(16,2,"OUTD");
					break;
						
		case 0xA3:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L);
					z80.write_io( z80.regs[BC].REG16 );
					z80.regs[HL].REG16++; z80.regs[BC].H--;
					z80.regs[AF].ZFLAG = ( z80.regs[BC].H == 0 );
					z80.regs[AF].NFLAG = 1;
					_Z80_ITS(16,2,"OUTI");
					break;
		

		case 0xAA:	z80.read_io( z80.regs[BC].REG16, &z80.regs[WZ].L);
					_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L);
					z80.regs[HL].REG16--; z80.regs[BC].H--;
					z80.regs[AF].ZFLAG = ( z80.regs[BC].H == 0 );
					z80.regs[AF].NFLAG = 1;
					_Z80_ITS(16,2,"IND");
					break;
						
		case 0xA2:	z80.read_io( z80.regs[BC].REG16, &z80.regs[WZ].L);
					_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L);
					z80.regs[HL].REG16++; z80.regs[BC].H--;
					z80.regs[AF].ZFLAG = ( z80.regs[BC].H == 0 );
					z80.regs[AF].NFLAG = 1;
					_Z80_ITS(16,2,"INI");
					break;
					
		case 0xBA:	z80.read_io( z80.regs[BC].REG16, &z80.regs[WZ].L);
					_Z80_WRITE_BYTE(z80.regs[HL].REG16--, z80.regs[WZ].L);
					z80.regs[HL].REG16--; z80.regs[BC].H--;
					z80.regs[AF].NFLAG = 1;
					z80.regs[AF].ZFLAG = ( z80.regs[BC].H == 0 );
					if ( z80.regs[BC].H != 0 ) {
						z80.regs[PC].REG16 -= 2;
						_Z80_ITS(21,2,"INDR");
					}
					else {
						_Z80_ITS(16,2,"INDR");
					}
					break;

		case 0xB2:	z80.read_io( z80.regs[BC].REG16, &z80.regs[WZ].L);
					_Z80_WRITE_BYTE( z80.regs[HL].REG16--, z80.regs[WZ].L);
					z80.regs[HL].REG16++; z80.regs[BC].H--;
					z80.regs[AF].NFLAG = 1;
					z80.regs[AF].ZFLAG = ( z80.regs[BC].H == 0 );
					if ( z80.regs[BC].H != 0 ) {
						z80.regs[PC].REG16 -= 2;
						_Z80_ITS(21,2,"INIR");
					}
					else {
						_Z80_ITS(16,2,"INIR");
					}
					break;
										
		case 0x4B:	_Z80_FETCH_WORD; _Z80_READ_REG16( z80.regs[WZ].REG16, BC); _Z80_ITS_1(20,4,"LD BC,(%04Xh)",z80.regs[WZ].REG16); break; 
		case 0x5B:	_Z80_FETCH_WORD; _Z80_READ_REG16( z80.regs[WZ].REG16, DE); _Z80_ITS_1(20,4,"LD DE,(%04Xh)",z80.regs[WZ].REG16); break; 
		case 0x6B:	_Z80_FETCH_WORD; _Z80_READ_REG16( z80.regs[WZ].REG16, HL); _Z80_ITS_1(20,4,"LD HL,(%04Xh)",z80.regs[WZ].REG16); break; 
		case 0x7B:	_Z80_FETCH_WORD; _Z80_READ_REG16( z80.regs[WZ].REG16, SP); _Z80_ITS_1(20,4,"LD SP,(%04Xh)",z80.regs[WZ].REG16); break; 
		
		case 0x43:	_Z80_FETCH_WORD; _Z80_WRITE_REG16( z80.regs[WZ].REG16, BC); _Z80_ITS_1(20,4,"LD (%04Xh),BC",z80.regs[WZ].REG16); break; 
		case 0x53:	_Z80_FETCH_WORD; _Z80_WRITE_REG16( z80.regs[WZ].REG16, DE); _Z80_ITS_1(20,4,"LD (%04Xh),DE",z80.regs[WZ].REG16); break; 
		case 0x63:	_Z80_FETCH_WORD; _Z80_WRITE_REG16( z80.regs[WZ].REG16, HL); _Z80_ITS_1(20,4,"LD (%04Xh),HL",z80.regs[WZ].REG16); break; 
		case 0x73:	_Z80_FETCH_WORD; _Z80_WRITE_REG16( z80.regs[WZ].REG16, SP); _Z80_ITS_1(20,4,"LD (%04Xh),SP",z80.regs[WZ].REG16); break; 
		
		case 0x57:	z80.regs[AF].H = z80.regs[IR].H; NX = 0; HX = 0; SX = (z80.regs[AF].H >> 7); ZX = (z80.regs[AF].H == 0); PX = z80.status.IFF2; _Z80_ITS(9,2,"LD A,I"); break;    
		case 0x47:	z80.regs[IR].H = z80.regs[AF].H; _Z80_ITS(9,2,"LD I,A"); break;
		case 0x5F:	z80.regs[AF].H = z80.regs[IR].L; NX = 0; HX = 0; SX = (z80.regs[AF].H >> 7); ZX = (z80.regs[AF].H == 0); PX = z80.status.IFF2; _Z80_ITS(9,2,"LD A,R"); break;    
		case 0x4F:	z80.regs[IR].L = z80.regs[AF].H; _Z80_ITS(9,2,"LD R,A"); break;
		    
		case 0xA8:	_Z80_READ_BYTE( z80.regs[HL].REG16--, z80.regs[WZ].L);
					_Z80_WRITE_BYTE(z80.regs[DE].REG16--, z80.regs[WZ].L);
					z80.regs[BC].REG16--;
					HX = 0 ; NX = 0;
					PX = ( z80.regs[BC].REG16 != 0 );
					_Z80_ITS(16,2,"LDD");
					break;
		
		case 0xB8:	_Z80_READ_BYTE( z80.regs[HL].REG16--, z80.regs[WZ].L);
					_Z80_WRITE_BYTE(z80.regs[DE].REG16--, z80.regs[WZ].L);
					z80.regs[BC].REG16--;
					_Z80_ITS(16,2,"LDDR");
					z80.regs[AF].HFLAG = 0 ; z80.regs[AF].NFLAG = 0; z80.regs[AF].PFLAG = ( z80.regs[BC].REG16 != 0 );
					if ( z80.regs[BC].REG16 != 0 ) { _Z80_ITS(21,2,"LDDR"); z80.regs[PC].REG16 -= 2; }
					break;
					
		case 0xA0:	_Z80_READ_BYTE( z80.regs[HL].REG16++, z80.regs[WZ].L);
					_Z80_WRITE_BYTE(z80.regs[DE].REG16++, z80.regs[WZ].L);
					z80.regs[BC].REG16--;
					z80.regs[AF].HFLAG = 0 ; z80.regs[AF].NFLAG = 0;
					z80.regs[AF].PFLAG = ( z80.regs[BC].REG16 != 0 );
					_Z80_ITS(16,2,"LDI");
					break;
		
		case 0xB0:	_Z80_READ_BYTE( z80.regs[HL].REG16++, z80.regs[WZ].L);
					_Z80_WRITE_BYTE(z80.regs[DE].REG16++, z80.regs[WZ].L);
					z80.regs[BC].REG16--;
					_Z80_ITS(16,2,"LDIR");
					z80.regs[AF].HFLAG = 0 ; z80.regs[AF].NFLAG = 0; z80.regs[AF].PFLAG = ( z80.regs[BC].REG16 != 0 );
					if ( z80.regs[BC].REG16 != 0 ) { _Z80_ITS(21,2,"LDIR"); z80.regs[PC].REG16 -= 2; }
					break;
					
		case 0xBB:	_Z80_READ_BYTE( z80.regs[HL].REG16,z80.regs[WZ].L);
					z80.write_io( z80.regs[BC].REG16 );
					z80.regs[BC].H--;
					z80.regs[HL].REG16--;
					z80.regs[AF].NFLAG = 1;
					z80.regs[AF].ZFLAG = ( z80.regs[BC].H == 0 );
					if ( z80.regs[BC].H == 0 ) {
						_Z80_ITS(16,2,"OTDR");
					}
					else {
						_Z80_ITS(21,2,"OTDR");
						z80.regs[PC].REG16 -= 2;
					}
					break;
		
		case 0xB3:	_Z80_READ_BYTE(z80.regs[HL].REG16, z80.regs[WZ].L);
					z80.write_io( z80.regs[BC].REG16 );
					z80.regs[BC].H--;
					z80.regs[HL].REG16++;
					z80.regs[AF].NFLAG = 1;
					z80.regs[AF].ZFLAG = ( z80.regs[BC].H == 0 );
					if ( z80.regs[BC].H == 0 ) {
						_Z80_ITS(16,2,"OTIR");
					}
					else {
						_Z80_ITS(21,2,"OTIR");
						z80.regs[PC].REG16 -= 2;
					}
					break;
				
		case 0x44:	NX = 1; HX = ( (z80.regs[AF].H&0x0F) > 0 );
					PX = ( z80.regs[AF].H == 0x80 );	          
					ZX = GET_ZFLAG( z80.regs[AF].H );
					SX = GET_SFLAG( z80.regs[AF].H );
					CX = ( z80.regs[AF].H != 0x00 );
					YX = GET_YFLAG( z80.regs[AF].H );
					XX = GET_XFLAG( z80.regs[AF].H );
					z80.regs[AF].H = 0 - z80.regs[AF].H;
					 _Z80_ITS(8,2,"NEG"); break;
			
			
		case 0x4D:	_Z80_POP_REG16(PC); _Z80_ITS(14,2,"RETI"); break;
		case 0x45:	_Z80_POP_REG16(PC); z80.status.IFF1 = z80.status.IFF2; _Z80_ITS(14,2,"RETN"); break;
		
		case 0x67:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L);
					z80.regs[WZ].H = z80.regs[AF].H;
					z80.regs[AF].H = (uint8_t)(z80.regs[AF].H & 0xF0) | (uint8_t)( z80.regs[WZ].L & 0x0F ); 
					z80.regs[WZ].L = (uint8_t)( (uint8_t)z80.regs[WZ].L >> 4 ) | (uint8_t)( z80.regs[WZ].H << 4 );
					_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L);
					NX = 0;
					HX = 0;	          
					PX = z80_alu_check_parity(z80.regs[AF].H);
					z80.regs[AF].ZFLAG = ( z80.regs[AF].H == 0 );
					z80.regs[AF].SFLAG = ( z80.regs[AF].H >> 7 ); 
					_Z80_ITS(18,2,"RRD");
					break;
					
		case 0x6F:	_Z80_READ_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L);
					z80.regs[WZ].H = z80.regs[AF].H;
					z80.regs[AF].H = (z80.regs[AF].H & 0xF0) | ( z80.regs[WZ].L >> 4 ); 
					z80.regs[WZ].L = ( z80.regs[WZ].L << 4 ) | ( z80.regs[WZ].H & 0x0F );
					_Z80_WRITE_BYTE( z80.regs[HL].REG16, z80.regs[WZ].L);
					z80.regs[AF].NFLAG = 0;
					z80.regs[AF].HFLAG = 0;	          
					z80.regs[AF].PFLAG = z80_alu_check_parity(z80.regs[AF].H);
					z80.regs[AF].ZFLAG = ( z80.regs[AF].H == 0 );
					z80.regs[AF].SFLAG = ( z80.regs[AF].H >> 7 ); 
					_Z80_ITS(18,2,"RLD");
					break;
								
					
					
		default: z80_error(ERROR_UNKNOWN_OPCODE); break;
	}

}
