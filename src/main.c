// LCD Interface V1 by Alex-Martin K. Lakovski
// Build on PIC16F877A (Register bits may vary on different chip models)

#include <stdlib.h>
#include <stdio.h>
#include <pic.h>
#include "lcd.h"
#include <xc.h>

#define _XTAL_FREQ 4000000

void main(void) {
	// Values based on PIC16F877A with 4MHz external osc
   TRISA = 0x00; 
   TRISB = 0x00;
   CMCON = 0b111;
   
   Init();
  
   while(1)
  {
	   //Write_String8x2("0123456789ABCDEF") 	// For chinese display
       Write_String("0123456789ABCDEF");
  }
}