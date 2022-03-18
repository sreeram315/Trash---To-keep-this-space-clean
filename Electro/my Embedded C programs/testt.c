#include<reg51.h>
void delay ( unsigned int t){
	unsigned int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<1275;j++);}}
void main(void){
	while(1){
	P11=0xFF;
	delay(100);
	P1=0x55;}
}
	