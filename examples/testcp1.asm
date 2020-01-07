; This is a basic test of the  CP command
; to check the CP command and the flags
; It will do a CP H With A=0 and H=57
; the result it 0x93 in the FLAGS Register

 	LD BC,0
	PUSH BC
	POP AF
	LD A,0x00
	LD H,0x57
	CP H
	HALT

