%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "defs.h"
 
int yyparse();
int yylex();

void includebin(const char * includefile);

extern int setLabelAddress(const char * label, const int pc);
extern int setLabelValue(const char * label, const int val);
extern int LookupTableLabels(const char * label);
extern void labelUndefinedError(const char * label);
extern void warningError(const char *str);
extern void fatalError(const char *str);
extern int getLabelValue(const char * label, uint * k);
extern int outCode( int num, ... );
extern void outDirective();
extern void includebinTooBigError(const char * includefile);
void directiveError(const char * msg);


extern void yyerror(const char *str);
extern int yylineno;
extern int pc;
extern int previouspc;
extern int pass;
extern int condStatus;


char msg[200];
uint k;
uint a;
uint8_t * p;

int yywrap()
{
        return 1;
} 
  
  
void includebin(const char * includefile) {
 FILE * fi;
 uint8_t buffer[MAX_SIZE_CODE_LINE];
 uint16_t nbread;
 int a;
        
     if ( !condStatus ) { return; }
     
        fi = fopen(includefile, "r");
		if (fi == NULL) { perror("ERROR INCLUDE:"); exit(1); }
        nbread = fread(buffer, sizeof(char), MAX_SIZE_CODE_LINE, fi);
        if ( nbread == MAX_SIZE_CODE_LINE ) { includebinTooBigError(includefile); }
        for(a=0;a<nbread;a++) { outCode(1,buffer[a]); }       
        fclose(fi);
        
}


%}


%union {
  uint32_t normal;
  uint8_t byte;
  uint16_t word;
  uint16_t address;
  uint8_t * listexpr;
  char literal[64];
  }


%error-verbose

%token DEFB DEFS DEFW DEFC DEFD
%token PLUS MINUS MULT DIVIDE
%token GREATERTHAN GREATEREQ LESSTHAN LESSEQ
%token BITOR BITAND
%token OPSHLF OPSHRT
%token PARRIGHT PARLEFT
%token EXCLAMATION
%token NEQUAL EQUAL
%token IF IFDEF IFNDEF ENDIF
%token FNAME
%token INCLUDE
%token INCLUDEBIN
%token DEFINED
%token NEWLINE
%token ERROR
%token DOLAR
%token ALIGN
%token COMMA
%token ASEG
%token <byte> CHAR
%token LDDR
%token CALL
%token RRCA
%token OTDR
%token OTIR
%token OUTI
%token OUTD
%token RETI
%token RETN
%token PUSH
%token END
%token EQU
%token DEC
%token AND
%token SBC
%token OUT
%token ADC
%token LDD
%token LDI
%token ADD
%token RRA
%token RRC
%token SRA
%token SRL
%token SLL
%token RRD
%token POP
%token CCF
%token RET
%token XOR
%token BIT
%token SCF
%token NOP
%token SET
%token JP
%token DJNZ
%token HALT
%token INDR
%token INIR
%token IND
%token LDIR
%token SLA
%token NEG
%token LD
%token AF HL SP BC DE IX IY
%token IXH IXL IYH IYL
%token OR
%token AFPLUS
%token SUB
%token CP
%token RES
%token CPD
%token CPDR
%token CPI
%token CPIR
%token CPL
%token RLA
%token RLC
%token RLCA
%token DAA
%token RL
%token RLD
%token DI EI
%token EX
%token JR
%token RR
%token EXX
%token RST
%token IM
%token IN
%token INI
%token INC
%token NC NZ PO PE Z P M
%token A B C D E H L R I F
%token <literal> STRING
%token <literal> LITERAL
%token <literal> LABEL
%token <normal> INTEGER

%type <byte>     undocregix
%type <byte>     undocregiy
%type <byte>     reg8
%type <byte>     reg16
%type <byte>     reg16af
%type <byte>     cc
%type <byte>     ccreduced
%type <listexpr> listexpr
%type <listexpr> listexprw
%type <listexpr> listexprd
%type <normal>   expritem
%type <normal>  expr
%type <normal>  regixiy

%left AND OR
%left PLUS MINUS
%left MULT DIVIDE
%left GREATERTHAN GREATEREQ LESSTHAN LESSEQ
%left BITOR BITAND
%left OPSHLF OPSHRT
%left NEQUAL EQUAL
%left EXCLAMATION
%left UMINUS

%precedence "word"
%precedence "sequence"

%%
    program:  lines  {  }
    ;
    lines:  line         {  }
		|	lines line   {  }
		
	;
	line:  instruction   NEWLINE         { yylineno++; previouspc = pc; }
	     | LABEL instruction NEWLINE     { setLabelAddress($1,previouspc); yylineno++; previouspc = pc; }
	     | LITERAL instruction NEWLINE   { setLabelAddress($1,previouspc); yylineno++; previouspc = pc; } 
	     | NEWLINE                       { yylineno++; previouspc = pc; }
	     | LABEL NEWLINE                 { setLabelAddress($1,pc); outDirective(); yylineno++; previouspc = pc; }
   	     | LITERAL NEWLINE               { setLabelAddress($1,pc); outDirective(); yylineno++; previouspc = pc; }
         | INCLUDE STRING NEWLINE        { yylineno++; warningError("Include feature has not yet being implemented. Ignoring this line"); }
         | INCLUDE LITERAL NEWLINE       { yylineno++; warningError("Include feature has not yet being implemented. Ignoring this line"); }
         | INCLUDEBIN STRING NEWLINE     {  includebin($2); yylineno++; }
         | INCLUDEBIN LITERAL NEWLINE    {  includebin($2); yylineno++; }  
         | directive NEWLINE             {  yylineno++; previouspc = pc; }
         | LITERAL directive NEWLINE     {  setLabelAddress($1,previouspc); yylineno++; previouspc = pc; }
         | LABEL directive NEWLINE       {  setLabelAddress($1,previouspc); yylineno++; previouspc = pc; }
         | ASEG   NEWLINE                { yylineno++; /* MISSING Absolute segment directive mode. Not yet implemented */ }
         | FNAME STRING NEWLINE          { yylineno++; /* nothing happens, I've foudn this directive around, probably alias to TITLE */ }
         | IF expr NEWLINE               { yylineno++; condStatus = ($2==0)?0:1; }
         | IFDEF LITERAL NEWLINE         { yylineno++; condStatus = (LookupTableLabels($2)<0)?0:1; }
         | IFNDEF LITERAL NEWLINE        { yylineno++; condStatus = (LookupTableLabels($2)<0)?1:0; } 
         | ENDIF NEWLINE                 { if (condStatus < 0) { fatalError("Syntax error. Detected ENDIF without IF"); } condStatus = -1; yylineno++; } 
         | LABEL STRING                  { fatalError("Syntax error: I do not understand this line"); }
         | LITERAL STRING                { fatalError("Syntax error: I do not understand this line"); }
         | LABEL LITERAL                 { fatalError("Syntax error: I do not understand this line"); }
    ;
    directive:      ERROR STRING  	{ directiveError($2); }
  	               | END            { return 0; /* we should stop here compilation */}
	               | END expr  		{ return 0; /* MISSING, in order to allow entry point definition */ }
	               | directivedefb  { }
	               | directivedefs  { }
	               | directivedefw  { }
	               | directivedefc  { }
	               | directivedefd  { }
	               | LITERAL EQU expr  { setLabelValue($1,$3);  }
	               | LABEL EQU expr    { setLabelValue($1,$3);  } 
	               | ALIGN expr        { k = (((pc/$2)+1)*$2); for(a=pc; a < k; a++) { outCode(1,0x0); } }
	       
                   
    ;
	instruction: opcodeld       {  }
	           | opcodeand      {  }
	           | opcodeadc      {  }
	           | opcodeadd      {  } 
	           | opcoderet      {  }
	           | opcodedjnz     {  }
	           | opcodeout      {  }
               | opcodecall     {  }
               | opcodejp       {  }
               | opcodejr       {  }
               | opcodedec      {  }
               | opcodexor      {  }
               | opcodebit      {  }
               | opcodecp       {  }
               | opcodeex       {  }
               | opcodeim       {  }
               | opcodein       {  } 
               | opcodeinc      {  }
               | opcodeor       {  }
               | opcodepop      {  }
               | opcodepush     {  }
               | opcoderes      {  }
               | opcoderl       {  }
               | opcoderlc      {  }
               | opcoderr       {  }
               | opcoderrc      {  }
               | opcoderst      {  }
               | opcodesbc      {  }
               | opcodeset      {  }
               | opcodesla      {  }
               | opcodesra      {  } 
               | opcodesrl      {  }        
               | opcodesll      {  } 
               | opcodesub      {  }
               | CCF            { outCode(1,0x3F); }	
               | CPD            { outCode(2,0xED,0xA9); }
               | CPDR           { outCode(2,0xED,0xB9); }
               | CPI            { outCode(2,0xED,0xA1); }
               | CPIR           { outCode(2,0xED,0xB1); }
               | CPL            { outCode(1,0x2F); }
               | DAA            { outCode(1,0x27); }         
               | DI             { outCode(1,0xF3); }
               | EI             { outCode(1,0xFB); } 
               | EXX            { outCode(1,0xD9); }
               | HALT           { outCode(1,0x76); }
               | IND            { outCode(2,0xED,0xAA); }
               | INDR           { outCode(2,0xED,0xBA); }
               | INI            { outCode(2,0xED,0xA2); }
               | INIR           { outCode(2,0xED,0xB2); }
	           | LDD            { outCode(2,0xED,0xA8); }
	           | LDDR           { outCode(2,0xED,0xB8); }
	           | LDI            { outCode(2,0xED,0xA0); }
	           | LDIR           { outCode(2,0xED,0xB0); }
	           | NEG            { outCode(2,0xED,0x44); }
	           | NOP            { outCode(1,0x00);      }
	           | OTDR           { outCode(2,0xED,0xBB); }
	           | OTIR           { outCode(2,0xED,0xB3); }
	           | OUTD           { outCode(2,0xED,0xAB); }
	           | OUTI           { outCode(2,0xED,0xA3); }
	           | RETI           { outCode(2,0xED,0x4D); }
	           | RETN           { outCode(2,0xED,0x45); }
	           | RLA            { outCode(1,0x17);      }
	           | RLCA           { outCode(1,0x07);      }
	           | RLD            { outCode(2,0xED,0x6F); }
	           | RRA            { outCode(1,0x1F);      }
	           | RRCA           { outCode(1,0x0F);      }
	           | RRD            { outCode(2,0xED,0x67); }
	           | SCF            { outCode(1,0x37); }


	;
	directivedefc: DEFC LITERAL EQUAL expr   { setLabelValue($2,$4); }
	;
	directivedefs: DEFS expr                 { for(a=0;a<abs($2);a++) { outCode(1,0x0); } }
	         |     DEFS expr COMMA expr {  for(a=0;a<abs($2);a++) { outCode(1,$4); }  } 
	;
	directivedefb: DEFB listexpr       { for(a=0;a<$2[0];a++)      { outCode(1,$2[a+1]);  } }
	;
	directivedefw: DEFW listexprw      { for(a=0;a<$2[0];a++)      { outCode(1,$2[a+1]);  } }
	;
    directivedefd: DEFD listexprd      { for(a=0;a<$2[0];a++)      { outCode(1,$2[a+1]);  } }
	;
	opcodeadc: ADC A COMMA expr   { outCode(2,0xCE,$4); }
	         | ADC A COMMA reg8        { k = (($4)|128|8); outCode(1,k); }
	         | ADC A COMMA PARLEFT HL PARRIGHT { outCode(1,0x8E); }
	         | ADC A COMMA PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0x8E,$7); }
	         | ADC A COMMA PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0x8E,$7); }
	         | ADC A COMMA PARLEFT IX PARRIGHT { outCode(3,0xDD,0x8E,0); }
	         | ADC A COMMA PARLEFT IY PARRIGHT { outCode(3,0xFD,0x8E,0); } 
	         | ADC HL COMMA reg16      { k = (($4<<4)|64|8|2); outCode(2,0xED,k); } 
	         | ADC A COMMA IXH         {  outCode(2,0xDD,0x8C); }
	         | ADC A COMMA IXL         {  outCode(2,0xDD,0x8D); }
	         | ADC A COMMA IYH         {  outCode(2,0xFD,0x8C); }
	         | ADC A COMMA IYL         {  outCode(2,0xFD,0x8D); }	
	;
	opcodeadd: ADD A COMMA expr   { outCode(2,0xC6,$4); }
	         | ADD A COMMA reg8        { k = (($4)|128); outCode(1,k); }
	         | ADD A COMMA PARLEFT HL PARRIGHT { outCode(1,0x86); }
	         | ADD A COMMA PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0x86,$7); }
	         | ADD A COMMA PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0x86,$7); }
	         | ADD A COMMA PARLEFT IX PARRIGHT { outCode(3,0xDD,0x86,0); }
	         | ADD A COMMA PARLEFT IY PARRIGHT { outCode(3,0xFD,0x86,0); } 
	         | ADD HL COMMA reg16      { k = (($4<<4)|8|1); outCode(1,k); }
	         | ADD IX COMMA BC         { outCode(2,0xDD,0x09); }
	         | ADD IX COMMA DE         { outCode(2,0xDD,0x19); }
	         | ADD IX COMMA IX         { outCode(2,0xDD,0x29); }
	         | ADD IX COMMA SP         { outCode(2,0xDD,0x39); }
	         | ADD IY COMMA BC         { outCode(2,0xFD,0x09); }
	         | ADD IY COMMA DE         { outCode(2,0xFD,0x19); }
	         | ADD IY COMMA IY         { outCode(2,0xFD,0x29); }
	         | ADD IY COMMA SP         { outCode(2,0xFD,0x39); }
	         | ADD A COMMA IXH         {  outCode(2,0xDD,0x84); }
	         | ADD A COMMA IXL         {  outCode(2,0xDD,0x85); }
	         | ADD A COMMA IYH         {  outCode(2,0xFD,0x84); }
	         | ADD A COMMA IYL         {  outCode(2,0xFD,0x85); }
	;
	opcodeand: AND expr   { outCode(2,0xE6,$2); }
	         | AND reg8        { k = (($2)|128|32); outCode(1,k); }
	         | AND PARLEFT HL PARRIGHT { outCode(1,0xA6); }
	         | AND PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0xA6,$5); }
	         | AND PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0xA6,$5); }
	         | AND PARLEFT IX PARRIGHT { outCode(3,0xDD,0xA6,0); }
	         | AND PARLEFT IY PARRIGHT { outCode(3,0xFD,0xA6,0); }
	      
	         | AND IXH          { outCode(2,0xDD,0xA4); }
	         | AND IXL          { outCode(2,0xDD,0xA5); }
	         | AND IYH          { outCode(2,0xFD,0xA4); }
	         | AND IYL          { outCode(2,0xFD,0xA5); }
	         | AND A COMMA expr   { outCode(2,0xE6,$4); }
	         | AND A COMMA reg8        { k = (($4)|128|32); outCode(1,k); }
	         | AND A COMMA PARLEFT HL PARRIGHT { outCode(1,0xA6); }
	         | AND A COMMA PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0xA6,$7); }
	         | AND A COMMA PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0xA6,$7); }
	         | AND A COMMA IXH          { outCode(2,0xDD,0xA4); }
	         | AND A COMMA IXL          { outCode(2,0xDD,0xA5); }
	         | AND A COMMA IYH          { outCode(2,0xFD,0xA4); }
	         | AND A COMMA IYL          { outCode(2,0xFD,0xA5); }
	;
	opcodebit: BIT expr COMMA PARLEFT HL PARRIGHT { if ($2 > 7) { warningError("Bit number is bigger out of range, truncating"); } outCode(2,0xCB,(($2<<3)|64|6)); }
	         | BIT expr COMMA PARLEFT IX PLUS expr PARRIGHT { if ($2>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xDD,0xCB,$7, (($2<<3)|64|6)); } 
	         | BIT expr COMMA PARLEFT IY PLUS expr PARRIGHT { if ($2>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xFD,0xCB,$7, (($2<<3)|64|6)); } 
             | BIT expr COMMA reg8 { 	if ($2>7) { warningError("Bit number is bigger out of range, truncating"); }
                                            outCode(2,0xCB,(($2<<3)|$4|64));
                                        }
	;
	opcodecall: 
	            CALL expr  { outCode(3,0xCD,0x00FF&$2,(0xFF00&$2)>>8); }
	         |  CALL cc COMMA expr { outCode(3, (($2<<3)|128|64|4),0x00FF&$4,(0xFF00&$4)>>8); }                    
	;	
	opcodecp: CP expr   { outCode(2,0xFE,$2); }
	         | CP reg8        { k = (($2)|128|32|16|8); outCode(1,k); }
	         | CP PARLEFT HL PARRIGHT { outCode(1,0xBE); }
	         | CP PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0xBE,$5); }
	         | CP PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0xBE,$5); }
	         | CP PARLEFT IX PARRIGHT { outCode(3,0xDD,0xBE,0); }
	         | CP PARLEFT IY PARRIGHT { outCode(3,0xFD,0xBE,0); }
	         | CP IXH         {  outCode(2,0xDD,0xBC); }
	         | CP IXL         {  outCode(2,0xDD,0xBD); }
	         | CP IYH         {  outCode(2,0xFD,0xBC); }
	         | CP IYL         {  outCode(2,0xFD,0xBD); }
	;
	opcodedec: DEC reg8        { k = (($2<<3)|4|1); outCode(1,k); }
	         | DEC PARLEFT HL PARRIGHT { outCode(1,0x35); }
	         | DEC PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0x35,$5); }
	         | DEC PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0x35,$5); }
	         | DEC PARLEFT IX PARRIGHT { outCode(3,0xDD,0x35,0); }
	         | DEC PARLEFT IY PARRIGHT { outCode(3,0xFD,0x35,0); }
	         | DEC reg16       { k = (($2<<4)|8|2|1); outCode(1,k); }
	         | DEC IX          { outCode(2,0xDD,0x2B); }
   	         | DEC IY          { outCode(2,0xFD,0x2B); }
             | DEC IXH          { outCode(1,0xDD,0x25); }
             | DEC IXL          { outCode(1,0xDD,0x2D); }
             | DEC IYH          { outCode(1,0xFD,0x25); }
             | DEC IYL          { outCode(1,0xFD,0x2C); }

	;
	opcodedjnz: DJNZ expr		   {  outCode(2,0x10,($2 - pc - 2) ); }
	                         
	;	
    opcodeex:  EX AF COMMA AFPLUS       { outCode(1,0x08); }
             | EX DE COMMA HL           { outCode(1,0xEB); }
             | EX PARLEFT SP PARRIGHT COMMA HL           { outCode(1,0xE3); }
             | EX PARLEFT SP PARRIGHT COMMA IX           { outCode(2,0xDD,0xE3); }
             | EX PARLEFT SP PARRIGHT COMMA IY           { outCode(2,0xFD,0xE3); }
    ; 
    opcodeim:  IM expr { switch($2) {
                                case 0: outCode(2,0xED,0x46); break;
                                case 1: outCode(2,0xED,0x56); break;
                                case 2: outCode(2,0xED,0x5E); break;
                                default: fatalError("Interruption mode value is out of range: Only allowed 0, 1 or 2"); break;
                               }
                             }
    ; 
    opcodein:  IN reg8 COMMA PARLEFT C PARRIGHT { outCode(2,0xED,(($2<<3)|64)); } 
             | IN reg8 COMMA expr               { outCode(2,0xDB,$4); if ($2 != 7) { fatalError("IN only can use the A Register, sorry"); } } 
    ; 
    opcodeinc: INC reg8         { outCode(1,($2<<3)|4); }
             | INC reg16        { outCode(1,(($2<<4)|1|2));  }
             | INC PARLEFT HL PARRIGHT { outCode(1,0x34); }
             | INC PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0x34,$5); }
             | INC PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0x34,$5); }
             | INC PARLEFT IX  PARRIGHT { outCode(3,0xDD,0x34,0); }
             | INC PARLEFT IY  PARRIGHT { outCode(3,0xFD,0x34,0); }
             | INC IX           { outCode(1,0xDD,0x23); }
             | INC IY           { outCode(1,0xFD,0x23); }         
             | INC IXH          { outCode(1,0xDD,0x24); }
             | INC IXL          { outCode(1,0xDD,0x2C); }
             | INC IYH          { outCode(1,0xFD,0x24); }
             | INC IYL          { outCode(1,0xFD,0x2C); }
    ;
    opcodejp:   JP expr          { outCode(3,0xC3,0x00FF&$2,(0xFF00&$2)>>8); } 
             |  JP cc COMMA expr { outCode(3,(($2<<3)|128|64|2),0x00FF&$4,(0xFF00&$4)>>8); }             
             |  JP PARLEFT HL PARRIGHT { outCode(1,0xE9); }
             |  JP PARLEFT IX PARRIGHT { outCode(2,0xDD,0xE9); } 
             |  JP PARLEFT IY PARRIGHT { outCode(2,0xDD,0xE9); }
	;
	opcodejr:  JR ccreduced COMMA expr { outCode(2,($2<<3)|32,($4 - pc - 2)); }
	         | JR expr          { outCode(2,0x18, ($2 - pc - 2) ); }
	         | JR M COMMA expr  { fatalError("You cannot use M flag bit in JR instruction"); }
	         | JR P COMMA expr  { fatalError("You cannot use P flag bit in JR instruction"); }
	         | JR PE COMMA expr  { fatalError("You cannot use PE flag bit in JR instruction"); }
	         | JR PO COMMA expr  { fatalError("You cannot use PO flag bit in JR instruction"); }
	         
	;
	opcodeld:  LD reg8 COMMA reg8        							{ k = (($2 << 3)|64); k = k | $4; outCode(1,k); }
	         | LD reg8 COMMA PARLEFT expr PARRIGHT                  { outCode(3,0x3A,0x00FF&$5,(0xFF00&$5)>>8); if ($2 != 7) {fatalError("Only A REGISTER can be used with this syntax");} }
	         | LD reg8 COMMA expr 									{ outCode(2,(($2 << 3)|6),$4); }
	         | LD reg8 COMMA PARLEFT regixiy PLUS expr PARRIGHT 	{ outCode(3,$5,($2<<3)|64|4|2,$7); }
		     | LD reg8 COMMA PARLEFT HL PARRIGHT 					{ outCode(1,($2<<3)|64|4|2); }
	         | LD PARLEFT BC PARRIGHT COMMA A 						{ outCode(1,0x02); }
	         | LD PARLEFT DE PARRIGHT COMMA A 						{ outCode(1,0x12); }
		     | LD PARLEFT HL PARRIGHT COMMA expr 					{ outCode(2,0x36,$6); }
		     | LD PARLEFT HL PARRIGHT COMMA reg8 					{ outCode(1,$6|64|32|16); }
		     | LD PARLEFT regixiy PLUS expr PARRIGHT COMMA expr	 	{ outCode(4,$3,0x36,$5,$8); }
		     | LD PARLEFT regixiy PLUS expr PARRIGHT COMMA reg8 	{ outCode(3,$3,($8|64|32|16),$5); }
		     | LD PARLEFT regixiy MINUS expr PARRIGHT COMMA expr 	{ outCode(4,$3,0x36,$5,-$8); }
		     | LD PARLEFT regixiy MINUS expr PARRIGHT COMMA reg8 	{ outCode(3,$3,($8|64|32|16),-$5); }
		     | LD PARLEFT expr PARRIGHT COMMA A 					{ outCode(3,0x32,0x00FF&$3,(0xFF00&$3)>>8); }
		     | LD PARLEFT expr PARRIGHT COMMA BC 					{ outCode(4,0xED,43,0x00FF&$3,(0xFF00&$3)>>8); }
		     | LD PARLEFT expr PARRIGHT COMMA DE 					{ outCode(4,0xED,53,0x00FF&$3,(0xFF00&$3)>>8); }
		     | LD PARLEFT expr PARRIGHT COMMA SP 					{ outCode(4,0xED,73,0x00FF&$3,(0xFF00&$3)>>8); } 
		     | LD PARLEFT expr PARRIGHT COMMA HL 					{ outCode(3,0x22,0x00FF&$3,(0xFF00&$3)>>8); }
		     | LD PARLEFT expr PARRIGHT COMMA IX 					{ outCode(4,0xDD,0x22,0x00FF&$3,(0xFF00&$3)>>8); }
		     | LD PARLEFT expr PARRIGHT COMMA IY 					{ outCode(3,0xFD,0x22,0x00FF&$3,(0xFF00&$3)>>8); }
		     | LD reg8 COMMA PARLEFT BC PARRIGHT 					{ outCode(1,0x0A); if ($2 != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
		     | LD reg8 COMMA PARLEFT DE PARRIGHT 					{ outCode(1,0x1A); if ($2 != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
		     | LD reg8 COMMA I        								{ outCode(2,0xED,0x57); if ($2 != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
		     | LD I COMMA A           								{ outCode(2,0xED,0x47); }
		     | LD reg8 COMMA R          							{ outCode(2,0xED,0x5F); if ($2 != 7) {fatalError("Only A REGISTER can be used with this syntax");}} 
		     | LD R COMMA A           								{ outCode(2,0xED,0x4F); }
		     | LD regixiy COMMA PARLEFT expr PARRIGHT %prec UMINUS	{ outCode(4,$2,0x2A,0x00FF&$5,(0xFF00&$5)>>8); }
		     | LD regixiy COMMA expr         				        { outCode(4,$2,0x21,0x00FF&$4,(0xFF00&$4)>>8); }		      
		     | LD reg16 COMMA PARLEFT expr PARRIGHT %prec UMINUS	{ 
																		if ($2 != 2) { outCode(4,0xED,0x4B,0x00FF&$5,(0xFF00&$5)>>8); }
																		else            { outCode(3,0x2A,0x00FF&$5,(0xFF00&$5)>>8); }
																	}
			 | LD reg16 COMMA expr 									{ outCode(3,($2<<4)|1,0x00FF&$4,(0xFF00&$4)>>8); }  
	       
             | LD reg16 COMMA HL        							{ 
																		if ( $2 != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else { outCode(1,0xF9);  }
																	}		    	
		     | LD reg16 COMMA regixiy        						{
																		if ( $2 != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else  { outCode(2,$4,0xF9); }
																	}   
		     | LD reg8 COMMA undocregix  							{ 
		                                                                switch ($2) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																			case 7: outCode(2,0xDD,(5<<3)|64|$4); break;
																			default: outCode(2,0xDD,($2<<3)|64|$4); break;
																	    }
																	}                          
             | LD reg8 COMMA undocregiy   							{ switch ($2) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																		case 7: outCode(2,0xFD,(5<<3)|64|$4); break;
																		default: outCode(2,0xFD,($2<<3)|64|$4); break;
																	  }
																	}                                                                   
             | LD IXH COMMA B            { outCode(2,0xDD,0x60); }
             | LD IXH COMMA C            { outCode(2,0xDD,0x61); }
             | LD IXH COMMA D            { outCode(2,0xDD,0x62); }
             | LD IXH COMMA E            { outCode(2,0xDD,0x63); }
             | LD IXH COMMA IXH          { outCode(2,0xDD,0x64); }                            
             | LD IXH COMMA IXL          { outCode(2,0xDD,0x65); }
             | LD IXH COMMA A            { outCode(2,0xDD,0x67); }
             | LD IXL COMMA B            { outCode(2,0xDD,0x68); }
             | LD IXL COMMA C            { outCode(2,0xDD,0x69); }
             | LD IXL COMMA D            { outCode(2,0xDD,0x6A); }
             | LD IXL COMMA E            { outCode(2,0xDD,0x6B); }
             | LD IXL COMMA IXH          { outCode(2,0xDD,0x6C); }                            
             | LD IXL COMMA IXL          { outCode(2,0xDD,0x6D); }
             | LD IXL COMMA A            { outCode(2,0xDD,0x6F); }
             | LD IYH COMMA B            { outCode(2,0xFD,0x60); }
             | LD IYH COMMA C            { outCode(2,0xFD,0x61); }
             | LD IYH COMMA D            { outCode(2,0xFD,0x62); }
             | LD IYH COMMA E            { outCode(2,0xFD,0x63); }
             | LD IYH COMMA IYH          { outCode(2,0xFD,0x64); }                            
             | LD IYH COMMA IYL          { outCode(2,0xFD,0x65); }
             | LD IYH COMMA A            { outCode(2,0xFD,0x67); }
             | LD IYL COMMA B            { outCode(2,0xFD,0x68); }
             | LD IYL COMMA C            { outCode(2,0xFD,0x69); }
             | LD IYL COMMA D            { outCode(2,0xFD,0x6A); }
             | LD IYL COMMA E            { outCode(2,0xFD,0x6B); }
             | LD IYL COMMA IYH          { outCode(2,0xFD,0x6C); }                            
             | LD IYL COMMA IYL          { outCode(2,0xFD,0x6D); }
             | LD IYL COMMA A            { outCode(2,0xFD,0x6F); }
             | LD IYL COMMA expr    { outCode(2,0xFD,0x2E,$4); }
             | LD IXL COMMA expr    { outCode(2,0xDD,0x2E,$4); }
             | LD IYH COMMA expr    { outCode(2,0xFD,0x26,$4); }
             | LD IXH COMMA expr    { outCode(2,0xDD,0x26,$4); }
             | LD F COMMA expr      { fatalError("Sorry, LD option into F register is not allowed in the Z80"); }
             | LD AF COMMA expr     { fatalError("Sorry, LD option into AF register is not allowed in the Z80"); }

     ; 
 	opcodeor:  OR expr   { outCode(2,0xF6,$2); }
	         | OR reg8        { k = (($2)|128|32|16); outCode(1,k); }
	         | OR PARLEFT HL PARRIGHT { outCode(1,0xB6); }
	         | OR PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0xB6,$5); }
	         | OR PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0xB6,$5); }
	         | OR IXH          { outCode(2,0xDD,0xB4); }
	         | OR IXL          { outCode(2,0xDD,0xB5); }
	         | OR IYH          { outCode(2,0xFD,0xB4); }
	         | OR IYL          { outCode(2,0xFD,0xB5); }
	         | OR A COMMA expr   { outCode(2,0xF6,$4); }
	         | OR A COMMA reg8        { k = (($4)|128|32|16); outCode(1,k); }
	         | OR A COMMA PARLEFT HL PARRIGHT { outCode(1,0xB6); }
	         | OR A COMMA PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0xB6,$7); }
	         | OR A COMMA PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0xB6,$7); }
	         | OR A COMMA IXH          { outCode(2,0xDD,0xB4); }
	         | OR A COMMA IXL          { outCode(2,0xDD,0xB5); }
	         | OR A COMMA IYH          { outCode(2,0xFD,0xB4); }
	         | OR A COMMA IYL          { outCode(2,0xFD,0xB5); }
	                
	;
	opcodeout: OUT PARLEFT expr PARRIGHT COMMA A  { outCode(2,0xD3,$3); }
	         | OUT PARLEFT C PARRIGHT COMMA reg8       { outCode(2,0xED,($6<<3)|1|64); }
    ;      
    opcodepop: POP reg16af { outCode(1,($2<<4)|1|128|64); }
             | POP IX    { outCode(2,0xDD,0xE1); }
             | POP IY    { outCode(2,0xFD,0xE1); }
    ;
    opcodepush: PUSH reg16af { outCode(1,($2<<4)|1|4|64|128); }
             |  PUSH IX    { outCode(2,0xDD,0xE5); }
             |  PUSH IY    { outCode(2,0xFD,0xE5); }
             
    ;
    opcoderes: RES expr COMMA reg8 { outCode(2,0xCB,($2<<3)|$4|128); }
             | RES expr COMMA PARLEFT HL PARRIGHT { outCode(2,0xCB,($2<<3)|128|4|2); }
             | RES expr COMMA PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0xCB,($7),($2<<3)|128|4|2); }
             | RES expr COMMA PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0xCB,($7),($2<<3)|128|4|2); }
             
    ;
	opcoderet: RET 					   { outCode(1,0xC9); }
	         | RET cc                  { outCode(1,($2<<3)|128|64); }
	;
	
	opcoderl:  RL reg8                                { outCode(2,0xCB,($2)|16); }
             | RL PARLEFT HL PARRIGHT                 { outCode(2,0xCB,16); }
             | RL PARLEFT IX PLUS expr PARRIGHT  { outCode(4,0xDD,0xCB,($5),0x16); }
             | RL PARLEFT IY PLUS expr PARRIGHT  { outCode(4,0xFD,0xCB,($5),0x16); }
    ;
    opcoderlc: RLC reg8                { outCode(2,0xCB,  $2); }
             | RLC PARLEFT HL PARRIGHT   { outCode(2,0xCB,0x06); }
             | RLC PARLEFT IX PLUS expr PARRIGHT { outCode(4,0xDD,0xCB,$5,0x06); }
             | RLC PARLEFT IY PLUS expr PARRIGHT { outCode(4,0xFD,0xCB,$5,0x06); }
    ; 
    opcoderr:  RR reg8                { outCode(2,0xCB,$2|8|16); }
             | RR PARLEFT HL PARRIGHT { outCode(2,0xCB,0x1E);     }
             | RR PARLEFT IX PLUS expr PARRIGHT { outCode(2,0xDD,0xCB,$5,0x1E); }
             | RR PARLEFT IY PLUS expr PARRIGHT { outCode(2,0xFD,0xCB,$5,0x1E); }
    ;
    opcoderrc: RRC reg8                { outCode(2,0xCB,$2|8); }
             | RRC PARLEFT HL PARRIGHT { outCode(2,0xCB,0x0E); }
             | RRC PARLEFT IX PLUS expr PARRIGHT { outCode(4,0xDD,0xCB,$5,0x0E); }
             | RRC PARLEFT IY PLUS expr PARRIGHT { outCode(4,0xFD,0xCB,$5,0x0E); }
    ;         
    opcoderst: RST expr { switch ($2) {
                                case 0x0: case 0x8:
                                case 0x10: case 0x18:
                                case 0x20: case 0x28:
                                case 0x30: case 0x38: outCode(1,($2<<3)|128|64|4|2|1); break;
                                default: fatalError("Wrong vector provided for RST"); break;
                               }
                             }
    ;
    opcodesbc: SBC A COMMA reg8 { outCode(1,$4|8|16|128); }
             | SBC A COMMA expr { outCode(2,0xDE,$4); }
             | SBC A COMMA PARLEFT HL PARRIGHT { outCode(1,0x9E); }
             | SBC A COMMA PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0x9E,$7); }
             | SBC A COMMA PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0x9E,$7); }
             | SBC HL COMMA reg16 { outCode(2,0xED,($4<<4)|2|64); }
             | SBC A COMMA IXH         {  outCode(2,0xDD,0x9C); }
	         | SBC A COMMA IXL         {  outCode(2,0xDD,0x9D); }
	         | SBC A COMMA IYH         {  outCode(2,0xFD,0x9C); }
	         | SBC A COMMA IYL         {  outCode(2,0xFD,0x9D); }
    ; 
    opcodeset: SET expr COMMA reg8 { outCode(2,0xCB,($2<<3)|$4|128|64); }
             | SET expr COMMA PARLEFT HL PARRIGHT { outCode(2,0xCB,($2<<3)|128|64|4|2); }
             | SET expr COMMA PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0xCB,($7),($2<<3)|128|64|4|2); }
             | SET expr COMMA PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0xCB,($7),($2<<3)|128|64|4|2); }
             
    ;
    opcodesla:  SLA reg8                                { outCode(2,0xCB,($2)|32); }
             | SLA PARLEFT HL PARRIGHT                 { outCode(2,0xCB,26); }
             | SLA PARLEFT IX PLUS expr PARRIGHT  { outCode(4,0xDD,0xCB,($5),0x26); }
             | SLA PARLEFT IY PLUS expr PARRIGHT  { outCode(4,0xFD,0xCB,($5),0x26); }
    ;  
    opcodesll:  SLL reg8                                { outCode(2,0xCB,($2)|32|16); }
             | SLL PARLEFT HL PARRIGHT                 { outCode(2,0xCB,36); }
             | SLL PARLEFT IX PLUS expr PARRIGHT  { outCode(4,0xDD,0xCB,($5),0x36); }
             | SLL PARLEFT IY PLUS expr PARRIGHT  { outCode(4,0xFD,0xCB,($5),0x36); }
    ; 
    opcodesra:  SRA reg8                                { outCode(2,0xCB,($2)|32|8); }
             | SRA PARLEFT HL PARRIGHT          { outCode(2,0xCB,0x2E); } 
             | SRA PARLEFT IX PLUS expr PARRIGHT  { outCode(4,0xDD,0xCB,($5),0x2E); }
             | SRA PARLEFT IY PLUS expr PARRIGHT  { outCode(4,0xFD,0xCB,($5),0x2E); }
    ; 
    opcodesrl:  SRL reg8                                { outCode(2,0xCB,($2)|32|16|8); }
             | SRL PARLEFT HL PARRIGHT                 { outCode(2,0xCB,0x3E); }
             | SRL PARLEFT IX PLUS expr PARRIGHT  { outCode(4,0xDD,0xCB,($5),0x3E); }
             | SRL PARLEFT IY PLUS expr PARRIGHT  { outCode(4,0xFD,0xCB,($5),0x3E); }
    ; 
    opcodesub: SUB reg8                { outCode(1,$2|16|128); }
             | SUB expr           { outCode(2,0xD6,$2); }
             | SUB PARLEFT HL PARRIGHT { outCode(1,0x96); }
             | SUB PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0x96,$5); }
             | SUB PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0x96,$5); }
             | SUB IXH         {  outCode(2,0xDD,0x94); }
	         | SUB IXL         {  outCode(2,0xDD,0x95); }
	         | SUB IYH         {  outCode(2,0xFD,0x94); }
	         | SUB IYL         {  outCode(2,0xFD,0x95); }
	         
    ; 
	opcodexor: XOR reg8			{ k = (($2)|128|32|8); outCode(1,k); }
	         | XOR expr    { outCode(2,0xEE,$2); }
	         | XOR PARLEFT HL PARRIGHT { outCode(1,0xAE); }
	         | XOR PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0xAE,$5); }
	         | XOR PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0xAE,$5); } 
	         | XOR IXH          { outCode(2,0xDD,0xAC); }
	         | XOR IXL          { outCode(2,0xDD,0xAD); }
	         | XOR IYH          { outCode(2,0xFD,0xAC); }
	         | XOR IYL          { outCode(2,0xFD,0xAD); }
	         | XOR A COMMA reg8			{ k = (($4)|128|32|8); outCode(1,k); }
	         | XOR A COMMA expr    { outCode(2,0xEE,$4); }
	         | XOR A COMMA PARLEFT HL PARRIGHT { outCode(1,0xAE); }
	         | XOR A COMMA PARLEFT IX PLUS expr PARRIGHT { outCode(3,0xDD,0xAE,$7); }
	         | XOR A COMMA PARLEFT IY PLUS expr PARRIGHT { outCode(3,0xFD,0xAE,$7); } 
	         | XOR A COMMA IXH          { outCode(2,0xDD,0xAC); }
	         | XOR A COMMA IXL          { outCode(2,0xDD,0xAD); }
	         | XOR A COMMA IYH          { outCode(2,0xFD,0xAC); }
	         | XOR A COMMA IYL          { outCode(2,0xFD,0xAD); }
	         	         
	;
	listexprw:  expr                 { p = (uint8_t *)malloc(3*sizeof(uint8_t)); p[0] = 2; p[1] = $1&0x00FF; p[2] = $1>>8; $$ = p;  }
	         | listexprw COMMA expr  { p = (uint8_t *)realloc($1,((*($1))+2)*sizeof(uint8_t)); p[p[0]+1] = $3&0x00FF; p[p[0]+2] = $3>>8; p[0] = p[0] + 2; $$ = p; }   
	         | STRING                     { p = (uint8_t *)malloc(strlen($1)+1); p[0] = strlen($1); for(a=0;a<strlen($1);a++) { p[a+1] = $1[a];  } $$ = p; }       
	         | listexprw COMMA STRING      {
	                                        p = (uint8_t *)realloc($1,$1[0]+strlen($3)); 
	                                        strcpy((char *)&p[p[0]+1],(char *)$3); p[0] = p[0] + strlen($3); $$ = p; 
	                                      }                           
	;
	
	
	listexprd:  expr                      { p = (uint8_t *)malloc(5*sizeof(uint8_t)); p[0] = 4; p[1] = $1&0x000000FF; p[2] = ($1&0x0000FF00)>>8; p[3] = ($1&0x00FF0000)>>16; p[4] = ($1&0xFF000000)>>24; $$ = p;  }
	         | listexprd COMMA expr  { p = (uint8_t *)realloc($1,((*($1))+4)*sizeof(uint8_t)); p[p[0]+1] = $3&&0x000000FF; p[p[0]+2] = ($3&0x0000FF00)>>8; p[p[0]+4] = ($3&0x00FF0000)>>18; p[p[0]+4] = ($3&0xFF000000)>>24; p[0] = p[0] + 4; $$ = p; }   
	         | STRING                     { p = (uint8_t *)malloc(strlen($1)+1); p[0] = strlen($1); for(a=0;a<strlen($1);a++) { p[a+1] = $1[a];  } $$ = p; }                      
	         | listexprd COMMA STRING      {
	                                        p = (uint8_t *)realloc($1,$1[0]+strlen($3)); 
	                                        strcpy((char *)&p[p[0]+1],(char *)$3); p[0] = p[0] + strlen($3); $$ = p; 
	                                      }                          
	;
	
	
	listexpr:  expr                      { p = (uint8_t *)malloc(2); p[0] = 1; p[1] = $1; $$ = p; }
	         | STRING                    { p = (uint8_t *)malloc(strlen($1)+1); p[0] = strlen($1); for(a=0;a<strlen($1);a++) { p[a+1] = $1[a];  } $$ = p; }
	         | listexpr COMMA expr  { 
	                                       if (((uint16_t)$3) > 255) {
	                                          p = (uint8_t *)realloc($1,((*($1))+2)); p[p[0]+1] = $3&0x00FF; p[(*p)+2] = $3>>8; p[0] = p[0] + 2; $$ = p; 
	                                       }
	                                       else { 
	                                          p = (uint8_t *)realloc($1,((*($1))+1)); p[p[0]+1] = $3; p[0] = p[0] + 1; $$ = p; 
	                                       }   
	                                     }    
	         | listexpr COMMA STRING      {
	                                        p = (uint8_t *)realloc($1,$1[0]+strlen($3)); 
	                                        strcpy((char *)&p[p[0]+1],(char *)$3); p[0] = p[0] + strlen($3); $$ = p; 
	                                      }                            
	;
	expr:      expritem                   	 { $$ = $1;  }
	         | EXCLAMATION expr %prec UMINUS { $$=($2==0)?1:0; }
	         | PARLEFT expr PARRIGHT        { $$ = $2;  }
	         | MINUS expr %prec UMINUS      { $$=-$2; }
	         | expr PLUS   		expr    	{ $$ = $1 + $3; }
	         | expr MINUS  		expr   		{ $$ = $1 - $3; }
	         | expr MULT   		expr    	{ $$ = $1 * $3; }
	         | expr DIVIDE 		expr  		{ $$ = $1 / $3; }
	         | expr BITAND 		expr  		{ $$ = $1 & $3; }
	         | expr BITOR  		expr 		{ $$ = $1 | $3; }
	         | expr OPSHLF 		expr  		{ $$ = $1 << $3; }
	         | expr OPSHRT 		expr 		{ $$ = $1 >> $3; }    
	         | expr NEQUAL 		expr   		{ if ( $1 == $3 )  { $$ = 0; } else { $$ = 1;  } }	
             | expr EQUAL  		expr   		{ if ( $1 == $3 )  { $$ = 1; } else { $$ = 0;  } }	
             | expr GREATEREQ  	expr 		{ if ( $1 >= $3 )  { $$ = 1; } else { $$ = 0;  } }	
             | expr GREATERTHAN expr	 	{ if ( $1 > $3 )  { $$ = 1; } else { $$ = 0;  } }	
             | expr LESSEQ  	expr 		{ if ( $1 <= $3 )  { $$ = 1; } else { $$ = 0;  } }	
             | expr LESSTHAN  	expr 		{ if ( $1 < $3 )  { $$ = 1; } else { $$ = 0;  } }
	         | expr AND 		expr       	{ if ( $1 && $3) { $$=1; } else {$$=0; } } 
  	         | expr OR  		expr     	{ if ( $1 || $3) { $$=1; } else {$$=0; } } 
	;	               
	expritem: LITERAL               {  
	                                 if (getLabelValue($1,&k) < 0)   { labelUndefinedError($1); $$=0; }                                  
	                                 else { $$=k; }
	                                }	                              
             | INTEGER              { $$ = $1; }
             | CHAR                 { $$ = $1; }
             | DOLAR                { $$ = previouspc; }
             | DEFINED LITERAL      { $$ = (LookupTableLabels($2)<0)?0:1; } 
             
    ;
    
    reg8:      A	{ $$ = 7; }
             | B    { $$ = 0; }
             | C    { $$ = 1; }
             | D    { $$ = 2; }
             | E    { $$ = 3; }
             | H    { $$ = 4; }
             | L    { $$ = 5; }
    ;
    regixiy:   IX   { $$ = 0xDD; }
             | IY   { $$ = 0xFD; }
    ;
    reg16:     BC	{ $$ = 0; }
             | DE    { $$ = 1; }
             | HL   { $$ = 2; }
             | SP    { $$ = 3; }
    ;         
    reg16af:   BC	{ $$ = 0; }
             | DE    { $$ = 1; }
             | HL   { $$ = 2; }
             | AF    { $$ = 3; }
    
    ;
    undocregix: IXH    { $$ = 4; }
            | IXL    { $$ = 5; }
    ;
    undocregiy: IYH    { $$ = 4; }
            | IYL    { $$ = 5; }
    ; 
    cc:        NZ { $$ = 0; }
             | Z { $$ = 1; }
             | NC { $$ = 2; }
             | C { $$ = 3; }
             | PO { $$ = 4; }
             | PE  { $$ = 5; }
             | P  { $$ = 6; }
             | M { $$ = 7; }
    ;
    ccreduced:        NZ { $$ = 0; }
             | Z { $$ = 1; }
             | NC { $$ = 2; }
             | C { $$ = 3; }
    ;         
