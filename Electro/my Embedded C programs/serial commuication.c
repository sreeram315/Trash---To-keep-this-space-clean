#include <REGX51.H>                 

void cct_init(void);


void SerialInitialize(void);

void uart_msg(unsigned char *c);

void uart_tx(unsigned char);   

sbit led1 = P1^0;

sbit led2 = P1^1;

sbit led3 = P1^2;

sbit led4 = P1^3;




void main()

{

    cct_init();

    SerialInitialize();   

    EA = 1;

    ES = 1;

    uart_msg("Initializing Serial Communication");

                uart_tx(0x0d);

                uart_msg("1,2,3,4 key can on leds and a,b,c,d can off them respectively.");

                uart_tx(0x0d);                                                   //next line

                uart_msg("Press the key for particular LED");

                uart_tx(0x0d);

    while(1);

}




void cct_init(void)            //initialize cct

{

    P0 = 0x00;                                        //not used

    P1 = 0x00;                                        //output port used for leds

    P2 = 0x00;                                        //not used

    P3 = 0x03;                                        //used for serial communication

}




void SerialInitialize(void)       //Initialize Serial Port

{

    TMOD = 0x20;                   //Timer 1 In Mode 2 -Auto Reload to Generate Baud Rate

    SCON = 0x50;                    //Serial Mode 1, 8-Data Bit, REN Enabled

    TH1 = 0xFD;                       //Load Baud Rate 9600 To Timer Register

    TR1 = 1;                              //Start Timer

}




void uart_msg(unsigned char *c)

{

                while(*c != 0)

                {

                                uart_tx(*c++);

                }

}




void uart_tx(unsigned char serialdata)

{

    SBUF = serialdata;                        //Load Data to Serial Buffer Register

    while(TI == 0);                               //Wait Until Transmission To Complete

    TI = 0;                                                //Clear Transmission Interrupt Flag

}




void serial_ISR (void) interrupt 4

{

    char chr;                                           //receive character

    if(RI==1)

    {

        chr = SBUF;

        RI = 0;

    }




    P0 = ~P0;                                         //Show the data has been updated




    switch(chr)

    {

     case '1':  led1 = 1; uart_msg("1st on"); uart_tx(0x0d); break;

     case '2':  led2 = 1; uart_msg("2nd on"); uart_tx(0x0d); break;

     case '3':  led3 = 1; uart_msg("3rd on"); uart_tx(0x0d); break;

     case '4':  led4 = 1; uart_msg("4th on"); uart_tx(0x0d); break;




     case 'a':  led1 = 0; uart_msg("1st off"); uart_tx(0x0d);  break;

     case 'b':  led2 = 0; uart_msg("2nd off"); uart_tx(0x0d); break;

     case 'c':  led3 = 0; uart_msg("3rd off"); uart_tx(0x0d); break;

     case 'd':  led4 = 0; uart_msg("4th off"); uart_tx(0x0d); break;




     default: ;    break;                        //do nothing

    }




    RI = 0;

}