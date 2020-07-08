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
 
#include <stdio.h> 
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "defs.h"

//----------------------------------------------------------------------
// EXTERNAL
extern int yyparse();
extern int yylineno;
extern int reset_lexer();
extern FILE * yyin;
extern int outCode( int num, ... );
extern void codeInit();
extern void outputBinCode(const char * outputfile, const uint8_t padding);
extern void outputLstCode(const char * outputfile);
extern void setCodeAsmLine(const int line, const char * text);
extern char * getDefinedLabels(); /* here added in case we need debug */
extern void setFileName(const char * filename);
extern void codeLink();
extern struct sline * preproc_uploadFile(const char * file);
extern FILE * preproc_writeFile();
extern void preproc_proc();
extern void preproc_setslines( struct sline * s );
void reset_pc();

//----------------------------------------------------------------------
// INTERNAL
void showUsage();
void showVersion();

/******************************/
/* GLOBAL VARIABLES           */

int pass = 1; 			/* The pass of the assembler */
int condStatus = -1; 	/* IF directive control */
int pc	=0;	     	/* global pc counter */
int prepc =0;
/*******************************/


/* Print usage */
void showUsage() {
	 fprintf(stderr,"LXZ Assembler. Version %s\n\n",LXZ80_VERSION); 
	 fprintf(stderr,"Usage: lxzasm [-v] [ -h] [ -l] [ -o <filename> ] inputfile \n");
	 fprintf(stderr,"	v:  Show Version\n");
	 fprintf(stderr,"	h:  Show Help ( this help )\n");
	 fprintf(stderr,"	l:  Generate an ASCII lst output\n");
	 fprintf(stderr,"	p:  PAd with zeroes the ouput from the byte 0 until the start of the code ( set by ORG directive )\n");
	 fprintf(stderr,"	o <file>:  Use <file> as the output name\n");
	 
}


void showVersion() {
	fprintf(stderr,"LXZ Assembler. Version %s\n\n",LXZ80_VERSION); 
}


/*** MAIN *************************/ 
int main(int argc, char *argv[])
{
  int opt;
  char outputFile[MAX_SIZE_FILE_NAME];
  int outputList = FALSE;
  int paddingZeroes = FALSE;
  
  strcpy(outputFile,DFT_OUTPUT_FILE);
  
  if (argc==1) { 
	 fprintf(stderr, "%s: No input files\n",argv[0]);
	 showUsage();
     exit(EXIT_FAILURE);
  }
  
  while ((opt = getopt(argc, argv, "o:plvh")) != -1) {
        switch (opt) {
		case 'v':
			showVersion();
			exit(EXIT_SUCCESS);
			break;
        case 'o':
			strcpy(outputFile,optarg);
            break;  
        case 'l':  /* type of output text list */
            outputList = TRUE;  
            break;     
        case 'p':  /* Pad with 0 the output file until the first org. */
            paddingZeroes = TRUE;  
            break;     
        case 'h': /* Show version and quit */
            showUsage();
            exit(EXIT_SUCCESS);
            break;
        default: /* '?' */
            showUsage();
            exit(EXIT_FAILURE);
        }
  }
  
  if (argc==optind) { 
	 fprintf(stderr, "%s: No input files\n",argv[0]);
	 showUsage();
     exit(EXIT_FAILURE);
  } 
  

	preproc_setslines( preproc_uploadFile(argv[optind]) );
	preproc_proc();
	yyin = preproc_writeFile();
  
    /* reset the code table, just for the number of files given */
	codeInit(); 

	pass = 1;
	yyparse();

	
	
 /*              
        printf("Pass 1 completed\n");
        printf("Defined Labels: \n %s\n",getDefinedLabels());
 */ 
       
    rewind(yyin);    
	reset_lexer();
	reset_pc();
	pass = 2;
	yyparse();
	fclose(yyin);


/* ingest the original source code */ 
    yyin = fopen(argv[optind], "r");
	if (yyin == NULL) { perror("ERROR:"); return(EXIT_FAILURE); }	
	int l = 1; char line[MAX_SIZE_ASM_LINE];
	while (fgets(line, sizeof(line), yyin)) {
		setCodeAsmLine(l,line);
		l++;
	} 
	fclose(yyin);        
   
/* Let's link the code */
    codeLink();

/* Output */
	outputBinCode(outputFile,paddingZeroes);

	if ( outputList == TRUE ) {
		outputLstCode(DFT_OUTPUT_LST_FILE); 
    }
} 


