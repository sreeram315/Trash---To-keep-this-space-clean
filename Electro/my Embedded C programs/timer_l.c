#include<reg51.h>

void delay(unsigned int time) 										 
{
    unsigned int i,j;
    for(i=0;i<time;i++)    
    for(j=0;j<1575;j++);
}

void main()
{
    unsigned char a[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}   ;		
		int k,j;
		P0=0x00;
    while(1)
    {
			P0=~0x4F;
			P2=~0x3F;
			delay(100);
			for(j=2;j>=0;j--)
			{
				P0=~a[j];
        for(k=9;k>=0;k--)
        {
         P2=~a[k]; 
         delay(100);
        }
			}
    }
}