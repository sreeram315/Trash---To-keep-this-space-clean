#include<reg51.h>
void delay(unsigned int time){
	unsigned char i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);}

void main(void){
	code unsigned char mynum[]="ABCDEF";
	unsigned char z;
	for(z=0;z<=6;z++){
		P1=mynum[z];}}