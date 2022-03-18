
#define MY_LCD_H
//define pin config.for LCD 
 #define rs PC0    						//rs=register select 0 for comm. 1 for Data
 #define rw PC1    						//rw=read/write to LCD 1 for read and 0 for write
 #define en PC2    						//enable lcd 1 or disable lcd 0 lcd prepare for geting data
 int pos;
 #define MRP 0

 //define function
void lcd_number(unsigned int val);
 void lcd_init();							//initialisation for lcd
 void lcd_clear();
 void lcd_efmodeC(char);   				//function for sending 8bit data in 4 bit mode
 void lcd_efmodeD(char); 
 void lcd_com(char);						//function for sending comm line
 void lcd_data(char); 					//usre data
 void lcd_printc(unsigned char *str);
 void lcd_printnum(long signed int);
 void lcd_gotoxy(int,int);				// goto row or coll possition

//Function declaration

//LCD init
 void lcd_init()
 {
	//lcd_efmodeC(0x01);		//clear LCD
	DDRC=0xff;
	lcd_efmodeC(0x02);		//initialization, for 4 bit mode
	
	lcd_efmodeC(0x28);		//selecting data is writen in CGRAM or DDRAM
		
	lcd_efmodeC(0x06);		//Sets mode to increment the
							//address by one and to shift the
							//cursor to the right at the time of
							//write to the DD/CGRAM.
							//Display is not shifted.
	
	lcd_efmodeC(0x0C);		//Turns on display and cursor.
							//Entire display is in space mode		
	
 }


//LCD 8bit to 4 bit mode for command
void lcd_efmodeC(char val)
{
   char div;
	
	div = val & 0xF0;		//mask lower nibble because PA4-PA7 pins are used. 
	lcd_com(div);			// send to LCD
 
	div = ((val<<4) & 0xF0);	//shift 4-bit and mask
	lcd_com(div);	

}
//LCD 8bit to 4 bit mode for data
void lcd_efmodeD(char val1)
{
   char div1;
	div1 = val1 & 0xF0;		//mask lower nibble because PA4-PA7 pins are used. 
	lcd_data(div1);			// send to LCD
 
	div1 = ((val1<<4) & 0xF0);	//shift 4-bit and mask
	lcd_data(div1);	
	
}

//LCD command line
 void lcd_com(char val2)
 {
	PORTC=val2;
	PORTC&=~(1<<rs);
	PORTC&=~(1<<rw);
	PORTC|=(1<<en);
	_delay_ms(1);
	PORTC&=~(1<<en);
 }

 //LCD DATA line
 void lcd_data(char val3)
 {
	PORTC=val3;
	PORTC|=(1<<rs);
	PORTC&=~(1<<rw);
	PORTC|=(1<<en);
	_delay_ms(1);
	PORTC&=~(1<<en);


 }

//LCD cursor possition
 void lcd_gotoxy(int x,int y)
 {
	pos=15-x;
	int xk=0x80,yk=0xC0;	
	if(y==1)
	{
	lcd_efmodeC(0xC0);
	yk = x | 0xC0;
    lcd_efmodeC(yk);
  	}
	else
	{
	xk = x | 0x80;
    lcd_efmodeC(xk);
	}
 } 

 //LCD print
 void lcd_printc(unsigned char *data0)
 {
	 int i=0;
	 while(data0[i]!='\0')
		{
		if(i<16){lcd_efmodeD(data0[i]);_delay_ms(MRP);}

		if(i == pos){lcd_efmodeC(0xC0);}

		if(i>15){lcd_efmodeD(data0[i]);_delay_ms(MRP);}
		i++;
		}
 }

//LCD number
void lcd_printnum(long signed int val)
{	
	
	char s;
	lcd_efmodeC(0x04);
	
	s=val%10;
	lcd_efmodeD(48+s);
  	val=val/10;
	s=val%10;
	lcd_efmodeD(48+s);
	lcd_efmodeC(0x06);
	}
void lcd_number(unsigned int val)
{	
	char s;
	lcd_efmodeC(0x04);
	if(val==0)
	lcd_efmodeD(48+val);
	while(val!=0)
	{
	s=val%10; 
	lcd_efmodeD(48+s);	
	val=val/10;
	}
	lcd_efmodeC(0x06);
	}
//LCD clear
void lcd_clear()
	{
	lcd_efmodeC(0x01);
	_delay_ms(200);
	}
