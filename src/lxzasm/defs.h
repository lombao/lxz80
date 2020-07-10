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
 
/* General definitions */
  
/* This sets the maximun number of lines it can assemble */ 
#define MAX_NUMBER_LINES 30000


/* This one defines the maximun size of a label or constant */
#define MAX_SIZE_LABEL 50

/* This one defines the maximun number of labels that can be defined in one single program */
#define MAX_NUM_LABELS 1000 


/* This one define the maximun size of a file name */
#define MAX_SIZE_FILE_NAME 100

/* Max size of an asm line */ 
#define MAX_SIZE_ASM_LINE 200

/* */
#define MAX_SIZE_CODE_LINE 32500


/* DEFAULT OUTPUT NAME */
#define DFT_OUTPUT_FILE "a.z80"
#define DFT_OUTPUT_LST_FILE "output.lst"

/* MAx size of addressable memory */
#define MAX_SIZE_RAM 65535

/* */
#define FALSE 0
#define TRUE 1



/* Version */
#define LXZ80_VERSION "0.0.12"
