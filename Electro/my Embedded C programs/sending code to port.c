#include<reg51.h>
void delay(unsigned time){
	unsigned char i,z;
	for(i=0;i<time;i++)
	for(z=0;z<1275;z++);}
void main(){
	A: P1=0x55;
	delay(500);
	P1=0xAA;
	delay(500);
	goto A;
}