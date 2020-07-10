

struct sline {
		struct sline * next;
		struct sline * prev;
		char parsed[MAX_SIZE_ASM_LINE+1];    /* parsed line */
		char line[MAX_SIZE_ASM_LINE+1];		 /* orig line */
		char filename[MAX_SIZE_FILE_NAME+1]; /* name of file source */
		int nline;                           /* orig number of line in file source */
		int address;						 /* also known as the PC, the address in mem */
		uint8_t * code;
		uint8_t   codesize;
		char *    codehex;
		
};


struct spreproc {
	char * title ;
	int    org   ;
	int    limit ;
};
