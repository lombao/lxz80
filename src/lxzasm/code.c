/* Copyright (c) 2017 Cesar Lombao
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
 
 
/*
   This module handles the generated code 
*/


#include <stdio.h> 
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

#include "defs.h"

/* Data structure */
struct Scodeline {
	uint8_t * code; 	/* all the codes of the instruction */
	uint16_t size;   	/* the size in bytes */
	uint16_t line;   	/* the corresponding line number in source code */
	uint16_t address;	/* Address in memory */
	uint8_t  directive; /* to flag that this line although withouth opcodes should be printed */
	char text[MAX_SIZE_ASM_LINE]; /* the original asm text */
} ObjectCode[MAX_NUMBER_LINES];


uint16_t start_org = 0;					/* start of the code , normally the lowest ORG */
uint16_t end_limit = 0xFFFF;  			/* The limit in memory, the upper limit */
uint8_t binarycode[MAX_SIZE_RAM];	/* the binary code */
uint16_t totalbytes = 0;			/* the number of bytes compiled */

uint16_t pc;	     /* global pc counter */
uint16_t previouspc;


/* External dependencies */
extern int pass;
extern int yylineno;
extern int condStatus;
extern char * fileasm;
extern char * getDefinedLabels();
extern void sourceMaxLinesError();
extern void sourceSizeLineError();
extern void sourceLimitError(const int limit);

/* Functions in this module  */
void codeInit();
int outCode( int num, ... );
void outDirective();
void outputBinCode(const char * outputfile, const uint8_t padding);
void outputLstCode(const char * outputfile);
void setPC(uint16_t org);
void setLimit(uint16_t limit);
void setStart(uint16_t start);
void setCodeAsmLine(const int line, const char * text);
void codeLink();


/*************************************************/
/*************************************************/
/*************************************************/
/*************************************************/

/* initialize before compiling */
void codeInit() {
 int a;
 	  
	for(a=0;a<MAX_NUMBER_LINES;a++) {
		ObjectCode[a].size = 0;
		ObjectCode[a].line = 0;
		ObjectCode[a].code = NULL;
		ObjectCode[a].address = 0;
		ObjectCode[a].directive = 0;
	}
	  
	for(a=0;a<MAX_SIZE_RAM;a++) {
		binarycode[a] = 0;
	}
}



/* this is a patch to add in the ObjectCode table 
 * lines that don't produce any cpu instruction like
 * directives or labels , so later can be shown in the 
 * .lst files */
 
void outDirective () {
	 ObjectCode[yylineno].directive = 1;
	 ObjectCode[yylineno].address = pc;
}


/* Use to add the original asm lines into the code */
void setCodeAsmLine(const int line, const char * text) {
	strncpy(ObjectCode[line].text,text,MAX_SIZE_ASM_LINE);
}


/* to stablish an lower memory limit */
void setStart(uint16_t start) {
	if ( start_org == 0 ) { start_org = start; }
	if ( start_org > start ) { start_org = start; }
	
	previouspc = pc = start;
}

/* to stablish an upper memory limit */
void setLimit(uint16_t limit) {
	end_limit = limit;
}




/*************************************************/
int outCode( int num, ... ) {
 
 uint8_t * ptr = NULL;
 va_list arguments;     
 uint8_t opcode;
 int k;
 
    if ( !condStatus ) { return 0; }
  	
	if (yylineno == MAX_NUMBER_LINES) { 
		 sourceMaxLinesError(); 
    }
    

   if (num > MAX_SIZE_CODE_LINE ) {
	     sourceSizeLineError(); 
    }
   
   if ( pc+num >= end_limit ) {
	  sourceLimitError(end_limit);
   } 
      
    /* Initializing arguments to store all values after num */
    va_start ( arguments, num );           
	k = ObjectCode[yylineno].size;
	if ( ( k+num ) >= MAX_SIZE_CODE_LINE ) {
		sourceSizeLineError();
	}
	
    for ( int x = 0; x < num; x++ )        
    {
		opcode = (uint8_t)va_arg ( arguments, int );
         if (pass > 1) {		 
	      if ( k == 0) {	
		   ObjectCode[yylineno].line = yylineno;
	       ObjectCode[yylineno].address = pc;
	       ObjectCode[yylineno].size = x+1;
	       
	       ptr = ObjectCode[yylineno].code;
	       ptr = (uint8_t *)realloc(ptr, (x+1)*sizeof(uint8_t) );
	       ptr[x] = opcode;
	       ObjectCode[yylineno].code = ptr;
	       
	      }
	      else {
		   ObjectCode[yylineno].size = k+x+1;
	       ptr = ObjectCode[yylineno].code;
	       ptr = (uint8_t *)realloc(ptr, (k+x+1)*sizeof(uint8_t) );
	       ptr[k+x] = opcode;
	       ObjectCode[yylineno].code = ptr;
	        
		  }
	    } 
	    
	}
	pc = pc + num;
	va_end ( arguments );                  // Cleans up the list

    return 0;
}





/*************************************************/

void outputLstCode(const char * outputfile) {
 uint a = 0;	
 uint b = 0;
 uint c = 0;
 FILE * fo;
 char kk[10];
 char line[MAX_SIZE_ASM_LINE+50];
 char opli[MAX_SIZE_CODE_LINE*2];
 char opcode[3];
 char * l = NULL;
    
    
        if (outputfile == NULL) { return; }
        
        fo = fopen(outputfile,"w");
        if (fo == NULL) { perror("ERROR OUTPUT:"); exit(EXIT_FAILURE); }
         
        sprintf(line,"LIST::::::: \n\n");
		fwrite(line,1,strlen(line),fo);     
                   
        		                 
		  for(a=0;a<MAX_NUMBER_LINES;a++) {
			if ( ObjectCode[a].size != 0 ) {
			   for (b=0;b<ObjectCode[a].size;b++) {
				   sprintf(opcode,"%02X",ObjectCode[a].code[b]);
				   strncpy(opli+(b*2),opcode,2);
				   opli[(b*2)+2]=0x0;
			   }

			   if ( strlen(opli) > 8) {
				 strncpy(kk,opli,8); kk[8] = 0x0; 
	             sprintf(line,"%04X %8s %04d %s",ObjectCode[a].address,kk,ObjectCode[a].line,ObjectCode[a].text);
	             fwrite(line,1,strlen(line),fo);
	             for(c=8;c<strlen(opli);c += 8) {
                   strncpy(kk,opli+c,8);  kk[8] = 0x0;
	               sprintf(line,"     %8s \n",kk);
	               fwrite(line,1,strlen(line),fo);
				 }
	             
			   }
			   else {
			     sprintf(line,"%04X %8s %04d %s",ObjectCode[a].address,opli,ObjectCode[a].line,ObjectCode[a].text);
			     fwrite(line,1,strlen(line),fo);			  
		       } 
		    } /* end if */
		    else{
			  if ( ObjectCode[a].directive ) {
				sprintf(line,"%04X %8s %04d %s",ObjectCode[a].address,"       ",ObjectCode[a].line,ObjectCode[a].text);
				fwrite(line,1,strlen(line),fo);			
			  }
			}
		  }  
		

        fwrite("\n",1,strlen("\n"),fo);
        l = getDefinedLabels();
        if ( l != NULL ) {
          fwrite(l,1,strlen(l),fo);
	    }

        sprintf(line,"Total bytes assembled: %d\n",totalbytes);
        fwrite(line,1,strlen(line),fo);
         

        fclose(fo);
}


void outputBinCode(const char * outputfile,const uint8_t padding ) {
 FILE * fo;
 
        fo = fopen(outputfile,"w"); 
        if (fo == NULL) { perror("ERROR OUTPUT:"); exit(EXIT_FAILURE); }
                
        if (padding == FALSE) { /* then only output data from the start point */
			fwrite(&(binarycode[start_org]),1,end_limit-start_org,fo);
		}
		else {           
			fwrite(&(binarycode[0]),1,end_limit,fo);
	    }
		
        fclose(fo);
}



/* this function assembles all the code from different files
 * and create a single block of code order by address memory
 * ready to be outputed. Also determines the number of bytes
 * used */
void codeLink() {
 uint16_t a = 0;
 uint16_t b = 0;
                 
	     for(a=0;a<MAX_NUMBER_LINES;a++) {
			if ( ObjectCode[a].size != 0 ) {
			   for (b=0;b<ObjectCode[a].size;b++) { 
				   binarycode[ObjectCode[a].address + b] = ObjectCode[a].code[b];
				   totalbytes++;
			   }
			}
		 }
		

}
