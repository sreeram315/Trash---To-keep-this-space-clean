#include<reg51.h>
#include<stdio.h>
#include<intrins.h>

sbit rs=P1^2; sbit rw=P1^1;	sbit en=P1^0;
sbit trig=P0^0; sbit echo=P0^1;
void lcd_data(unsigned char x);
unsigned char i=0,j;
void delay(int time)
{
	int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<=1275;j++);
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
	en=0;
}

void lcd_string(unsigned char *str)
{
	i=0;
	while(str[i] != '\0')
	{
		lcd_data(str[i]);
		i++;
	}
}

void trigger()
{
	
	trig=1;
	delay(10);
	trig=0;
}

void main()
{
	int time;
	TR0=1;
	P2=0x00;
	P1=0x00;
	P0=0x02;
	lcd_ini();
	lcd_string("Starting now");
	TMOD=0x01;
	trig=0;
	while(1)
	{
	lcd_ini();
	lcd_string("Distance is:");
	TR0=0;
	TH0=0x00;
	TL0=0x00;
	trigger();
	while(echo==0);
	TR0=1;
	while(echo==1);
	TR0=0;
	time= ((TH0<<8)|TL0);
		if(time<150){
			lcd_cmd(0xC0);
			lcd_string("Too near");}
		else{
	time=time/59;
	if(time<35000)
	{
		delay(10);
		lcd_cmd(0xC0);
		lcd_data((time/100) + 0x30);
		lcd_data(((time/10)%10) + 0x30);
		lcd_data((time%10) + 0x30);
		lcd_string("cm");
		delay(10);
	}
	else
	{
		lcd_ini();
		lcd_string("OBJECT OUT OF RANGE");
	}}delay(100);
}
}