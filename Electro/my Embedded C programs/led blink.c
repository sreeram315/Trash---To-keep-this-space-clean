#include<reg51.h>
sbit a= P2^0;
void delay();
void main()
{
	P2=0xFF;
	while(1)
	{
		a=0;
		delay();
		a=1;
		delay();
	}
}

void delay()
{
	int i,j;
	for(i=0;i<10;i++)
	for(j=0;j<1275;j++);
}