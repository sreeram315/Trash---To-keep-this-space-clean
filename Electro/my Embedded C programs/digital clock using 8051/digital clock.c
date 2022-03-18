
#include<reg51.h>
#include<absacc.h>
#define dataport P2
#define port P1
#define lcdport P3
 sbit reset = port^0;
 sbit rs =port^1;
 sbit rw =port^2;
 sbit e = port^3;
 sbit dig_hr1=port^4;
 sbit dig_min1=port^5;
 sbit start=port^6;
 int  min1=0,hr1=0;
 int min0=60,hr0=25;
 unsigned char temp=60,hr,min,sec,num[60]={0x00,0x01,0x02,
	 0x03,0x04,0x05,0x06,0x07,0x08,0X09,0X10,0X11,0X12,0X13,
	 0X14,0X15,0X16,0X17,0X18,0X19,0X20,0X21,0X22,0X23,0X24,
	 0X25,0X26,0X27,0X28,0X29,0X30,0X31,0X32,0X33,0X34,0X35,
	 0X36,0X37,0X38,0X39,0X40,0X41,0X42,0X43,0X44,0X45,0X46,
	 0X47,0X48,0X49,0X50,0X51,0X52,0X53,0X54,0X55,0X56,0X57,
	 0X58,0X59};

 void delay(unsigned int msec )
{
	int i ,j ;
	for(i=0;i<msec;i++)
	for(j=0; j<1275; j++);
}

void lcd_cmd(unsigned char item)
{
	dataport = item;
	rs= 0;
	rw=0;
	e=1;
	delay(1);
	e=0;
	return;
} 

// function to send data
void lcd_data(unsigned char item)
{
	dataport = item;
	rs= 1;
	rw=0;
	e=1;
	delay(1);
	e=0;
	return;
}

void lcd_string(unsigned char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		lcd_data(str[i]);
		i++;
		delay(1);
	}
	return; 
}

lcd_int(int time_val)
{
	int int_amt;
	int_amt=time_val/10;
	lcd_data(int_amt+48);
	int_amt=time_val%10;	 
	lcd_data(int_amt+48);
}


void lcd()
{
	lcd_cmd(0x38);		   
	delay(5);
	lcd_cmd(0x0C);        
	delay(5);
	lcd_cmd(0x80);
	delay(5);
}

void set_rtc_time()  
{
	XBYTE[10]=0x20;
	XBYTE[11]=0x82;
	XBYTE[0]=0x00;
	XBYTE[2]=min;
	XBYTE[4]=hr;
	XBYTE[7]=0x01;
	XBYTE[8]=0x01;
	XBYTE[9]=0x10;
	XBYTE[1]=0xFF;
	XBYTE[3]=0xFF;
	XBYTE[5]=0xFF;
	XBYTE[11]=0x22;
}

void set_hr1()
{
	hr1++;
	if(hr1>23)
	hr1=0;
	lcd_cmd(0xc3);
	lcd_int(hr1);
	lcd_data(':');
	hr0=hr1;
}

void set_min1()
{
	min1++;
	if(min1>59)
	min1=0;
	lcd_cmd(0xc6);
	lcd_int(min1);
	min0=min1;
}

void set_time()	interrupt 2
{
	lcd_cmd(0x01);
	if(start==0)
	{
		lcd_string("SET TIMING");
		lcd_cmd(0xc3);
		lcd_int(hr1);
		lcd_data(':');
		lcd_int(min1);
		while(start==0)
		{
			delay(10);
			if(dig_hr1==0)
			set_hr1();
			if(dig_min1==0)
			set_min1();	 
		}
	}
	lcd_cmd(0x01);
	hr=num[hr1];
	min=num[min1];
	set_rtc_time();
	lcd_cmd(0x80);
	lcd_string("TIME:");
	hr0=25;
	min0=60;
}

bcdconv(unsigned char mybyte)
{
	unsigned char x,y;
	x=	mybyte & 0x0F;
	x=x | 0x30;
	y= mybyte & 0xF0;
	y=y>>4;
	y=y | 0x30;
	lcd_data(y);
	lcd_data(x);
}

void read_rtc_display() 
{ 

	XBYTE[11]=0x02;
	hr=XBYTE[4];
	lcd_cmd(0x85);
	//if(hr!=hr0)
	{
		bcdconv(hr);
		lcd_data(':');
		hr0=hr;
	}
	
	min=XBYTE[2];

	//if(min!=min0)
	{
		bcdconv(min);
		lcd_data(':');
		//min0=min;
	}
		sec=XBYTE[0];
	
	//if(sec!=temp)
	{
		bcdconv(sec);
		//temp=sec;
	}
}

void main()
{
	reset=1;
	lcd();
	XBYTE[10]=0x20;
	XBYTE[1]=0xFF;
	XBYTE[3]=0xFF;
	XBYTE[5]=0xFF;
	XBYTE[11]=0x02;
	lcd_cmd(0x01);
	IE=0x84;
	lcd_cmd(0x80);
	lcd_string("TIME:");
	while(1)
	{
		read_rtc_display();
	}
}