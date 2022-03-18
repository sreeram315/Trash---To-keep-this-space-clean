#include<reg51.h>
sbit rs = P1^2; sbit rw = P1^1;  sbit en = P1^0;
sbit R1 = P0^0; sbit R2= P0^1;  sbit R3 = P0^2; sbit R4 = P0^3;
sbit C1 = P0^4;  sbit C2 = P0^5;  sbit C3 = P0^6;
	xdata char stu_names[][20]={"BEERA","Devesan ji","Sunny Gupta","Someone 1","Someone 2"};
	xdata int stu_rolls[]={47,43,33,2,45,33};
	xdata int stu_pins[]={2770,9398,1234,4758,5216,5486};
	xdata struct student s[5];
	for(i=0;i<3;i++)
	{
		strcpy(s[i].name,stu_names[i]);
		s[i].rn=stu_rolls[i];
		s[i].pin=stu_pins[i];
	}
	P2=0x00;
	P3=0x01;
void lcd_data();
void acc();
		
unsigned char count=0;
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

void lcd_ini()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    delay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    delay(10);
    lcd_cmd(0x01);  //clear screen
    delay(10);
    lcd_cmd(0x80);  // bring cursor to position 1 of line 1
    delay(10);
}


void row_find1()
{
	R1=R2=R3=R4=1;
	C1=C2=C3=0;
	if(R1==0)
		lcd_data('1');
	else if(R2==0)
		lcd_data('4');
	else if(R3==0)
		lcd_data('7');
	else if(R4==0)
		lcd_data('*');
	count += 1;
	
}

void row_find2()
{
	R1=R2=R3=R4=1;
	C1=C2=C3=0;
	if(R1==0)
		lcd_data('2');
	else if(R2==0)
		lcd_data('5');
	else if(R3==0)
		lcd_data('8');
	else if(R4==0)
		lcd_data('0');
	count +=1;
	
}

void row_find3()
{
	R1=R2=R3=R4=1;
	C1=C2=C3=0;
		if(R1==0)
		lcd_data('3');
	else if(R2==0)
		lcd_data('6');
	else if(R3==0)
		lcd_data('9');
	else if(R4==0)
		acc();
	count +=1;
	
}

void acc()
{
	
	unsigned char i=0;
	unsigned char b[]="Access Granted";
	lcd_ini();
	while(b[i] != '\0')
	{
		lcd_data(b[i]);
		delay(1);
		i++;
	}
	while(1);
}

void main()
{
	unsigned char i=0;
	unsigned char a[]="Enter password:";
	P0=0xFF;
	P2=0x00;
	P1=0x00;
	lcd_ini();
	delay(30);
	i=0;
	while(a[i] != '\0')
	{
		lcd_data(a[i]);
		delay(10);
		i+=1;
	}
	lcd_cmd(0xC0);
	delay(200);
	while(1)
	{
	
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
	if(count==16){
		lcd_cmd(0xC0);		
	}
	if(count==32){
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	count=0;}
}}	