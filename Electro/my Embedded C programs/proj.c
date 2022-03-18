#include<reg51.h>
#include<stdio.h>
#include<string.h>
	unsigned char ar=0;
	 unsigned char snames[][20]={"BEERA JI","DESAI ","BEERA BHAI"};
	 unsigned int srolls[]={43,44,47,43,44,45,46,47,48,49,50,51,52};
	 unsigned int spins[]={2770,5894,5748,5135};
	unsigned char ch,k=0,r=0,y=0,ox=0;
	int a,b;
	unsigned int epin=0;
	unsigned int pres[];
//sbit w  = P3^5; sbit d  = P3^4;
	sbit buzz = P3^4;
sbit rs = P3^7; sbit rw = P3^6;  sbit en = P3^5;
sbit R1 = P1^0; sbit R2= P1^1;  sbit R3 = P1^2; sbit R4 = P1^3;
sbit C1 = P1^4;  sbit C2 = P1^5;  sbit C3 = P1^6;
void show_pres();
void lcd_array(unsigned char);
void show_abs();
void lcd_data(unsigned char a);
void lcd_cmd(unsigned char a);
void get_roll();
void main();
//void lcd_line(unsigned char);
void lcd_ini();
void row_find1();
void delay(unsigned int z);
void row_find2();
void row_find3();

void buzzer (void) interrupt 0
{
	unsigned char y=5;
	if(ar==1)
		return;
	P0=99;
	while(y>1){
		buzz =0;
		delay(40);
		buzz=1;
		delay(40);
		y--;
	}		
}

void lcd_line(unsigned char *str)
{
	unsigned char i;
	i=0;
	while(str[i] != '\0')
	{
		lcd_data(str[i]);
		i++;
	}
}

/*void lcd_array(unsigned int *a)
{
	unsigned char i=0;
	while(a[i]!='\0'){
		lcd_data(a[i]);
		i++;
	}
}*/


/*struct student{
	 char name[25];
	 unsigned char rn;
	 int pin;
};*/

void show_abs(){
	lcd_ini();
	lcd_line("ABSENTEES ARE");
	delay(200);
/*	for(a=0;snames[a]!='\0';a++){
		for(b=0;pres[b]!='\0';b++){
			if(srolls[a]==pres[b])
			{
				lcd_ini();
				lcd_line(snames[a]);
				delay(200);
				break;
			}
		}
	}*/
}
			

void show_pres(){
	lcd_ini();
	lcd_line("PRESENTEES ARE");
	delay(200);
/*	for(a=0;pres[a]!='\0';a++){
		for(b=0;srolls[b]!='\0';b++){
			if(pres[a]==srolls[b]){
				lcd_ini();
				lcd_line(snames[a]);
				break;
			}
		}
	}*/
}

void get_snum(){
	while(epin<=0){
	C1=C2=C3=1;
	R1=R2=R3=R4=0;
	if(C1==0){
		row_find1();
	delay(50);}
	else if(C2==0){
		row_find2();
	delay(50);}
	else if(C3==0){
	row_find3();
	delay(50);}
}
}



void delay(unsigned int z)
{
  unsigned int p,q;
  for(p=0;p<z;p++)    
  for(q=0;q<1375;q++);   
}

void lcd_cmd(unsigned char a){
	P2 = a;
	rs = 0;
	rw = 0;
	en = 1;
	delay(1);
	en=0;
}

void lcd_data(unsigned char a){
	
	P2=a;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
	
}



void show_att(){
	lcd_ini();
	lcd_line("  C H O O S E");
	delay(100);
	X:
	lcd_ini();
	lcd_line("1) VIEW PRESENTEES");
	lcd_cmd(0xC0);
	lcd_line("2) VIEW ABSENTEES");
	epin=0;
	get_snum();
	switch(epin){
		case 9:
			main();
		case 1: 
			lcd_ini();
			show_pres();
			break;
		case 2:
			lcd_ini();
			show_abs();
			break;
		default:
			lcd_ini();
			lcd_line("Wrong choice");
			lcd_cmd(0xC0);
			lcd_line("Try again");
			delay(150);
			lcd_ini();
			lcd_line("PRESS \"0\" FOR");
			lcd_cmd(0xC0);
			lcd_line("MARKING ATENDENS");
			delay(200);
			goto X;
	}
}

void get_roll(){
	while(epin<999){
	C1=C2=C3=1;
	R1=R2=R3=R4=0;
	if(C1==0){
		row_find1();
	delay(50);}
	else if(C2==0){
		row_find2();
	delay(50);}
	else if(C3==0){
	row_find3();
	delay(50);}
}
}

void row_find1()
{
	R1=R2=R3=R4=1;
	C1=C2=C3=0;
	if(R1==0){
		lcd_data('1');
		epin=epin*10 + 1;}
	else if(R2==0){
		lcd_data('4');
		epin=epin*10 + 4;}
	else if(R3==0){
		lcd_data('7');
		epin=epin*10 + 7;}
	else if(R4==0){
		lcd_data('*');
		show_att();
		
	}
	
}

void row_find2()
{
	R1=R2=R3=R4=1;
	C1=C2=C3=0;
	if(R1==0){
		lcd_data('2');
		epin=epin*10 + 2;}
	else if(R2==0){
		lcd_data('5');
		epin=epin*10 + 5;}
	else if(R3==0){
		lcd_data('8');
		epin=epin*10 + 8;}
	else if(R4==0){
		lcd_data('0');
		epin=epin*10 + 0;}
	
}





void row_find3(){
	R1=R2=R3=R4=1;
	C1=C2=C3=0;
	if(R1==0){
		lcd_data('3');
		epin=epin*10 + 3;}
	else if(R2==0){
		lcd_data('6');
		epin=epin*10 + 6;}
	else if(R3==0){
		lcd_data('9');
		epin=epin*10 + 9;}
	else if(R4==0)
		return;
		
}

void forgot_pass(){
	lcd_ini();
	lcd_line("FORGOT PASSWORD ?");
	lcd_cmd(0xC0);
	delay(40);
	lcd_line("Do not worry");
	lcd_ini();
	delay(200);
	lcd_line("BEERA is with");
	lcd_cmd(0xC0);
	lcd_line("you");
	delay(200);
	lcd_ini();
	lcd_line("Boys, call Now");
	delay(200);
	lcd_ini();
	lcd_line("BEERA:8919937557");
	lcd_cmd(0xC0);
	lcd_line("*GIRLS DONT CALL");
	delay(500);
	ox=1;
	main();
}
	

void lcd_ini(){
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
	lcd_cmd(0x80);
} 

void main(void){
	
	unsigned char o;
	IT0 = 1;   // Configure interrupt 0 for falling edge on /INT0 (P3.2)
  EX0 = 1;   // Enable EX0 Interrupt
  EA = 1;    // Enable Global Interrupt Flag
	P0=0x00;
	P2=0x00;
	P1=0xFF;
	if(ox==1)
	{goto A;}
	buzz=1;
	lcd_ini();
//	w=d=0;
	lcd_ini();
	lcd_line("    NAMASTHE   ");
	delay(400);
	lcd_ini();
	lcd_line("PLEASE WAIT");
	delay(300);
	lcd_ini();
	lcd_line("POWERING UP");
	lcd_cmd(0xC0);
	lcd_line("ATTENDENS SYSTEM");
	delay(300);
	lcd_ini();
	lcd_line("WELCOME");
	delay(200);
	lcd_ini();
	lcd_line("SECTION: E1602");
	lcd_cmd(0xC0);
	lcd_line("GROUP: 2");
	delay(300);
	lcd_ini();
	lcd_line("ENTER YOUR");
	lcd_cmd(0xC0);
	lcd_line("PIN NUMBER");
	delay(200);
	lcd_ini();
	lcd_line("PRESS \"#\" when");
	lcd_cmd(0xC0);
	lcd_line("DONE");
	delay(300);
	lcd_ini();
	lcd_line("PRESS \"*\" to");
	lcd_cmd(0xC0);
	lcd_line("VIEW RECORDS");
	delay(200);
	A:
	ar=0;
	k=0;
	epin=0;
	lcd_ini();
	lcd_line("PIN NUMBER:");
	lcd_cmd(0xC0);
	get_roll();
	lcd_ini();
	if(epin==1111){
		forgot_pass();
		goto A;
	}
	for(o=0;o<3;o++){
		if(epin==spins[o])
		{
			ar=1;
			P0=srolls[o];
			lcd_ini();
			lcd_line("WELCOME");
			lcd_cmd(0xC0);
			lcd_line(snames[o]);
			buzz=0;
			
			
			delay(200);
			delay(3);
//			w=1;
			
//			w=0;
			lcd_ini();
			lcd_line("Pleaz wait until");
			lcd_cmd(0xC0);
			lcd_line("atendens uploads");
			buzz=1;
//			pres[r++]=srolls[o];
			delay(400);
//			goto A;
//			while(d==0);
			k=60;
			lcd_ini();
			lcd_line("DONE");
			lcd_cmd(0xC0);
			lcd_line("NEXT PLEASE");
			delay(100);
			goto A;
			}}
		if(k!=60){
			lcd_ini();
			lcd_line("NUMEBR NOT FOUND");
			lcd_cmd(0xC0);
			lcd_line("TRY AGAIN");
			delay(200);
			goto A;}
}	
