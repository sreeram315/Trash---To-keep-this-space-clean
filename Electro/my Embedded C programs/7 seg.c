#include<reg51.h>

void msdelay(unsigned int time) 										 // Function for creating delay in milliseconds.
{
    unsigned int i,j;
    for(i=0;i<time;i++)    
    for(j=0;j<1375;j++);
}

void main()
{
    unsigned char a[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}   ;
		unsigned char b[]={0x3F,0x06,0x5B}   ;							//Array for hex values (0-9) for common anode 7 segment
    int k,j;
    while(1)
    {
			P0=~0x4F;
			P1=~0x3F;
			msdelay(100);
			for(j=2;j>=0;j--)
			{
				P0=~b[j];
        for(k=9;k>=0;k--)
        {
         P1=~a[k]; 
         msdelay(100);
        }
			}
    }
}