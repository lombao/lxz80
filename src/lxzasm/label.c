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
 
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "defs.h"
 
/* Data structs */
struct Sentrylabel {
	     char label[MAX_SIZE_LABEL];
	     int  value;
} TableLabels[MAX_NUM_LABELS];
uint pointerTableLabels = 0;	   


/* External declarations */
extern int pass;
extern int condStatus;
extern void labelSizeError(const char * label);
extern void labelExhaustedError();
extern void labelAlreadyDefinedError(const char * label);

/* Local declarations */
int LookupTableLabels(const char * label);
int getLabelValue(const char * label, uint * k );
int setLabelAddress(const char * label, const int pc);
int setLabelValue(const char * label, const int val);
char * getDefinedLabels();
  

/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/

/* returns the position in the Table of labels, -1 if not found */
int LookupTableLabels(const char * label) {
	uint a;
	if ( strlen(label) > MAX_SIZE_LABEL) {
		labelSizeError(label);
	}
	for (a=0;a<pointerTableLabels;a++) {
		if ( strncmp(label,TableLabels[a].label, MAX_SIZE_LABEL) == 0 ) {
			return a;
		}
	}
	return -1;
}

int setLabelAddress(const char * label, const int pc) {
  
  if ( !condStatus ) { return 0; }
  
  if ( pointerTableLabels == MAX_NUM_LABELS) {
	  labelExhaustedError();
  }
  
  if ( strlen(label) > MAX_SIZE_LABEL) {
	  labelSizeError(label);
  }
  
  if (LookupTableLabels(label) != -1) {
	  if (pass == 1) {
	    /* it is already defined, get out */
	    labelAlreadyDefinedError(label);
	    return -1;
      }
      else { /* if 2nd pass this is the expected */
		  return 0;
      }		  
  }
  TableLabels[pointerTableLabels].value = pc;
  strncpy(TableLabels[pointerTableLabels].label, label,MAX_SIZE_LABEL);
  pointerTableLabels++;
  return 0;	
}

int setLabelValue(const char * label, const int val) {
  
  
  if ( !condStatus ) { return 0; }
  
  
  if ( pointerTableLabels == MAX_NUM_LABELS) {
	  labelExhaustedError();
  }
  
  if ( strlen(label) > MAX_SIZE_LABEL) {
	  labelSizeError(label);
  }
  
  if (LookupTableLabels(label) != -1) {
	  if (pass == 1) {
	    /* it is already defined, get out */
	    labelAlreadyDefinedError(label);
	   }
      else { /* if 2nd pass this is the expected */
		  return 0;
      }		  
  }
  TableLabels[pointerTableLabels].value = val;
  strncpy(TableLabels[pointerTableLabels].label, label,MAX_SIZE_LABEL);
  pointerTableLabels++;
  return 0;	
}



int getLabelValue(const char * label, uint * k) {
 uint a;
	
	
  if ( !condStatus ) { return 0; }
  
	
	if ( strlen(label) > MAX_SIZE_LABEL) {
	  labelSizeError(label);
    }
  	
	for (a=0;a<pointerTableLabels;a++) {
		if ( strncmp(label,TableLabels[a].label, MAX_SIZE_LABEL) == 0 ) {
			*k = TableLabels[a].value;
			return 0;
		}
	}
	return -1;
}


char * getDefinedLabels() {
	uint a;
	char l[80];
	char * output = NULL;
	int size = 0;

	
	for (a=0;a<pointerTableLabels;a++) {
	    if (output == NULL ) { size = 0; } else { size = strlen(output); }
		sprintf(l,"LABEL: %50s ==> \tVALUE: %04x\n",TableLabels[a].label,TableLabels[a].value);
		output = realloc(output,( (output==NULL)?strlen(l)+1:(size+strlen(l)+1) ) );
		if (size == 0) { output[0] = 0x0; }
		strcat(output,l);

		
	}
	return output;
}
