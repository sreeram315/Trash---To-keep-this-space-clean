#include<reg51.h>
void delay(unsigned int time){
	unsigned char i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);}
void main(void){
	while(1){
	P0=0x55;
	delay(100);
	P0=0xAA;
	delay(100);}
}
	