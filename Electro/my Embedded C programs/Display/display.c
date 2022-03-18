// # proprietary to BEERA // DO NOT COPY
// Program for LCD Interfacing with 8051 Microcontroller (AT89S52) 

#include<reg51.h>
#define display_port P2      //Data pins connected to port 2 on microcontroller
sbit rs = P0^2;  						//RS pin connected to pin 2 of port 3
sbit rw = P0^3;  						// RW pin connected to pin 3 of port 3
sbit e =  P0^4;  						//E pin connected to pin 4 of port 3

void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}
void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD
{
    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}

void lcd_data(unsigned char disp_data)  //Function to send display data to LCD
{
    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}

 void lcd_start()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01);  //clear screen
    msdelay(10);
    lcd_cmd(0x80);  // bring cursor to position 1 of line 1
    msdelay(10);
}

 void lcd_start2()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    //lcd_cmd(0x0F);  // turn display ON, cursor blinking
    //msdelay(10);
    //lcd_cmd(0x01);  //clear screen
    //msdelay(10);
    lcd_cmd(0xC0);  // bring cursor to position 1 of line 2
    msdelay(10);
	  
} 

void main()
{
	while(1)
	{
    unsigned char a[25]="GURU BHAI AVYA CHE",b[25]="DUM DADAKA KREYA CHE";    //string of 14 characters with a null terminator.
    int l=0,m=0;
    lcd_start();
    while(a[l] != '\0') // searching the null terminator in the sentence
    {
        lcd_data(a[l]);
        l++;
        msdelay(15);
    }
		lcd_start2();
		while(b[m] != '\0')
		{
			lcd_data(b[m]);
			m++;
			msdelay(15);
		}
	}
}

 