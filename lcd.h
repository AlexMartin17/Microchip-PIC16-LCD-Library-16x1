#include <pic.h>
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>


#define RS RA3
#define EN RA2
#define D0 RB0
#define D1 RB1
#define D2 RB2
#define D3 RB3
#define D4 RB4
#define D5 RB5
#define D6 RB6
#define D7 RB7

#define _XTAL_FREQ 4000000


void Port(char a)
{
	if(a & 1)
		D0 = 1;
	else 
		D0 = 0;
	
	if(a & 2)
		D1 = 1;
	else
		D1 = 0;
	
	if(a & 4)
		D2 = 1;
	else
		D2 = 0;
	
	if(a & 8)
		D3 = 1;
	else
		D3 = 0;
	
	if(a & 16)
		D4 = 1;
	else
		D4 = 0;

	if(a & 32)
		D5 = 1;
	else
		D5 = 0;
	
	if(a & 64)
		D6 = 1;
	else 
		D6 = 0;
	
	if(a & 128)
		D7 = 1;
	else
		D7 = 0;
}
void Cmd(char a)
{ 
  RS = 0;             // => RS = 0
  Port(a);             //Data transfer
  EN  = 1;             // => E = 1
  __delay_ms(5);
  EN  = 0;             // => E = 0
}

void Clear_Display()
{
	  Cmd(1);
}
// Sets the cursor at the begining
void Set_Cursor1() {
    
    Cmd(0x80);
}
// Sets the cursor after first 8 chars
void Set_Cursor2()
{
	  Cmd(0x80 + 0x40);
}

void Init()
{
  Port(0x00);
  RS = 0;
  __delay_ms(25);
  Cmd(0x30);
   __delay_ms(5);
  Cmd(0x30);
  __delay_ms(15);
  Cmd(0x30);
  Cmd(0x38);
  Cmd(0x0C);
  Cmd(0x01);
  Cmd(0x06); 
}

void Write_Char(char a)
{
   RS = 1;
   Port(a);
   EN  = 1;
  __delay_ms(4);
   EN  = 0;
}
// For chinese display 16x1 splitted to 2x8 columns in 1 row
void Write_String8x2(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++) {
        if (i>=8) {
            Set_Cursor2();
            Write_Char(a[8]);
            Write_Char(a[9]);
            Write_Char(a[10]);
            Write_Char(a[11]);
            Write_Char(a[12]);
            Write_Char(a[13]);
            Write_Char(a[14]);
            Write_Char(a[15]);
        } else {
            Write_Char(a[i]);
        }
        
    }
}
// For regular 16x1 display
void Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++) {

        Write_Char(a[i]);
        
    }
}

void Shift_Right()
{
	Cmd(0x1C);
}

void Shift_Left()
{
	Cmd(0x18);
}