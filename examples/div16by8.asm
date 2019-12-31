; Extracted from the Z80 book ( Rodnay Zaks )
; Modified by Cesar Lombao for this case

; Integer Division 16 bits by 8 bits
; HL --> 16 bits value
; A  --> 8 bits value
; Result stored in HL ( HL / A )
		
	LD D,A
	LD E,0	
	LD B,8
    
DIV:	XOR A
	SBC HL,DE
	INC HL
	JP P,NOADD
	ADD HL,DE
	DEC HL
	
NOADD:	ADD HL,HL
	DJNZ DIV

	HALT
