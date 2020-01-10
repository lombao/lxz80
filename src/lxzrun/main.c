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
 
#include <lxz80.h>

#include <stdio.h> 
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>


uint8_t ram[64 * 1024];

struct {
	uint8_t regA;
	uint8_t flagA;
	
	uint8_t regB;
	uint8_t flagB;
	
	uint8_t regC;
	uint8_t flagC;
	
	uint8_t regD;
	uint8_t flagD;
	
	uint8_t regE;
	uint8_t flagE;
	
	uint8_t regH;
	uint8_t flagH;
	
	uint8_t regL;
	uint8_t flagL;
	
	uint8_t clock;
} init = { 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0 ,1 };


/**********************************************************************/
/* Internally defined functions */
void showUsage();
void parseParameters(int argc, char *argv[], char * objectfile);
void uploadRam(char * file);
void initializeRegisters();

void io(struct z80interface * interface);


/**********************************************************************/
/* Print usage                                                        */
void showUsage() {
	 fprintf(stderr,"LXZ80 Run. Version %s\n\n",LXZ80_VERSION); 
	 fprintf(stderr,"Usage: lxzrun [-v] [ -h] [ -c] [ -<REG> <val> ] objectfile \n");
	 fprintf(stderr,"	v:  Show Version\n");
	 fprintf(stderr,"	h:  Show Help ( this help )\n");
	 fprintf(stderr,"	c:  Clock in Mhz ( default is 1 Mhz )\n");
 	 fprintf(stderr,"	A:  Preload reg A with <val>\n");
 	 fprintf(stderr,"	B:  Preload reg B with <val>\n"); 
 	 fprintf(stderr,"	C:  Preload reg C with <val>\n");
 	 fprintf(stderr,"	D:  Preload reg D with <val>\n"); 
 	 fprintf(stderr,"	E:  Preload reg E with <val>\n");
 	 fprintf(stderr,"	H:  Preload reg H with <val>\n"); 
 	 fprintf(stderr,"	L:  Preload reg L with <val>\n"); 
	 fprintf(stderr,"	objectfile:  File to be run\n");
}

/**********************************************************************/
/* Parse command line inputs                                          */
void parseParameters(int argc, char *argv[], char * objectfile) {

 int opt;
 
	if (argc==1) { 
		fprintf(stderr, "::: %s: No input files\n",argv[0]);
		showUsage();
		exit(EXIT_FAILURE);
	}
  
	while ((opt = getopt(argc, argv, "A:B:C:D:E:H:L:c:vh")) != -1) {
		switch (opt) {
			case 'A':
				init.regA = atoi(optarg);
				init.flagA = 1;
				break;
			case 'B':
				init.regB = atoi(optarg);
				init.flagB = 1;
				break;
			case 'C':
				init.regC = atoi(optarg);
				init.flagC = 1;
				break;
			case 'D':
				init.regD = atoi(optarg);
				init.flagD = 1;
				break;
			case 'E':
				init.regE = atoi(optarg);
				init.flagE = 1;
				break;
			case 'H':
				init.regH = atoi(optarg);
				init.flagH = 1;
				break;
			case 'L':
				init.regL = atoi(optarg);
				init.flagL = 1;
				break;
			case 'v':
				showUsage();
				exit(EXIT_SUCCESS);
				break;  
			case 'c':
				init.clock = atoi(optarg);
				break;  
			case 'h': /* Show version and quit */
				showUsage();
				exit(EXIT_SUCCESS);
				break;
			default: /* '?' */
				fprintf(stderr,"::: Unknown option used\n");
				showUsage();
				exit(EXIT_FAILURE);
		}
	}
  
	if (argc==optind) { 
		fprintf(stderr, "::: %s: No object file to run\n",argv[0]);
		showUsage();
		exit(EXIT_FAILURE);
	} 
   
	strcpy(objectfile,argv[optind]);	
}


void uploadRam(char * file) {
	
	FILE * fd=fopen(file, "rb"); 
	if ( fd == NULL) { 
		fprintf(stderr,"::: Could not upload the object file. It does not exist or I have no permissions: %s\n",file);
		exit(EXIT_FAILURE);
	}
	fread(ram,1,64*1024,fd);
	fclose(fd);

}	

/**********************************************************************/
/* Initialize Z80 Registers if requested							  */
/* this must be executed AFTER the z80 init                           */
void initializeRegisters() {

	if (init.flagA) {	
		z80_init_reg_a(init.regA);	
	}
	if (init.flagB) {	
		z80_init_reg_b(init.regB);	
	}
	if (init.flagC) {	
		z80_init_reg_c(init.regC);	
	}
	if (init.flagD) {	
		z80_init_reg_d(init.regD);	
	}
	if (init.flagE) {	
		z80_init_reg_e(init.regE);	
	}
	if (init.flagH) {	
		z80_init_reg_h(init.regH);	
	}
	if (init.flagL) {	
		z80_init_reg_l(init.regL);	
	}
}


/**********************************************************************/
/* Mandatory setup of the Z80 Library                                 */
void io (struct z80interface * interface) {
		
		switch(interface->type) {
			case 0: interface->busdata = ram[interface->busaddr];
					break;
			case 1: ram[ interface->busaddr ] = interface->busdata;
					break;
			case 2: printf(":: Warning, detected IO Read to address: %04Xh\n",interface->busaddr);
					break;
			case 3: printf(":: Warning, detected IO Write to address: %04Xh\n",interface->busaddr);
					break;
		}
}



/*** MAIN *************************/ 
int main(int argc, char *argv[])
{

  char objectfile[500];
  struct timespec tpstart;
  struct timespec tpend;
  struct z80interface interface;
  
	/* Prepare */
	parseParameters(argc,argv,objectfile);
	uploadRam(objectfile);
	
	/* Init Z80 */
	interface.clock = init.clock;
	interface.io    = io;
	
	z80_init( &interface );
	
	/* preset some Registers if defined */
	initializeRegisters();
	
	/* Here we go */
	/* this will keep running until a HALT instruction */
	clock_gettime(CLOCK_REALTIME,&tpstart);	
	z80_run();
	clock_gettime(CLOCK_REALTIME,&tpend);

	/* error checking */
	if ( interface.error.number != 0 ) {
		printf("Detected a problem: Error %d\n",interface.error.number);
		printf("         PC: %04Xh\n",interface.error.pc);
	}
	
	/* read the values of the registers */
	z80_readstatus();
	
	
	/* Print Execution Report */
	printf("\n");
	printf("--------------------------------------------\n");
	printf("| Total TS Cycles: %ld with a Clock at %d Mhz \n",interface.totalts,init.clock);
	printf("| Real time:       %ld seconds %ld microseconds\n",tpend.tv_sec - tpstart.tv_sec, (tpend.tv_nsec - tpstart.tv_nsec)/1000 );
	printf("--------------------------------------------\n");
	
	printf(" AF: %04Xh 	BCPLUS: %04Xh \n",interface.registers.AF,interface.registers.AFPLUS);
	printf(" BC: %04Xh 	BCPLUS: %04Xh \n",interface.registers.BC,interface.registers.BCPLUS);
	printf(" DE: %04Xh 	DEPLUS: %04Xh \n",interface.registers.DE,interface.registers.DEPLUS);
	printf(" HL: %04Xh 	HLPLUS: %04Xh \n",interface.registers.HL,interface.registers.HLPLUS);
	printf(" IX: %04Xh \n",interface.registers.IX);
	printf(" IY: %04Xh \n",interface.registers.IY);
	printf(" SP: %04Xh 	PC: %04Xh \n",interface.registers.SP,interface.registers.PC);
	
	
} 
