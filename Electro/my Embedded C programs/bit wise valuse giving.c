#include<reg51.h>
sbit mybit=P1^1;
void delay(int time){
	unsigned char i,z;
	for(i=0;i<time;i++)
		for(z=0;z<1275;z++);
	
}
void main(){
	
//	unsigned char z;
	for(;;){
		mybit=0;
		delay(100);
		mybit=1;
		delay(100);
	}
}
