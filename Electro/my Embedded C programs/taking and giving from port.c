#include<reg51.h>
void delay(unsigned int time){
	unsigned i,j;
	for(i=0;i<time;i++)
	for(j+0;j<1275;j++);
}
unsigned char mybyte;
void main(void){
	P1=0xFF;
	mybyte=P1;
	delay(40);
	P2=mybyte;
	delay(40);
}