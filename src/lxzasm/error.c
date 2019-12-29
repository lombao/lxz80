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
 
/**************************************/ 
/* This module is for handling errors */
/**************************************/

#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/* External declarations */
extern int yylineno;
extern int pass;
extern int ignoreUndocWarnings;
extern int condStatus;

/* Local declarations */
void labelSizeError(const char * label);
void recoverableError(const char *str);
void yyerror(const char *str);
void labelExhaustedError();
void labelAlreadyDefinedError(const char * label);
void labelUndefinedError(const char * label);
void sourceMaxLinesError();
void sourceSizeLineError();
void sourceLimitError(const int limit);
void undocumentedError();
void warningError(const char *str);
void includebinTooBigError(const char * includefile);
void directiveError(const char * msg);

/*************************************************/
void yyerror(const char *str)
{
	    if (pass> 1) {
	      recoverableError(str);  
	    }
} 

void recoverableError(const char *str) {
	    fprintf(stderr,">ERROR in line: %d ::: %s\n",yylineno,str);    
}

void fatalError(const char *str) {
	    fprintf(stderr,">FATAL ERROR in line: %d ::: %s\n",yylineno,str);    
	    exit(1);
}

void warningError(const char *str) {
	if (pass>1) {
	    fprintf(stderr,">WARNING in line: %d ::: %s\n",yylineno,str);    
	}
}

void labelSizeError(const char * label) {
 
     	recoverableError("Label name size is too big");
     	fprintf(stderr,"     LABEL: %s , the current size limit is %d characters\n",label,MAX_SIZE_LABEL);
     	exit (1);
	    
}

void labelExhaustedError() {
 
     	recoverableError("Maximun number of Labels reached");
     	fprintf(stderr,"     The maximun number of labels are %d\n",MAX_NUM_LABELS);
     	exit (1);
	    
}

void labelAlreadyDefinedError(const char * label) {

    	recoverableError("Label Already defined. Labels cannot be re-used");
     	fprintf(stderr,"     %s was already defined elsewhere\n",label);
     	exit (1);

}


void labelUndefinedError(const char * label) {

  if ( pass > 1 ) {
    	recoverableError("Label has not been defined");
     	fprintf(stderr,"      %s is unknown\n",label);
     	exit (1);
  }
}

void sourceMaxLinesError() {

     	recoverableError("Maximun number of Asm lines reached. Your source code is too big");
     	fprintf(stderr,"     The maximun number of lines accepted are %d\n",MAX_NUMBER_LINES);
     	exit (1);

}


void sourceSizeLineError() {

     	recoverableError("Maximun size of opcodes in a line, is too big");
     	fprintf(stderr,"     The maximun size in opcodes per line is %d\n",MAX_SIZE_CODE_LINE);
     	exit (1);

}

void sourceLimitError(const int limit) {
	
     	warningError("Memory beyond the LIMIT has been used");
     	fprintf(stderr,"     The LIMIT directive has been defined in your code as: %4x\n",limit);

}


void includebinTooBigError(const char * includefile) {
	 	recoverableError("The file to be include with the includebin is too large");
     	fprintf(stderr,"     IncludeBin: %s  \n",includefile);
     	exit (1);
	
}

void directiveError(const char * msg) {
	
  if ( !condStatus ) { return; }
  
	    fprintf(stderr,">DIRECTIVE ERROR in line: %d ::: %s\n",yylineno,msg);    
	    exit(1);
}
