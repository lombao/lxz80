 .title "This is a basic test"
ORG 100H

LD HL,1000
LD (HL),A  ; Load A content into memory address pointed by HL
LD B,(HL)
HALT

