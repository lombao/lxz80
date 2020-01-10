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

#ifndef _Z80_HELPER_H
#define _Z80_HELPER_H

#include "z80.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* ACCESS TO RAM */
#define _Z80_READ_RAM(d,x)		z80.interface->type = 0; z80.interface->busaddr = d; z80.interface->io( z80.interface ); x = z80.interface->busdata;
#define _Z80_READ_BYTE(d,x)		_Z80_READ_RAM(d,x)
#define _Z80_READ_REG16(d,x) 	_Z80_READ_RAM(d, z80.regs[x].L ); _Z80_READ_RAM(d + 1, z80.regs[x].H);

#define _Z80_WRITE_RAM(d,x)		z80.interface->type = 1; z80.interface->busaddr = d; z80.interface->busdata = x; z80.interface->io( z80.interface ); 
#define _Z80_WRITE_BYTE(d,x)    _Z80_WRITE_RAM(d,x)
#define _Z80_WRITE_REG16(d,x)	_Z80_WRITE_RAM(d, z80.regs[x].L ); _Z80_WRITE_RAM(d + 1, z80.regs[x].H);

#define _Z80_FETCH_RAM(x)		_Z80_READ_RAM(z80.regs[PC].REG16++,x)
#define _Z80_FETCH_WORD   		_Z80_FETCH_RAM(z80.regs[WZ].L); _Z80_FETCH_RAM(z80.regs[WZ].H);  
#define _Z80_FETCH_BYTE	  		_Z80_FETCH_RAM(z80.regs[WZ].L);  
#define _Z80_FETCH_INST   		_Z80_FETCH_RAM(z80.status.REGINST); 
#define _Z80_FETCH_WORD_REG(x)   _Z80_FETCH_RAM(x.L); _Z80_FETCH_RAM(x.H);  

#define _Z80_PUSH_REG16(x)		_Z80_WRITE_RAM( --z80.regs[SP].REG16, z80.regs[x].H ); _Z80_WRITE_RAM( --z80.regs[SP].REG16, z80.regs[x].L )
#define _Z80_POP_REG16(x)		_Z80_READ_RAM( z80.regs[SP].REG16++, z80.regs[x].L ); _Z80_READ_RAM( z80.regs[SP].REG16++, z80.regs[x].H )

#define _Z80_ITS(x,y,z)				z80.status.ts=x; 

/* I/O */
#define _Z80_READ_IO(d,x)		z80.interface->type = 2; z80.interface->busaddr = d; z80.interface->io( z80.interface ); x = z80.interface->busdata;
#define _Z80_WRITE_IO(d)		z80.interface->type = 3; z80.interface->busaddr = d; z80.interface->io( z80.interface ); 


/*********************/

uint8_t z80_alu_check_parity( uint8_t input );


#define GET_ZFLAG(x) ( x == 0 )
#define GET_SFLAG(x) ( x >> 7 )
#define GET_YFLAG(x) ( x >> 5 )
#define GET_XFLAG(x) ( x >> 3 )



#define ALU_AND(r) z80.regs[AF].H &=r; NX = 0; HX = 1; CX = 0; PX = z80_alu_check_parity(z80.regs[AF].H); ZX = GET_ZFLAG( z80.regs[AF].H ); SX = GET_SFLAG( z80.regs[AF].H ); YX = GET_YFLAG( z80.regs[AF].H ); XX = GET_XFLAG( z80.regs[AF].H );
#define ALU_INC(r) NX = 0; HX = ( (r & 0x0F) == 0x0F);  PX = ( r == 0x7F ); r++;  ZX = GET_ZFLAG( r ); SX = GET_SFLAG( r ); YX = GET_YFLAG( r ); XX = GET_XFLAG( r );
#define ALU_DEC(r) NX = 1; HX = ( (r & 0x0F) == 0);  PX = ( r == 0x80 ); r--;  ZX = GET_ZFLAG( r ); SX = GET_SFLAG( r ); YX = GET_YFLAG( r ); XX = GET_XFLAG( r );
#define ALU_XOR(r) z80.regs[AF].H ^=r; NX = 0; HX = 0; CX = 0; PX = z80_alu_check_parity(z80.regs[AF].H); ZX = GET_ZFLAG( z80.regs[AF].H ); SX = GET_SFLAG( z80.regs[AF].H ); YX = GET_YFLAG( z80.regs[AF].H ); XX = GET_XFLAG( z80.regs[AF].H );
#define ALU_OR(r) z80.regs[AF].H |=r; NX = 0; HX = 1; CX = 0; PX = z80_alu_check_parity(z80.regs[AF].H); ZX = GET_ZFLAG( z80.regs[AF].H ); SX = GET_SFLAG( z80.regs[AF].H ); YX = GET_YFLAG( z80.regs[AF].H ); XX = GET_XFLAG( z80.regs[AF].H );
#define ALU_CP(r) NX = 1; HX = ( ( z80.regs[AF].H & 0x0F) < (r & 0x0F) ); CX = ( z80.regs[AF].H < r ); PX = ( ((z80.regs[AF].H >> 7)  ^ (r >> 7)) && ( z80.regs[AF].H < r )    ); ZX = (z80.regs[AF].H == r); SX = GET_SFLAG( (z80.regs[AF].H - r)  );  YX = GET_YFLAG( (z80.regs[AF].H - r ) );  XX = GET_XFLAG( (z80.regs[AF].H - r ) );		

#define ALU_SET(r,b) r = (r | (1 << b))
#define ALU_BIT(r,b) HX=1; NX=0; ZX = ( (r & (1 << b) ) == 0); SX = ( b == 7 ) && ( r >> 7 ); YX = ( b == 5 ) && ( b & 0x20 ); XX =  ( b == 3 ) && ( r & 0x04 ); PX = ZX;
#define ALU_RES(r,b) r = r & (~(1 << b))

#define ALU_ADD_16(r1,r2) NX=0; CX=((uint32_t)(r1 + r2) > 0x0000FFFF); r1 += r2;
#define ALU_ADD(r)	NX = 0; HX = ( ((z80.regs[AF].H&0x0F) + (r & 0x0F)) > 0x0F ); CX = ((uint16_t)(z80.regs[AF].H + r) > 0x00FF); PX = ( (!((z80.regs[AF].H >> 7)  ^ (r >> 7))) && ( ((z80.regs[AF].H+r) >> 7) != (z80.regs[AF].H >> 7) )    ); z80.regs[AF].H += r; ZX = GET_ZFLAG( z80.regs[AF].H ); SX = GET_SFLAG( z80.regs[AF].H ); YX = GET_YFLAG( z80.regs[AF].H); XX = GET_XFLAG( z80.regs[AF].H);

#define ALU_SBC_HL(r) NX = 1; PX = ( ((z80.regs[HL].REG16 >> 15)  ^ ((uint16_t)(r+CX) >> 15)) && ( z80.regs[HL].REG16 < (uint16_t)(r+CX) ) ); YX= ( (uint32_t)z80.regs[HL].REG16 < (uint32_t)(r + CX) ); z80.regs[HL].REG16 = z80.regs[HL].REG16 - r - CX; CX = YX;	ZX=(z80.regs[HL].REG16==0); SX=(z80.regs[HL].REG16 >> 15);
						
#define ALU_SBC(r)	NX=1; HX = ( (z80.regs[AF].H&0x0F) < (r & 0x0F) ) || ( (z80.regs[AF].H&0x0F) < ( (r+CX) & 0x0F) ) ;	PX = ( ((z80.regs[AF].H >> 7)  ^ ((uint8_t)(r+CX) >> 7)) && ( z80.regs[AF].H < (uint8_t)(r+CX) ));YX = ( (uint16_t)z80.regs[AF].H < (uint16_t)(r + CX) );z80.regs[AF].H = z80.regs[AF].H - r - CX; CX = YX;	ZX = GET_ZFLAG( z80.regs[AF].H ); SX = GET_SFLAG( z80.regs[AF].H );	YX = GET_YFLAG( z80.regs[AF].H); XX = GET_XFLAG( z80.regs[AF].H);
					
#define ALU_ADC_HL(r) NX=0;	PX = ( (!((z80.regs[HL].REG16 >> 15)  ^ ((uint16_t)(r+CX) >> 15))) && ( ( (z80.regs[HL].REG16 + r + CX) >> 15) != (z80.regs[HL].REG16 >> 15) ) ); z80.regs[WZ].L = ((uint32_t)(z80.regs[HL].REG16 + r + CX) > 0x0000FFFF); z80.regs[HL].REG16 = z80.regs[HL].REG16 + r + CX ; CX = z80.regs[WZ].L; ZX=(z80.regs[HL].REG16==0); SX=(z80.regs[HL].REG16 >> 15);
	
#define ALU_ADC(r) NX=0; PX = ((!((z80.regs[AF].H >> 7)^((uint8_t)(CX)>>7)))&&(((z80.regs[AF].H+r+CX)>>7)!=(z80.regs[AF].H>>7))); HX = (((z80.regs[AF].H&0x0F)+(r&0x0F) + CX ) > 0x0F ); YX = ((uint16_t)(z80.regs[AF].H + r + CX) > 0x00FF); z80.regs[AF].H  = z80.regs[AF].H + r + CX; CX=YX; ZX = GET_ZFLAG( z80.regs[AF].H ); SX = GET_SFLAG( z80.regs[AF].H );	YX = GET_YFLAG( z80.regs[AF].H); XX = GET_XFLAG( z80.regs[AF].H);

#define ALU_SUB(r) NX=1; PX=(((z80.regs[AF].H>>7)^(r>>7))&&( z80.regs[AF].H<r)); HX=((z80.regs[AF].H&0x0F)<(r&0x0F)); CX = ( z80.regs[AF].H < r ); z80.regs[AF].H  -= r; ZX = GET_ZFLAG( z80.regs[AF].H ); SX = GET_SFLAG( z80.regs[AF].H );	YX = GET_YFLAG( z80.regs[AF].H); XX = GET_XFLAG( z80.regs[AF].H);

#define ALU_SRL(r) NX =0; HX= 0; CX = ( r & 0x01 ); r = r >> 1; PX = z80_alu_check_parity(r); ZX = GET_ZFLAG(r); SX = GET_SFLAG(r); YX = GET_YFLAG(r) ; XX = GET_XFLAG(r);
				
#define ALU_SRA(r) NX=0;HX=0;CX = ( r&0x01 ); r = (r >> 1) | ( r & 0x80); PX = z80_alu_check_parity(r); ZX = GET_ZFLAG(r); SX = GET_SFLAG(r); YX = GET_YFLAG(r) ; XX = GET_XFLAG(r);
				
#define ALU_SLA(r) NX=0;HX=0;CX = r >> 7; r=(r<<1); PX = z80_alu_check_parity(r); ZX = GET_ZFLAG(r); SX = GET_SFLAG(r); YX = GET_YFLAG(r) ; XX = GET_XFLAG(r);
	
#define ALU_SLL(r) NX=0;HX=0;CX = r >> 7; r = (r << 1) + 1; PX = z80_alu_check_parity(r); ZX = GET_ZFLAG(r); SX = GET_SFLAG(r); YX = GET_YFLAG(r) ; XX = GET_XFLAG(r);
					
#define ALU_RLC(r) NX=0;HX=0;CX = r >> 7; r =(r<<1)|(r >> 7); PX = z80_alu_check_parity(r); ZX = GET_ZFLAG(r); SX = GET_SFLAG(r); YX = GET_YFLAG(r) ; XX = GET_XFLAG(r);
					
#define ALU_RRC(r) NX=0;HX=0;CX = r & 0x01; r = (r >> 1)|(r << 7); PX = z80_alu_check_parity(r); ZX = GET_ZFLAG(r); SX = GET_SFLAG(r); YX = GET_YFLAG(r) ; XX = GET_XFLAG(r);
		
#define ALU_RR(r)  NX=0;HX=0;CX = r & 0x01; r = (r >> 1)|(CX << 7); PX = z80_alu_check_parity(r); ZX = GET_ZFLAG(r); SX = GET_SFLAG(r); YX = GET_YFLAG(r) ; XX = GET_XFLAG(r);

#define ALU_RL(r)  NX=0;HX=0;CX = (r >> 7); r = (r << 1) | CX;  PX = z80_alu_check_parity(r); ZX = GET_ZFLAG(r); SX = GET_SFLAG(r); YX = GET_YFLAG(r) ; XX = GET_XFLAG(r);

	


#endif
