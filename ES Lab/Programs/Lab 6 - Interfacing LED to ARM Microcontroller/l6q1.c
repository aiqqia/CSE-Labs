#include<LPC17xx.h>

unsigned int i,j;

int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();

    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;//configuring as output pins
    //using same pins P0.4 to P0.111 as GPIO functions

    while(1){
        for(i=0;i<256;i++)
        {
            LPC_GPIO0->FIOPIN = i<<4;
            for(j=0;j<10;j++);
        }
    }
}
