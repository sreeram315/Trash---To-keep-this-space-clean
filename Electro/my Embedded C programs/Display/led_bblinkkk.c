#include<reg51.h>


void delay(unsigned int t){
	unsigned int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1575;j++);
}

void main(){
	P2=0x00;
	while(1){
		P2=0x00;
		delay(100);
		P2=0xFF;
		delay(100);
	}
}