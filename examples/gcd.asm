; From the rosettacode.org
; https://rosettacode.org/wiki/Greatest_common_divisor#Z80_Assembly

; Greatest Common Divisor
; Inputs: a, b
; Outputs: a = gcd(a, b)
; Destroys: c
; Assumes: a and b are positive one-byte integers

; You can test it like
;   - lxzasm gcd.asm
;   - lxzrun -A 6 -B 3 a.out
;     the result stored in A should be obviously 3

call gcd
halt

gcd:
    cp b
    ret z                   ; while a != b
 
    jr c, else              ; if a > b
 
    sub b                   ; a = a - b
 
    jr gcd
   
 
else:
    ld c, a                 ; Save a
    ld a, b                 ; Swap b into a so we can do the subtraction
    sub c                   ; b = b - a
    ld b, a                 ; Put a and b back where they belong
    ld a, c 
    jr gcd
