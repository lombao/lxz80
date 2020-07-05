;       Copyright (C) 2015
;       Rojas Hernandez Miguel Alejandro <>
;       Oropeza Vilchis Luis Alberto <vilchissfi@gmail.com>
;
;       This program is free software: you can redistribute it and/or modify
;       it under the terms of the GNU General Public License as published by
;       the Free Software Foundation, either version 3 of the License, or
;	(at your option) any later version.
;
;	This program is distributed in the hope that it will be useful,
;	but WITHOUT ANY WARRANTY; without even the implied warranty of
;	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;	GNU General Public License for more details.
;
;	You should have received a copy of the GNU General Public License
;	along with this program.  If not, see <http://www.gnu.org/licenses/>.

;   https://github.com/mikeandblak/Ensamblador-Z80/blob/master/Fibonacci%20recursivo/fib.asm

;  Some modifications. Cesar Lombao
;  A contains the fibonacci sequence number to be calculated
;  D will hold the resut
;
; You can compile it with
;     lxzasm fib.asm
; and run it with
;     lxzrun -A 5 a.z80
; You will see that the D register contains the value 3
        	
        CP 0
        JR Z,FIN
        LD D,0
        LD B,A
        CALL FIBONACCI
FIN:    HALT

FIBONACCI: LD A,B
           CP 2
           JP Z,SUMAR
           CP 1
           JP Z,REGRESAR
           DEC B
           PUSH BC
           CALL FIBONACCI
           POP BC
           DEC B
           CALL FIBONACCI
REGRESAR: RET
SUMAR: INC D
       JP REGRESAR
