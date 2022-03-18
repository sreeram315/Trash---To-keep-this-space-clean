#include<AT89X51.h>
sbit dgt1 = P1^0;  
sbit dgt2 = P1^1;
sbit inc = P3^0;
sbit dec = P3^1;
sbit Reset = P3^2;

const unsigned char siven[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
volatile unsigned int h = 0,J=0;

unsigned char digits[4];
void delay (unsigned int msdelay)
{
	unsigned int x,y;
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
    
//     for(J=0;J<9999;)
//     {
//         J++;
//         delay(2);
//     }
        if(inc == 0)
        {
            delay(150);
            J++;
        }
        if(dec == 0 && J>0)
        { 
            delay(150);
            J--;
           // if(J<=0)
            //J = 1;
        }
				if(Reset == 0)
					J = 0;
    }
}

void timer0_isr () interrupt 1
{
    digits[0] = (char)(J/1000);   // tenth 
    digits[1] = (char)((J%1000)/100);   // unit
    digits[2] = (char)(((J%1000)%100)/10);    
    digits[3] = (char)(((J%1000)%100)%10);  
    dgt1=0;                 // tenth off
	dgt2=0;                 // unit off
    P1 =(((1<<h)));      // h=0 tenth on h=1 unit on 
    P2 = siven[digits[h]]; // h=0 display tenth h=1 display unit

    if(h==3)    //if last than come to first
    h=0;
    else
    h++;        //4.44ms int
    
     
    
    TF0=0;
	TH0=0XF0;
	TL0=0x00;		
}
