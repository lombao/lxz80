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

#define VERSION "0.0.4"

uint8_t ram[64 * 1024];

struct {
	uint8_t regA;
	uint8_t flagA;
} init = { 0,0 };


/**********************************************************************/
/* Internally defined functions */
void showUsage();
void parseParameters(int argc, char *argv[], char * objectfile);
void uploadRam(char * file);
void read_ram(const uint16_t addr, uint8_t * v);
void write_ram(const uint16_t addr, const uint8_t * v);
void read_io(const uint16_t addr, uint8_t * v);
void write_io(const uint16_t addr);


/**********************************************************************/
/* Print usage                                                        */
void showUsage() {
	 fprintf(stderr,"LXZ80 Run. Version %s\n\n",VERSION); 
	 fprintf(stderr,"Usage: lxzrun [-v] [ -h] [ -a <val> ] objectfile \n");
	 fprintf(stderr,"	v:  Show Version\n");
	 fprintf(stderr,"	h:  Show Help ( this help )\n");
 	 fprintf(stderr,"	a:  Preload reg A with <val>\n");
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
  
	while ((opt = getopt(argc, argv, "a:lh")) != -1) {
		switch (opt) {
			case 'a':
				init.regA = atoi(optarg);
				init.flagA = 1;
				break;
			case 'v':
				showUsage();
				exit(EXIT_SUCCESS);
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
void read_ram(const uint16_t addr, uint8_t * v) {
	*v = ram[addr];
}

void write_ram(const uint16_t addr, const uint8_t * v) {
	ram[addr] = *v;
}

/* We do not do anything with I/O */
/* but we create the callback just in case */
void read_io(const uint16_t addr, uint8_t * v) {
}

void write_io(const uint16_t addr) {
}

/*** MAIN *************************/ 
int main(int argc, char *argv[])
{

  char objectfile[500];
  
	parseParameters(argc,argv,objectfile);
	uploadRam(objectfile);
	
	/* 4Mhz , and the callbacks declared */
	z80_init( 4, read_io, write_io, read_ram , write_ram );
	printf("RUNNING....\n");
	if (init.flagA) {	
		printf ("REG A Initialized to %2x\n",init.regA);
		z80_write_reg_a(init.regA);	
	}
	
	/* Here we go */
	/* this will keep running until a HALT instruction */
	z80_run();
	
	printf("\nDONE.. OUPUT:\n");
	printf("----------------------\n");
	printf("Total TS Cycles: %li\n",z80_show_totalts());
	printf("REG AF: %04xH\n",z80_show_af());
	printf("REG BC: %04xH\n",z80_show_bc());
	printf("REG DE: %04xH\n",z80_show_de());
	printf("REG HL: %04xH\n",z80_show_hl());
	printf("REG IX: %04xH\n",z80_show_ix());
	printf("REG IY: %04xH\n",z80_show_iy());
	
	
	
} 
