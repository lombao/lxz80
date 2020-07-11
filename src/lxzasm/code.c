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
#include "codedata.h"


//----------------------------------------------------------------------
// EXTERNAL
extern struct sline * slines;
extern struct spreproc preproc;

extern int pc;
extern int prepc;
extern int yylineno;
extern int condStatus;
extern char * fileasm;
extern char * getDefinedLabels();

//----------------------------------------------------------------------
// INTERNAL
/* Functions in this module  */
void codeInit();
int outCode( int num, ... );
void outputBinCode(const char * outputfile, const uint8_t padding);
void outputLstCode(const char * outputfile);

/* totalbytes */
int totalbytes = 0;			/* the number of bytes compiled */


/*************************************************/
/*************************************************/
/*************************************************/
/*************************************************/

/* initialize before compiling */
void codeInit() {
 	  
	totalbytes = 0;
		
	pc = preproc.org;
	prepc = preproc.org;
	slines->address = preproc.org;
	
}


/*************************************************/
int outCode( int num, ... ) {
	
	va_list arguments;
	
	struct sline * s = slines;
	

	
	for(int k=1;k<yylineno;k++) { s = s->next; }
	s->codesize = num;
	if ( s->prev != NULL ) {
		s->address = s->prev->address + s->prev->codesize;
	}
	else {
		s->address = preproc.org;
	}

	if ( num == 0 ) {
		s->code = NULL;
		s->codehex = NULL;
		return 0 ;
	}

		
	s->code = (uint8_t*) realloc (s->code,sizeof(uint8_t)*(num+1));
	if (s->code == NULL) {
		fprintf(stderr,">>> %s\n",s->line);
		fprintf(stderr,"::: ERROR: Out of memory Compiling line %d of file %s\n",s->nline,s->filename);
		exit(EXIT_FAILURE);
	}
	s->codehex = (char*) realloc (s->codehex,sizeof(char)*((num*2)+1));
	if (s->codehex == NULL) {
		fprintf(stderr,">>> %s\n",s->line);
		fprintf(stderr,"::: ERROR: Out of memory Compiling line %d of file %s\n",s->nline,s->filename);
		exit(EXIT_FAILURE);
	}
	
	va_start ( arguments, num );  
	for ( int x = 0; x < num; x++ ) {
		int opcode = va_arg ( arguments, int );
	
		s->code[x] = opcode;
		sprintf(&s->codehex[x*2],"%02X",opcode);

	}

	
	pc = pc + num;
	totalbytes += num;
	
	va_end ( arguments ); 
	return 0;
		
}



/*************************************************/
void outputLstCode(const char * outputfile) {

 FILE * fo;
 struct sline * s = slines;	
 char line[800];
 
		if (outputfile == NULL) { return; }
        fo = fopen(outputfile,"w");
        if (fo == NULL) { 
			fprintf(stderr,"::: ERROR:  Cannot open the out file %s\n",outputfile);
			exit(EXIT_FAILURE);
		}
         
        
        /* Headers */ 
        if ( preproc.title != NULL ) {
			sprintf(line,"LIST::::: %s \n\n",preproc.title);
		}
		else {
			sprintf(line,"LIST::::: \n\n");
		}
		fwrite(line,1,strlen(line),fo);     
       
        
        sprintf(line,"ORG::::: %04XH \n",preproc.org);
		fwrite(line,1,strlen(line),fo); 
		sprintf(line,"LIMIT::: %04XH \n\n",preproc.limit);
		fwrite(line,1,strlen(line),fo); 
		
		/* Lines */
		while(s != NULL) {
			
			if ( s->codesize > 0 ) {
				sprintf(line,"%04X %8s      %04d %s",s->address,s->codehex,s->nline,s->parsed);
				fwrite(line,1,strlen(line),fo);
			}
					
			s = s->next;
		}
	

        fwrite("\n",1,strlen("\n"),fo);
        char * l = getDefinedLabels();
        if ( l != NULL ) {
          fwrite(l,1,strlen(l),fo);
	    }

        sprintf(line,"Total bytes assembled: %d\n",totalbytes);
        fwrite(line,1,strlen(line),fo);
         

		fclose(fo);
		
		 
}


/*************************************************/
void outputBinCode(const char * outputfile,const uint8_t padding ) {
 FILE * fo;
 struct sline * s = slines;	
        
        /* open */
        if (outputfile == NULL) { return; }
        fo = fopen(outputfile,"w");
        if (fo == NULL) { 
			fprintf(stderr,"::: ERROR:  Cannot open the output bin file %s\n",outputfile);
			exit(EXIT_FAILURE);
		}
		
		/* write */
		if (padding == FALSE) { /* then only output data from the start point */
			char * k = ( char *) malloc( preproc.org );
			memset(k,0x0,preproc.org );
			fwrite(k,preproc.org,1,fo);
			while ( s!=NULL ) {
				if ( s->codesize > 0 ) {
					fwrite(s->code,s->codesize,1,fo);
				}
				s = s->next;
			}
		}
		else {     
			while(s != NULL) {
				if ( s->codesize > 0 ) {
					fwrite(s->code,s->codesize,1,fo);
				}
				s = s->next;
			}
	    }
		
		
		/* close */
		fclose(fo);
		
        
        
}



