// LCD Interface V1 by Alex-Martin K. Lakovski

#include <stdlib.h>
#include <stdio.h>
#include <pic.h>
#include "lcd.h"
#include <xc.h>


#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)



#define _XTAL_FREQ 4000000

void main(void) {
   TRISA = 0x00; 
   TRISB = 0x00;
   CMCON = 0b111;
   
   Lcd8_Init();
  
   while(1)
  {
       Lcd8_Write_String("Bigger than 8ddd");
  }
}