#include<LPC17xx.h>

int main(void)
{
    unsigned int i,j,k;
    //i am configuring port0 pins p0.4-p0.11 as gpio function
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_PINCON->PINSEL4 &=0xFCFFFFFF;
    //2.12 gpio needs to be configured as input pin
    LPC_GPIO0->FIODIR |= 0x00000FF0;//configuring as output pins
    LPC_GPIO2->FIODIR &= 0xFFFFEFFF;//pin 12 is made to be 0 since i/p

    while(1){
        k = LPC_GPIO2->FIOPIN >> 12; //We read input from 2.12
        k &= 0x00000001;
        if(k == 1){
            
                LPC_GPIO0->FIOPIN = i << 4; //since p0.4
				i++;
                for (j = 0; j < 10000; j++);//random delay
				if(i==255) i=0;
        }
        else{
                LPC_GPIO0->FIOPIN = i << 4;
				i--;
                for(j = 0; j < 10000; j++);//random delay
				if(i==0){
					i=255;
				}
		}
	}
}

#include<LPC17xx.h>

int main(void)
{
    unsigned int i,j,k;
    //i am configuring port0 pins p0.4-p0.11 as gpio function
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_PINCON->PINSEL4 &=0xFCFFFFFF;
    //2.12 gpio needs to be configured as input pin
    LPC_GPIO0->FIODIR |= 0x00000FF0;//configuring as output pins
    LPC_GPIO2->FIODIR &= 0xFFFFEFFF;//pin 12 is made to be 0 since i/p

    while(1){
        k = LPC_GPIO2->FIOPIN >> 12; //We read input from 2.12
        k &= 0x00000001;
        if(k == 1){
            for (i = 0; i < 256; i++){
                LPC_GPIO0->FIOPIN = i << 4; //since p0.4
                for (j = 0; j < 10000; j++);//random delay
            }
        }
        else{
            for(i=255; i>0 ; i--){
                LPC_GPIO0->FIOPIN = i << 4;
                for(j = 0; j < 10000; j++);//random delay
								if(i==0){
									i=255;
									break;
								}
						}
				}
		}
}
