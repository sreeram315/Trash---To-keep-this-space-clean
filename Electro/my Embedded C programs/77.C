#include<reg51.h>

void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}

void main()
{
    unsigned char no_code[]={0x3F}; //Array for hex values (0-9) for common anode 7 segment
    int k;
    while(1)
    {
        for(k=0;k<12;k++)
        {
         P1=no_code[0]; 
         msdelay(1000);
        }
    }
}