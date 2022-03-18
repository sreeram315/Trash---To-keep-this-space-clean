#include<reg51.h>
#include<stdio.h>
sbit rs=P1^2; sbit rw=P1^1;	sbit en=P1^0;
sbit trig=P0^0; sbit echo=P0^1;
unsigned char i;
void delay(int time)
{
	int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<=1275;j++);
}

void _10usdelay()
{
	i=10;i=10;i=10;i=10;i=10;
	i=0;i=0;i=0;i=0;i=0;
	i=9;i=0;
}

void lcd_cmd(unsigned char x)
{
	rs=0;
	rw=0;
	P2=x;
	en=1;
	delay(1);
	en=0;
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
	rs=1;
	rw=0;
	P2=x;
	en=1;
	delay(1);
	en=0;
}

void main()
{
	unsigned char a,a1,a2;
	while(1){
	lcd_ini();
	a=38;
	a1=a%10;
	a1=a1+0x30;
	a2=a/10;
	a2=a2+0x30;
	lcd_data(a2);
	lcd_data(a1);
	delay(20);
	}
}
