#include<AT89X52.h>  // 256byte RAM ,8K flash

void delay_ms(unsigned int ms);  //delay function to generate delay of ms second
void main()
{
    
    while(1) //Infinity loop
    {
         unsigned char Binary;
        for(Binary = 0 ; Binary <=255 ; Binary++)
        {
            //P2 = Binary;                    //For Comman cathod
            P2 = ~Binary;                    //For Comman anode
            delay_ms(500);                 //delay of ~1 sec
        }
    }
}
void delay_ms(unsigned int ms)
{
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<127;j++);
    
}