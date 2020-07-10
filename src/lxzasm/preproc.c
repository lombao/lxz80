
#include <stdio.h> 
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

#include "defs.h"
#include "codedata.h"

//----------------------------------------------------------------------
extern struct sline * slines;
extern struct sline * slinesidx;
extern struct spreproc preproc;

//----------------------------------------------------------------------
// INTERNAL
struct sline * preproc_uploadFile(const char * file);
FILE * preproc_writeFile();
void preproc_setslines(  struct sline * s );
void preproc_proc();
void preproc_replacetab();
void preproc_reduceblanks();
void preproc_reducecommaspace();
void preproc_trimWhiteSpaces();
void preproc_removeComments();
void preproc_directive_title();
void preproc_directive_org();
void preproc_directive_limit();
void preproc_directive_aseg();
void preproc_directive_cseg();
void preproc_directive_include();
void preproc_directive_includebin();

char *  preproc_util_extractliteral( char * s  );
int  preproc_util_extractnumber( char * s  );
void preproc_includeFile(const char * file, struct sline * sfrom, struct sline * sto);
void preproc_loadBlob(const char * file, struct sline * s);


/**********************************************************************/
/**********************************************************************/

void preproc_setslines( struct sline * s ) {
	slines 		= s;
	slinesidx 	= s;
}


struct sline * preproc_uploadFile(const char * file) {
   
  char auxline[MAX_SIZE_ASM_LINE+1];
  struct sline * idx = NULL;
  struct sline * str = NULL;
  
	auxline[MAX_SIZE_ASM_LINE] = 0x0;
   
	FILE * fi=fopen(file, "r"); 
	if ( fi == NULL) { 
		fprintf(stderr,"::: ERROR: I cannot read the file %s\n",file);
		exit(EXIT_FAILURE);
	}
	
	int c=1;	
	while ( fgets( auxline ,MAX_SIZE_ASM_LINE,fi) != NULL ) {
		
		struct sline * s =  (struct sline *) malloc ( sizeof ( struct sline) );
		if ( s == NULL ) {
			fprintf(stderr,"::: ERROR:  Out of memory uploading file %s in Preprocessor\n",file);
			exit(EXIT_FAILURE);
		}
		memset(s,0x0,sizeof ( struct sline) );
		strcpy(s->line,auxline);
		strcpy(s->parsed,auxline);
		strcpy(s->filename,file);
		s->next = NULL;
		s->code = NULL;
		s->codehex = NULL;
		s->codesize = 0;
		s->address = -1;
		s->nline = c++;
		s->prev  = idx;
	
		if ( idx == NULL ) {
			str 	= s;
			idx 	= s; 
		}
		else {
			idx->next 	= s;
			idx = s;
		}
	}
   fclose(fi);
	
return str;

}


void preproc_proc() {
	preproc_replacetab();
	preproc_reduceblanks();
	preproc_reducecommaspace();
	preproc_trimWhiteSpaces();
	preproc_directive_include();
	
	preproc_removeComments();
	preproc_directive_title();
	preproc_directive_org();
	preproc_directive_limit();
	preproc_directive_aseg();
	preproc_directive_cseg();

}


//*********************************************************************/
//*********************************************************************/
//*********************************************************************/
void preproc_replacetab() {
	
	struct sline * s = slines;
    
	while(s != NULL) {	
		
		int a=0;
		int singlequote = 0;
		int doublequote = 0;
		while(s->parsed[a] != 0x0) {
			switch(s->parsed[a]) {
				case '\t':
							if ( !singlequote && !doublequote ) {
								s->parsed[a]=' '; 
							}
							break;
				case '\'': if ( singlequote ) { singlequote = 0; }
						   else {
							   if ( ! doublequote ) { singlequote = 1; }
						   }
						   break;
				case '"' : if ( doublequote ) { doublequote = 0; }
						   else {
							   if ( ! singlequote ) { doublequote = 1; }
						   }
						   break;
			};
			a++;
		}
		
		s = s->next;
		
	}
}


void preproc_reduceblanks() {
	
	struct sline * s = slines;
    char * kk;
    
	while(s != NULL) {	
		
		int a=0;
		int singlequote = 0;
		int doublequote = 0;
		while(s->parsed[a] != 0x0) {
			switch(s->parsed[a]) {
				case ' ':
							if ( !singlequote && !doublequote ) {
								if (s->parsed[a+1]==' '){
									kk = strdup(&s->parsed[a+1]);
									strcpy(&s->parsed[a],kk);
									free(kk);
								}
							}
							break;
				case '\'': if ( singlequote ) { singlequote = 0; }
						   else {
							   if ( ! doublequote ) { singlequote = 1; }
						   }
						   break;
				case '"' : if ( doublequote ) { doublequote = 0; }
						   else {
							   if ( ! singlequote ) { doublequote = 1; }
						   }
						   break;
			};
			a++;
		}
		
		s = s->next;
		
	}
}


void preproc_reducecommaspace() {
	
	struct sline * s = slines;
    char * kk;
    
	while(s != NULL) {	
		
		int a=0;
		int singlequote = 0;
		int doublequote = 0;
		while(s->parsed[a] != 0x0) {
			switch(s->parsed[a]) {
				case ' ':
							if ( !singlequote && !doublequote ) {
								if (s->parsed[a+1]==','){
									kk = strdup(&s->parsed[a+1]);
									strcpy(&s->parsed[a],kk);
									free(kk);
								}
							}
							break;
				case ',':
							if ( !singlequote && !doublequote ) {
								if (s->parsed[a+1]==' '){
									kk = strdup(&s->parsed[a+2]);
									strcpy(&s->parsed[a+1],kk);
									free(kk);
								}
							}
							break;			
				case '\'': if ( singlequote ) { singlequote = 0; }
						   else {
							   if ( ! doublequote ) { singlequote = 1; }
						   }
						   break;
				case '"' : if ( doublequote ) { doublequote = 0; }
						   else {
							   if ( ! singlequote ) { doublequote = 1; }
						   }
						   break;
			};
			a++;
		}
		
		s = s->next;
		
	}
}


void preproc_trimWhiteSpaces() {
	
	struct sline * s = slines;
    char * kk;
    
	while(s != NULL) {	
		int a = 0;
		while(s->parsed[a] == ' ' || s->parsed[a] == '\t') { a++; }
		kk = strdup(&s->parsed[a]);
		strcpy(s->parsed,kk);
		free(kk);
		
		a = strlen(s->parsed);
		while(s->parsed[a-2] == ' ' || s->parsed[a-2] == '\t') { 
		  s->parsed[a-2]='\n';
		  s->parsed[a-1]=0x0;
		  a--;
		}
		
		s = s->next;
	}
}


//*********************************************************************/
void preproc_removeComments() {
	
	struct sline * s = slines;
    
	while(s != NULL) {	
		
		int a=0;
		int singlequote = 0;
		int doublequote = 0;
		while(s->parsed[a] != 0x0) {
			switch(s->parsed[a]) {
				case ';':
				case '#':
							if ( !singlequote && !doublequote ) {
								s->parsed[a]='\n'; s->parsed[a+1]=0x0;
							}
							break;
				case '\'': if ( singlequote ) { singlequote = 0; }
						   else {
							   if ( ! doublequote ) { singlequote = 1; }
						   }
						   break;
				case '"' : if ( doublequote ) { doublequote = 0; }
						   else {
							   if ( ! singlequote ) { doublequote = 1; }
						   }
						   break;
			};
			a++;
		}
		
		s = s->next;
		
	}
}

//*********************************************************************/
void preproc_directive_include() {
	
	struct sline * s = slines;
	struct sline * sprev;
	
    char * filename;
    
	while(s != NULL) {	
		
		if (  strncmp(s->parsed,".include ",strlen(".include ") ) == 0 ||
		      strncmp(s->parsed,".INCLUDE ",strlen(".include ")) == 0 ||
			  strncmp(s->parsed,"include ",strlen("include ")) == 0 ||
			  strncmp(s->parsed,"INCLUDE ",strlen("INCLUDE ")) == 0 
		   ) {
				filename = preproc_util_extractliteral( s->parsed  );  
				preproc_includeFile(filename, s->prev, s->next );
				sprev = s->prev;
				free(s);
				s = sprev;
				
				preproc_replacetab();
				preproc_reduceblanks();
				preproc_reducecommaspace();
				preproc_trimWhiteSpaces();
		}
		
		s = s->next;
		
	}
}


//*********************************************************************/
void preproc_directive_includebin() {
	
	struct sline * s = slines;
	
    char * filename;
    
	while(s != NULL) {	
		
		if (  strncmp(s->parsed,".includebin ",strlen(".includebin ") ) == 0 ||
		      strncmp(s->parsed,".INCLUDEDIN ",strlen(".includebin ")) == 0 ||
			  strncmp(s->parsed,"includebin ",strlen("includebin ")) == 0 ||
			  strncmp(s->parsed,"INCLUDEBIN ",strlen("INCLUDEBIN ")) == 0 
		   ) {
				filename = preproc_util_extractliteral( s->parsed  );  
				preproc_loadBlob(filename,s);
				
		}
		
		s = s->next;
		
	}
}

//*********************************************************************/
void preproc_directive_title() {
	
	struct sline * s = slines;
    
	while(s != NULL) {	
		
		if (  strncmp(s->parsed,".title ",strlen(".title ") ) == 0 ||
		      strncmp(s->parsed,".TITLE ",strlen(".TITLE ")) == 0 ||
			  strncmp(s->parsed,"title ",strlen("title ")) == 0 ||
			  strncmp(s->parsed,"title ",strlen("TITLE ")) == 0 
		   ) {
				preproc.title = preproc_util_extractliteral( s->parsed  );  
				s->parsed[0]='\n';
				s->parsed[1]=0x0;
				return;
		}
		
		s = s->next;
		
	}
}

//*********************************************************************/
void preproc_directive_org() {
	
	struct sline * s = slines;
	
    preproc.org = 0;
    
	while(s != NULL) {	
		
		if (  strncmp(s->parsed,".org ",strlen(".org ") ) == 0 ||
		      strncmp(s->parsed,".ORG ",strlen(".ORG ")) == 0 ||
			  strncmp(s->parsed,"ORG ",strlen("ORG ")) == 0 ||
			  strncmp(s->parsed,"org ",strlen("org ")) == 0 
		   ) {
				preproc.org = preproc_util_extractnumber( s->parsed );  
				s->parsed[0]='\n';
				s->parsed[1]=0x0;
				return;
		}
		
		s = s->next;
		
	}
}


//*********************************************************************/
void preproc_directive_limit() {
	
	struct sline * s = slines;
    
    preproc.limit = 0xFFFF;
    
	while(s != NULL) {	
		
		if (  strncmp(s->parsed,".limit ",strlen(".limit ") ) == 0 ||
		      strncmp(s->parsed,".LIMIT ",strlen(".LIMIT ")) == 0 ||
			  strncmp(s->parsed,"LIMIT ",strlen("LIMIT ")) == 0 ||
			  strncmp(s->parsed,"limit ",strlen("limit ")) == 0 
		   ) {
				preproc.limit = preproc_util_extractnumber( s->parsed );  
				s->parsed[0]='\n';
				s->parsed[1]=0x0;
				return;
		}
		
		s = s->next;
		
	}
}


//*********************************************************************/
void preproc_directive_aseg() {
	
	struct sline * s = slines;
    
    /*
     * Absolute segment. Code generated until other segment directive is generated in absolute address mode
     * It is the default. It will simply be removed and ignored
     */
    
	while(s != NULL) {	
		
		if (  strncmp(s->parsed,".aseg\n" ,strlen(".aseg\n") ) == 0 ||
		      strncmp(s->parsed,".ASEG\n",strlen(".aseg\n")) == 0 ||
			  strncmp(s->parsed,"ASEG\n",strlen("ASEG\n")) == 0 ||
			  strncmp(s->parsed,"aseg\n",strlen("aseg\n")) == 0 
		   ) {
				s->parsed[0]='\n';
				s->parsed[1]=0x0;
				return;
		}
		
		s = s->next;
		
	}
}

//*********************************************************************/
void preproc_directive_cseg() {
	
	struct sline * s = slines;
    
    /*
     * Code segment. Code generated until other segment directive is generated in code segment relative address mode.
     * This is not supported in this version
     */
    
	while(s != NULL) {	
		
		if (  strncmp(s->parsed,".cseg\n" ,strlen(".cseg\n") ) == 0 ||
		      strncmp(s->parsed,".CSEG\n",strlen(".cseg\n")) == 0 ||
			  strncmp(s->parsed,"CSEG\n",strlen("ACSEG\n")) == 0 ||
			  strncmp(s->parsed,"cseg\n",strlen("cseg\n")) == 0 
		   ) {
			   
				fprintf(stderr,"::: ERROR:  File: %s, Line: %d.  The Directive CSEG is not yet supported\n",s->filename,s->nline);
				exit(EXIT_FAILURE);
		}
		
		s = s->next;
		
	}
}


//*********************************************************************/
FILE * preproc_writeFile() {
	
	
	struct sline * s = slines;
	
	FILE * fdt = tmpfile();
	if ( fdt == NULL) { 
		fprintf(stderr,"::: ERROR: I cannot set a temporal file for preprocessing");
		exit(EXIT_FAILURE);
	}
	while(s != NULL) {
		fputs(s->parsed,fdt);
		s = s->next;
	}
	rewind(fdt);
	return fdt;
}


//*********************************************************************/
//*********************************************************************/
char *  preproc_util_extractliteral( char * s  ) {
	
	int a = 0;
	int c = 0;
	int singlequote = 0;
	int doublequote = 0;
	char auxc[MAX_SIZE_LABEL+1];
		
	while(s[a] != 0x0) {
		
			switch(s[a]) {

				case '\'': if ( singlequote ) { singlequote = 0; }
						   else {
							   if ( ! doublequote ) { singlequote = 1; }
						   }
						   break;
				case '"' : if ( doublequote ) { doublequote = 0; }
						   else {
							   if ( ! singlequote ) { doublequote = 1; }
						   }
						   break;
				default:
							if ( singlequote || doublequote ) {
								auxc[c++] = s[a];
							}
							break;
			};
			a++;
	}
	
	if (c) {
			auxc[c] = 0x0;
			return strdup(auxc);
	}
	
	return NULL;
}


//*********************************************************************/
//*********************************************************************/
int  preproc_util_extractnumber( char * s  ) {
	
	int a = 0;
    int c = 0;
    		
	while(s[a] != 0x0) {
		
			switch(s[a]) {

				case '&': return strtol(&s[a+1],NULL,16); break;
				case '#': return strtol(&s[a+1],NULL,16); break;
				case '$': return strtol(&s[a+1],NULL,16); break;
				case '%': return strtol(&s[a+1],NULL,2); break;
				
				case 'H': return strtol(&s[c],NULL,16); break;
				case 'h': return strtol(&s[c],NULL,16); break;
				
				case '0': if (s[a+1]=='x') { return strtol(&s[a],NULL,16); }
						  else { 
							  if ( !c ) { c = a; }
						  }
						  break;
				
				case '1': case '2': case '3':
				case '4': case '5':	case '6': case '7':
				case '8': case '9':
				           if ( !c ) { c = a; }
				           break;
				
				default : 
							if ( c ) {
								return strtol(&s[c],NULL,10); break;
							}
			};
			a++;
	}
	
	
	return -1;
}			



//*********************************************************************/
//*********************************************************************/
//*********************************************************************/
//*********************************************************************/
void preproc_includeFile(const char * file, struct sline * sfrom, struct sline * sto) {
   
  char auxline[MAX_SIZE_ASM_LINE+1];
  struct sline * idx = NULL;
  
	auxline[MAX_SIZE_ASM_LINE] = 0x0;
   
	FILE * fi=fopen(file, "r"); 
	if ( fi == NULL) { 
		fprintf(stderr,"::: ERROR: I cannot include file %s\n",file);
		exit(EXIT_FAILURE);
	}
	
	int c=1;	
	while ( fgets( auxline ,MAX_SIZE_ASM_LINE,fi) != NULL ) {
		
		struct sline * s =  (struct sline *) malloc ( sizeof ( struct sline) );
		if ( s == NULL ) {
			fprintf(stderr,"::: ERROR:  Out of memory uploading file %s in Preprocessor\n",file);
			exit(EXIT_FAILURE);
		}
		memset(s,0x0,sizeof ( struct sline) );
		strcpy(s->line,auxline);
		strcpy(s->parsed,auxline);
		strcpy(s->filename,file);
		s->next = NULL;
		s->code = NULL;
		s->codehex = NULL;
		s->codesize = 0;
		s->address = -1;
		s->nline = c++;
		s->prev  = idx;
	
		if ( idx == NULL ) {
			idx 	= s; 
			if (sfrom != NULL ) { sfrom->next = s; } 
			s->prev = sfrom;
		}
		else {
			idx->next 	= s;
			idx = s;
		}
	}
   fclose(fi);
	
 idx->next = sto;
 if ( sto != NULL ) { sto->prev = idx; }

}

//*********************************************************************/
//*********************************************************************/
//*********************************************************************/
//*********************************************************************/
void preproc_loadBlob(const char * file, struct sline * s) {

  
   
	FILE * fi=fopen(file, "rb"); 
	if ( fi == NULL) { 
		fprintf(stderr,"::: ERROR: I cannot upload the binary file %s\n",file);
		exit(EXIT_FAILURE);
	}
	
	
	fseek (fi , 0 , SEEK_END);
	long lSize = ftell (fi);
	rewind (fi);
	
	if ( lSize > 65535 ) {
		fprintf(stderr,"::: ERROR: I cannot upload the a binary file so big as %s\n",file);
		exit(EXIT_FAILURE);
	}
	
	// allocate memory to contain the whole file:
	s->code = (uint8_t*) malloc (sizeof(uint8_t)*(lSize+1));
	if (s->code == NULL) {
		fprintf(stderr,"::: ERROR: Out of memory uploading the Binary file %s\n",file);
		exit(EXIT_FAILURE);
	}
		
	// copy the file into the buffer:
	int result = fread (s->code,1,lSize,fi);
	if (result != lSize) {
		fprintf(stderr,"::: ERROR: Reading error the binary file %s\n",file);
		exit(EXIT_FAILURE);
	}
	s->codesize = lSize;
	

 	fclose (fi);
 

}
