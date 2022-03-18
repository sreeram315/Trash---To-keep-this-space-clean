#include<reg51.h>
void delay(unsigned int time){
	unsigned i,j;
	for(i=0;i<time;i++)
	for(j+0;j<1275;j++);
}
unsigned char mybyte;
void main(void){
	P2=0xFF;
	delay(100);
	P1=0x55;
	mybyte=P1;
	delay(100);
	P2=mybyte;
	delay(1000);
}