#include<reg51.h>
void delay(unsigned int time){
	unsigned char i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);}
void main(void){
	
	P0=0x55;
	P1=0xAA;
		while(1){
			P0=~P0;
			P1=~P1;
			delay(100);
		}
}
	