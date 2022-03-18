#include<reg51.h>
#include<stdio.h>
sbit chip_select= P0^0;
sbit rd_adc = P0^1;
sbit wr_adc = P0^2;
sbit intr_adc = P0^3;

void delay(unsigned char time)
{
	int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}

void main()
{
	intr_adc =1;
	rd_adc = 1;
	wr_adc = 1;
	while(1)
	{
		wr_adc = 0;
		delay(1);
		wr_adc = 1;
		while(intr_adc==1);
		rd_adc = 0;
		delay(1000);
		rd_adc = 1;
		intr_adc=1;
	}
}
