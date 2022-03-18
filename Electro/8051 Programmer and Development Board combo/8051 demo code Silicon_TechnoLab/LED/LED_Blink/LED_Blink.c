#include<AT89X52.h>
void delay_ms(unsigned int ms); //delay function to generate delay of ms second
sbit LED = P1^0;
void main()
{
	P1=0xFF;
    while(1) //Infinity loop
    {
        P1=~P1; //Toggal the status of the P2.0
        delay_ms(1000);//delay for ~1 sec
    }
}
void delay_ms(unsigned int ms)
{
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<127;j++);
    
}