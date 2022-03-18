#include<reg51.h>
sbit dgt1 = P1^0;  
sbit dgt2 = P1^1;
sbit start= P3^0;

unsigned int count=0;
unsigned char dgt_1;
unsigned char dgt_2;
unsigned char siven[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int h = 0;

volatile unsigned char digits[2];
void delay (unsigned char msdelay)
{
	int x,y;
	for(x=0;x<msdelay;x++)
	{
		for(y=0;y<127;y++)
		{
		}
	}
}
void main (void)
{

	TMOD=0X01;
	TH0=0XF0;
	TL0=0x00;
	TR0=1;
	EA=1;			 
	ET0=1;
  P2 = 0xff;
  P1 = 0xff;
	while(1)
	{
     if(start == 0) //if Switch at P3.0 is Pressed
     {
        delay(50); //for Switch debouncing 
        count++;
        while(start == 0); //wait here if still Switch Pressed
        
     }
  }
}

void timer0_isr () interrupt 1
{
    digits[0] = count/10;   // tenth 
    digits[1] = count%10;   // unit 
    dgt1=0;                 // tenth off
    dgt2=0;                 // unit off
    P1 =(((1<<h)));      // h=0 tenth on h=1 unit on 
    P2 = siven[digits[h]]; // h=0 display tenth h=1 display unit

    if(h==1)    //if last than come to first
    h=0;
    else
    h++;        //4.44ms int
    TF0=0;
	TH0=0XF0;   //Reload value for Next 4.44ms
	TL0=0xf0;
		
}
