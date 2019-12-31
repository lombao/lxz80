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


#define LXZ80_VERSION LXZ80VERSION

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

void read_ram(const uint16_t addr, uint8_t * v);
void write_ram(const uint16_t addr, const uint8_t * v);
void read_io(const uint16_t addr, uint8_t * v);
void write_io(const uint16_t addr);


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
		printf ("REG A Initialized to %02Xh\n",init.regA);
		z80_write_reg_a(init.regA);	
	}
	if (init.flagB) {	
		printf ("REG B Initialized to %02Xh\n",init.regB);
		z80_write_reg_b(init.regB);	
	}
	if (init.flagC) {	
		printf ("REG C Initialized to %02Xh\n",init.regC);
		z80_write_reg_c(init.regC);	
	}
	if (init.flagD) {	
		printf ("REG D Initialized to %02Xh\n",init.regD);
		z80_write_reg_d(init.regD);	
	}
	if (init.flagE) {	
		printf ("REG E Initialized to %02Xh\n",init.regE);
		z80_write_reg_e(init.regE);	
	}
	if (init.flagH) {	
		printf ("REG H Initialized to %02Xh\n",init.regH);
		z80_write_reg_h(init.regH);	
	}
	if (init.flagL) {	
		printf ("REG L Initialized to %02Xh\n",init.regL);
		z80_write_reg_l(init.regL);	
	}
}


/**********************************************************************/
/* Mandatory setup of the Z80 Library                                 */
void read_ram(const uint16_t addr, uint8_t * v) {
	*v = ram[addr];
}

void write_ram(const uint16_t addr, const uint8_t * v) {
	ram[addr] = *v;
}

/* We do not do anything with I/O */
/* but we create the callback just in case */
void read_io(const uint16_t addr, uint8_t * v) {
	printf(":: Warning, detected IO Read to address: %04Xh\n",addr);
	*v = 0;	
}

void write_io(const uint16_t addr) {
	printf(":: Warning, detected IO Write to address: %04Xh\n",addr);
}

/*** MAIN *************************/ 
int main(int argc, char *argv[])
{

  char objectfile[500];
  struct timespec tpstart;
  struct timespec tpend;
 
	/* Prepare */
	parseParameters(argc,argv,objectfile);
	uploadRam(objectfile);
	
	/* Init Z80 */
	z80_init( init.clock, read_io, write_io, read_ram , write_ram );
	
	/* preset some Registers if defined */
	initializeRegisters();
	
	/* Here we go */
	/* this will keep running until a HALT instruction */
	clock_gettime(CLOCK_REALTIME,&tpstart);	
	z80_run();
	clock_gettime(CLOCK_REALTIME,&tpend);

	/* Print Execution Report */
	printf("\nOUPUT:\n");
	printf("--------------------------------------------\n");
	printf("| Total TS Cycles: %ld with a Clock at %d Mhz \n",z80_show_totalts(),init.clock);
	printf("| Real time:       %ld seconds %ld miliseconds\n",tpend.tv_sec - tpstart.tv_sec, (tpend.tv_nsec - tpstart.tv_nsec)/1000000 );
	printf("-------------------------\n");
	printf("| A | F | B | C |  H L  |\n");
	printf("|-------|-------|-------|\n");
	printf("| %04Xh | %04Xh | %04Xh |\n",z80_show_af(),z80_show_bc(),z80_show_hl());
	printf("|-------|-------|-------|\n");
	printf("        | D | E |  I X  |\n");
	printf("        |-------|-------|\n");
	printf("        | %04Xh | %04Xh |\n",z80_show_de(),z80_show_ix());
	printf("        |-------|-------|\n");
	printf("                |  I Y  |\n");
	printf("                |-------|\n");
	printf("                | %04Xh |\n",z80_show_iy());
	printf("                |-------|\n");
	
} 
