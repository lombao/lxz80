%{

#include <stdio.h>
#include <string.h>


#include "grammar.h"


/* Externally defined functions used here */
extern void fatalError(const char *str);


/* Declarations of locally defined functions */
void reset_lexer();
int from_binary(const char * s);


/*****************************/
/* Locally defined functions */
void reset_lexer() { YY_FLUSH_BUFFER;  yylineno = 1; }

int from_binary(const char * s) {
 char aux[60];
 
  if (strlen(s) > 59) { fatalError("Binary is too long"); }  
  strncpy(aux,s,strlen(s)); aux[strlen(s)] = 0x0;
  if (aux[strlen(aux)-1] == 'B' || aux[strlen(aux)-1] == 'b') {
     aux[strlen(aux)-1] = 0x0;
  }
  return (int) strtol(aux, NULL, 2);

}

int from_hexa(const char * s) {
 char aux[60];

  if (strlen(s) > 59) { fatalError("Hexadecimal number is too long"); }   
  strncpy(aux,s,strlen(s)); aux[strlen(s)] = 0x0;
  if (aux[strlen(aux)-1] == 'H' || aux[strlen(aux)-1] == 'h') {
     aux[strlen(aux)-1] = 0x0;
  }
  return (int) strtol(aux, NULL, 16);

}


%}

%option nounput
%option noinput

%%
[ \t]+                /* eat up whitespace */
\'.\'                   { yylval.normal = yytext[1]; return CHAR; }
\".\"                   { yylval.normal = yytext[1]; return CHAR; }
\"[^\n\"]*\"          {  strncpy(yylval.literal,yytext+1,strlen(yytext)-1); yylval.literal[strlen(yytext)-2]=0x0;return STRING; }
'[^\n']+'             {  strncpy(yylval.literal,yytext+1,strlen(yytext)-1); yylval.literal[strlen(yytext)-2]=0x0;return STRING; }
\.BYTE                { return DEFB; }
IF                    { return IF; }
IFDEF                 { return IFDEF; }
IFNDEF                { return IFNDEF; }
ENDIF                 { return ENDIF; }
NE                    { return NEQUAL;  }
!=                    { return NEQUAL;  }
==                    { return EQUAL; }
GE                    { return GREATEREQ; }
>=                    { return GREATEREQ; }
GT                    { return GREATERTHAN; }
>                     { return GREATERTHAN; }
\<                     { return LESSTHAN;    }
\<=                    { return LESSEQ; }
LT                    { return LESSTHAN; }
LE                    { return LESSEQ; } 
\.EQU                 { return EQU;  }
\.DB                  { return DEFB; }
\.DS                  { return DEFS; }
\.DW                  { return DEFW; }
\.DM                  { return DEFB; }
\.DD                  { return DEFD; }
\.DEFM                { return DEFB; }
\.DEFB                { return DEFB; }
\.DEFD                { return DEFD; }
\.DEFS                { return DEFS; }
\.DEFW                { return DEFW; }
DEFINED               { return DEFINED; }
defined			{ return DEFINED; }
DEFB                  { return DEFB; }
defb			{ return DEFB; }
DEFS                  { return DEFS; }
defs			{ return DEFS; }
DEFM                  { return DEFB; }
defm			{ return DEFB; }
DEFW                  { return DEFW; }
defw			{ return DEFW; }
DEFC                  { return DEFC; }
defc			{ return DEFC; }
DB                    { return DEFB; }
db			{ return DEFB; }
DS                    { return DEFS; }
ds			{ return DEFS; }
DM                    { return DEFB; }
dm			{ return DEFB; }
DW                    { return DEFW; }
dw			{ return DEFW; }
DD                    { return DEFD; }
dd			{ return DEFD; }
ERROR                 { return ERROR; }
ALIGN                 { return ALIGN; }
align			{ return ALIGN; }
DJNZ			{ return DJNZ; }
djnz			{ return DJNZ; }
CALL                  { return CALL; }
call			{ return CALL; }
OTDR                  { return OTDR; }
otdr			{ return OTDR; }
OTIR                  { return OTIR; }
otir			{ return OTIR; }
OUTI                  { return OUTI; }
outi			{ return OUTI; }
OUTD                  { return OUTD; }
outd			{ return OUTD; }
INDR                  { return INDR; }
indr			{ return INDR; }
CPDR                  { return CPDR; }
cpdr			{ return CPDR; }
CPIR                  { return CPIR; }
cpir			{ return CPIR; }
INIR                  { return INIR; }
inir			{ return INIR; }
HALT                  { return HALT; }
halt			{ return HALT; }
LDDR                  { return LDDR; }
lddr			{ return LDDR; }
LDIR                  { return LDIR; }
ldir			{ return LDIR; }
PUSH                  { return PUSH; }
push			{ return PUSH; }
RETI                  { return RETI; }
reti			{ return RETI; }
RETN                  { return RETN; }
retn			{ return RETN; }
RLCA                  { return RLCA; }
rlca			{ return RLCA; }
RRCA                  { return RRCA; }
rrca			{ return RRCA; }
DEC                   { return DEC; }
dec			{ return DEC; }
END       		{ return END; }
end			{ return END; }
EQU                   { return EQU; }
equ			{ return EQU; }
IYH                   { return IYH; }
iyh			{ return IYH; }
IYL                   { return IYL; }
iyl			{ return IYL; }
IXH                   { return IXH; }
ixh			{ return IXH; }
IXL                   { return IXL; }
ixl			{ return IXL; }
SUB                   { return SUB; }
sub			{ return SUB; }
SRL                   { return SRL; }
srl			{ return SRL; }
SRA                   { return SRA; }
sra			{ return SRA; }
SLA                   { return SLA; }
sla			{ return SLA; }
SLL                   { return SLL; }
sll			{ return SLL; }
SET                   { return SET; }
set			{ return SET; }
SCF                   { return SCF; }
scf			{ return SCF; }
SBC                   { return SBC; }
sbc			{ return SBC; }
RST                   { return RST; }
rst			{ return RST; }
RRD                   { return RRD; }
rrd			{ return RRD; }
RRA                   { return RRA; }
rra			{ return RRA; }
RRC                   { return RRC; }
rrc			{ return RRC; }
RLA                   { return RLA; }
rla			{ return RLA; }
RLC                   { return RLC; }
rlc			{ return RLC; }
RLD                   { return RLD; }
rld			{ return RLD; }
POP                   { return POP; }
pop			{ return POP; }
CPD                   { return CPD; }
cpd			{ return CPD; }
CPI                   { return CPI; }
cpi			{ return CPI; }
LDI                   { return LDI; }
ldi			{ return LDI; }
LDD                   { return LDD; }
ldd			{ return LDD; }
CPL                   { return CPL; }
cpl			{ return CPL; }
DAA                   { return DAA; }
daa			{ return DAA; }
OUT                   { return OUT; }
out			{ return OUT; }
AND			 { return AND; }
and			{ return AND; }
ADC			 { return ADC; }
adc			{ return ADC; }
ADD                   { return ADD; }
add			{ return ADD; }
BIT                   { return BIT; }
bit			{ return BIT; }
CCF                   { return CCF; }
ccf			{ return CCF; }
RET			{ return RET; }
ret			{ return RET; }
EXX                   { return EXX; }
exx			{ return EXX; }
XOR                   { return XOR; }
xor			{ return XOR; }
INC                   { return INC; }
inc			{ return INC; }
IND                   { return IND; }
ind			{ return IND; }
INI                   { return INI; }
ini			{ return INI; }
NEG                   { return NEG; }
neg			{ return NEG; }
NOP                   { return NOP; }
nop			{ return NOP; }
RES                   { return RES; }
res			{ return RES; }
AF'                   { return AFPLUS; }
af'			{ return AFPLUS; }
RL                    { return RL; }
rl			{ return RL; }
RR                    { return RR; }
rr			{ return RR; }
LD			{ return LD; }
ld			{ return LD; }
OR			{ return OR; }
or			{ return OR; }
JP			{ return JP; }
jp			{ return JP; }
JR			{ return JR; }
jr			{ return JR; }
AF                    { return AF; }
af			{ return AF; }
BC			{ return BC; }
bc			{ return BC; }
DE			 { return DE; }
de			{ return DE; }
HL			{ return HL; }
hl			{ return HL; }
SP			{ return SP; }
sp			{ return SP; }
IX                    { return IX; }
ix			{ return IX; }
IY                    { return IY; }
iy			{ return IY; }
DI                    { return DI; }
di			{ return DI; }
EI                    { return EI; }
ei			{ return EI; }
EX                    { return EX; }
ex			{ return EX; }
CP                    { return CP; }
cp			{ return CP; }
NZ                    { return NZ; }
nz			{ return NZ; }
NC                    { return NC; }
nc			{ return NC; }
PO                    { return PO; }
po			{ return PO; }
PE                    { return PE; }
pe			{ return PE; }
IM                    { return IM; }
im			{ return IM; }
IN                    { return IN; }
in			{ return IN; }
Z                     { return Z; }
z			{ return Z; }
P                     { return P; }
p			{ return P; }
M                     { return M; }
m			{ return M; }
A                     { return A; }
a			{ return A; }
B                     { return B; }
b			{ return B; }
C                     { return C; }
c			{ return C; }
D                     { return D; }
d			{ return D; }
E                     { return E; }
e			{ return E; }
H                     { return H; }
h			{ return H; }
L                     { return L; }
l			{ return L; }
R			{ return R; }
r			{ return R; }
I                     { return I; }
i			{ return I; }
F                     { return F; }
f			{ return F; }
[A-Za-z][A-Za-z0-9_]*:  { strncpy(yylval.literal,yytext,strlen(yytext)); yylval.literal[strlen(yytext)-1]=0x0;return LABEL; }
\.[A-Za-z][A-Za-z0-9_]* { strncpy(yylval.literal,yytext+1,strlen(yytext)-1); yylval.literal[strlen(yytext)-1]=0x0;return LABEL; }
\%[0-1]+              { yylval.normal = from_binary(yytext+1); return INTEGER; }
#([A-F0-9]){1,4}        { yylval.normal = from_hexa(yytext+1); return INTEGER; }
$[A-F0-9]+            { yylval.normal = from_hexa(yytext+1); return INTEGER; }
&[A-F0-9]+            { yylval.normal = from_hexa(yytext+1); return INTEGER; }
[A-F0-9]+H            { yylval.normal = from_hexa(yytext); return INTEGER;  }
[A-F0-9]+h            { yylval.normal = from_hexa(yytext); return INTEGER;  }
[A-Za-z][A-Za-z0-9_]* { strcpy(yylval.literal,yytext); return LITERAL; }
[0-9]+     			  { yylval.normal = atoi(yytext); return INTEGER; }
[0-1]+B               { yylval.normal = from_binary(yytext); return INTEGER;  }
@[0-1]+               { yylval.normal = from_binary(yytext+1); return INTEGER;  }
0x[A-F0-9]+           { yylval.normal = from_hexa(yytext+2); return INTEGER; }
[\n]                  { return NEWLINE; }
\-                    { return MINUS; }
,       			  { return COMMA; }
\(					  { return PARLEFT; }
\) 					  { return PARRIGHT; }
\[					  { return PARLEFT; }
\] 					  { return PARRIGHT; }
\+                    { return PLUS; }
\*                    { return MULT; }
\&                    { return BITAND; }
\&\&                  { return AND; }
\|                    { return BITOR;  }
\|\|                  { return OR;  }
\<\<                  { return OPSHLF; }
\>\>                  { return OPSHRT; }
\/                    { return DIVIDE; }
\$                    { return DOLAR;  }
=                     { return EQUAL;  }
!                     { return EXCLAMATION; }

%%

