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
;[^\n]*\n	          { return NEWLINE; }
#[ ]+([^\n])+\n       {  return NEWLINE; } 
[ \t]+                /* eat up whitespace */
\'.\'                   { yylval.normal = yytext[1]; return CHAR; }
\".\"                   { yylval.normal = yytext[1]; return CHAR; }
\"[^\n\"]*\"          {  strncpy(yylval.literal,yytext+1,strlen(yytext)-1); yylval.literal[strlen(yytext)-2]=0x0;return STRING; }
'[^\n']+'             {  strncpy(yylval.literal,yytext+1,strlen(yytext)-1); yylval.literal[strlen(yytext)-2]=0x0;return STRING; }
\.BYTE                { return DEFB; }
\.TITLE               { return TITLE; }
TITLE                 { return TITLE; }
FNAME                 { return FNAME; }
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
\.ORG                 { return ORG; }
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
DEFB                  { return DEFB; }
DEFS                  { return DEFS; }
DEFM                  { return DEFB; }
DEFW                  { return DEFW; }
DEFC                  { return DEFC; }
DB                    { return DEFB; }
DS                    { return DEFS; }
DM                    { return DEFB; }
DW                    { return DEFW; }
DD                    { return DEFD; }
ERROR                 { return ERROR; }
INCLUDE               { return INCLUDE; }
INCBIN                { return INCLUDEBIN;  }
INCLUDEBIN            { return INCLUDEBIN;  }
NOLIST                { return NOLIST; }
LIMIT                 { return LIMIT; }
ALIGN                 { return ALIGN; }
DJNZ				  { return DJNZ; }
ASEG                  { return ASEG; }
CALL                  { return CALL; }
OTDR                  { return OTDR; }
OTIR                  { return OTIR; }
OUTI                  { return OUTI; }
OUTD                  { return OUTD; }
INDR                  { return INDR; }
CPDR                  { return CPDR; }
CPIR                  { return CPIR; }
INIR                  { return INIR; }
HALT                  { return HALT; }
LDDR                  { return LDDR; }
LDIR                  { return LDIR; }
PUSH                  { return PUSH; }
RETI                  { return RETI; }
RETN                  { return RETN; }
RLCA                  { return RLCA; }
RRCA                  { return RRCA; }
DEC                   { return DEC; }
END       			  { return END; }
ORG                   { return ORG; }
EQU                   { return EQU; }
IYH                   { return IYH; }
IYL                   { return IYL; }
IXH                   { return IXH; }
IXL                   { return IXL; }
SUB                   { return SUB; }
SRL                   { return SRL; }
SRA                   { return SRA; }
SLA                   { return SLA; }
SLL                   { return SLL; }
SLS                   { return SLL; }
SET                   { return SET; }
SCF                   { return SCF; }
SBC                   { return SBC; }
RST                   { return RST; }
RRD                   { return RRD; }
RRA                   { return RRA; }
RRC                   { return RRC; }
RLA                   { return RLA; }
RLC                   { return RLC; }
RLD                   { return RLD; }
POP                   { return POP; }
CPD                   { return CPD; }
CPI                   { return CPI; }
LDI                   { return LDI; }
LDD                   { return LDD; }
CPL                   { return CPL; }
DAA                   { return DAA; }
OUT                   { return OUT; }
AND					  { return AND; }
ADC					  { return ADC; }
ADD                   { return ADD; }
BIT                   { return BIT; }
CCF                   { return CCF; }
RET					  { return RET; }
EXX                   { return EXX; }
XOR                   { return XOR; }
INC                   { return INC; }
IND                   { return IND; }
INI                   { return INI; }
NEG                   { return NEG; }
NOP                   { return NOP; }
RES                   { return RES; }
AF'                   { return AFPLUS; }
RL                    { return RL; }
RR                    { return RR; }
LD       			  { return LD; }
OR                    { return OR; }
JP                    { return JP; }
JR                    { return JR; }
AF                    { return AF; }
BC					  { return BC; }
DE					  { return DE; }
HL					  { return HL; }
SP					  { return SP; }
IX                    { return IX; }
IY                    { return IY; }
DI                    { return DI; }
EI                    { return EI; }
EX                    { return EX; }
CP                    { return CP; }
NZ                    { return NZ; }
NC                    { return NC; }
PO                    { return PO; }
PE                    { return PE; }
IM                    { return IM; }
IN                    { return IN; }
Z                     { return Z; }
P                     { return P; }
M                     { return M; }
A                     { return A; }
B                     { return B; }
C                     { return C; }
D                     { return D; }
E                     { return E; }
H                     { return H; }
L                     { return L; }
R					  { return R; }
I                     { return I; }
F                     { return F; }
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

