#include<reg51.h>
void delay(unsigned int time){
	unsigned char i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);}
void main(void){
	P0= 0x35 & 0x0F;
	P1=0x04 | 0x68;
	delay(100);
}