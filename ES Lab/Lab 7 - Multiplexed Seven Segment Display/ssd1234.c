#include<LPC17xx.h>

unsigned seven_seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66};
unsigned int dig_value[4]={4,3,2,1};
unsigned int dig_select[]={0,1,2,3};
unsigned int i=0;

int main(){
	LPC_PINCON->PINSEL0 &= 0xFF0000FF; //0.4 to 0.11
	LPC_PINCON->PINSEL3 &= 0xFFC03FFF; //1.23 to 1.26
	
	LPC_GPIO0->FIODIR |= 0x00000FF0; //0.4 to 0.11 as output
	LPC_GPIO1->FIODIR |= 0x07800000; //1.23 to 1.26 as output
	
	while(1){
		LPC_GPIO1->FIOPIN = i<<23;
		LPC_GPIO0->FIOPIN = seven_seg[dig_value[i]] << 4;
		i=(i+1)%4;
	}
}
