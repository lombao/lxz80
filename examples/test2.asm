 .title "Basic test Number 2"

LD HL,1000
LD (HL),A  ; Load A content into memory address pointed by HL
CP 20
LABEL: LD B,A
LD B,(HL)
HALT

