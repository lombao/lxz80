
#include <stdio.h> 
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

#include "defs.h"

struct sline {
		struct sline * next;
		struct sline * prev;
		char parsed[MAX_SIZE_ASM_LINE+1];
		char line[MAX_SIZE_ASM_LINE+1];
		char filename[MAX_SIZE_FILE_NAME+1];
		int nline;
};


struct sline * slines		= NULL;
struct sline * slinesidx	= NULL;


//----------------------------------------------------------------------
/* the preproc results */
struct {
	char * title ;
	int    org   ;
	int    limit ;
} preproc;





//----------------------------------------------------------------------
// INTERNAL
struct sline * preproc_uploadFile(const char * file);
FILE * preproc_writeFile();
void preproc_setslines(  struct sline * s );
void preproc_proc();
void preproc_trimWhiteSpaces();
void preproc_removeComments();
void preproc_directive_title();
void preproc_directive_org();
void preproc_directive_limit();

char *  preproc_util_extractliteral( char * s  );
int  preproc_util_extractnumber( char * s  );


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
	preproc_trimWhiteSpaces();
	preproc_removeComments();
	preproc_directive_title();
	preproc_directive_org();
	preproc_directive_limit();

}


//*********************************************************************/
//*********************************************************************/
void preproc_trimWhiteSpaces() {
	
	struct sline * s = slines;
    char * kk;
    
	while(s != NULL) {	
		int a = 0;
		while(s->parsed[a] == ' ' || s->parsed[a] == '\t') { a++; }
		kk = strdup(&s->parsed[a]);
		strcpy(s->parsed,kk);
		free(kk);
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


