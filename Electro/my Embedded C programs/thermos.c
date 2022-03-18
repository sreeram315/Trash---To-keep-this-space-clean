#include<reg51.h>
#include<stdio.h>
#include <math.h>
sbit rs_lcd = P0^2;	
sbit rw_lcd = P0^1;
sbit en_lcd = P0^0;
sbit chip_select = P0^3;
sbit rd_adc = P0^4;
sbit wr_adc = P0^5;
sbit intr = P0^6;
unsigned char i,j;
void delay(int time)
{
	int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<=1275;j++);
}
void lcd_cmd(unsigned char x)
{
	rs_lcd=0;
	rw_lcd=0;
	P2=x;
	en_lcd=1;
	delay(1);
	en_lcd=0;
}

void lcd_ini()
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
	lcd_cmd(0x80);
}

void lcd_data(unsigned char x)
{
	rs_lcd=1;
	rw_lcd=0;
	P2=x;
	en_lcd=1;
	delay(1);
	en_lcd=0;
}
	
void convertprint(unsigned char x)
{
	unsigned char x1,x2,x3;
	lcd_cmd(0xC0); 
	x1=x/10;
	x1=x1+(0x30);
	x2=x%10;
	x2=x2+(0x30);
	x3=0xDF;
	lcd_data(x1);
	lcd_data(x2);
	lcd_data(x3);
	lcd_data('C');
}

void main()
{
	
	unsigned char value;
	unsigned char a[]="TEMPARATURE: ";
	chip_select=1;
	P1=0xFF;
	P2=0x00;
	lcd_ini();
	i=0;
	for(i=0;i<13;i++)
	{
		lcd_data(a[i]);
		delay(1);
	}
	intr=1;
	rd_adc = 1;
	wr_adc=1;
	while(1)
	{
		wr_adc = 0;
		delay(1);
		wr_adc = 1;
		while(intr==1);
		rd_adc = 0;
		value=P1;
		convertprint(value);
		delay(100);
		rd_adc = 1;	
	}
}
