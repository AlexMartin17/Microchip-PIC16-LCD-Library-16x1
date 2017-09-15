// LCD Interface V1 by Alex-Martin K. Lakovski

#include <stdlib.h>
#include <stdio.h>
#include <pic.h>
#include "lcd.h"
#include <xc.h>

#define _XTAL_FREQ 4000000

void main(void) {
   TRISA = 0x00; 
   TRISB = 0x00;
   CMCON = 0b111;
   
   Init();
  
   while(1)
  {
       Write_String("Bigger than 8ddd");
  }
}