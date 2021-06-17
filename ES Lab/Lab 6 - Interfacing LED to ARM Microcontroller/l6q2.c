#include <LPC17xx.h>

unsigned int i,j,k;
int c=0;

int main(void)
{
//i am configuring port0 pins p0.4-p0.11 as gpio function
  LPC_PINCON->PINSEL0 &= 0xFF0000FF;
  LPC_PINCON->PINSEL4 &=0xFCFFFFFF;
  //2.12 gpio needs to be configured as input pin
  LPC_GPIO0->FIODIR |= 0x00000FF0;//configuring as output pins
  LPC_GPIO2->FIODIR &= 0xFFFFEFFF;//pin 12 is made to be 0 since i/p

    while(1){
        k = LPC_GPIO2->FIOPIN >> 12; //We read input from 2.12
        k &= 0x00000001;
        if(k==1) 
  	c++;
        else 
  	c--;
        if(c==-1)
  	c=255;
        if(c==256)
  	c=0;
  //left shifting by four because fourth bit is the starting bit
        LPC_GPIO0->FIOPIN=c<<4;
	  //Putting a random delay here
        for(j=0;j<5000;j++);
    }
}
