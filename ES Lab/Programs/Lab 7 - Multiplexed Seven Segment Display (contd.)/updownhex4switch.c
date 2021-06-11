#include<LPC17xx.h>
#include<stdio.h>

unsigned int seg_select[4] = {0<<23, 1<<23, 2<<23, 3<<23};
int dig1=0x00, dig2=0x00, dig3=0x00, dig4=0x00;
unsigned int seg_count=0x00, temp1=0x00;
unsigned char arr_dec[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned long int i=0;
unsigned int k;
void delay(void);
void display(void);

int main(void){
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;//output
	LPC_PINCON->PINSEL3 &= 0xFFC03FFF;//bit
	LPC_PINCON->PINSEL4 &=0xFCFFFFFF;//switch
	
	LPC_GPIO0->FIODIR |= 0x00000FF0;//output
	LPC_GPIO1->FIODIR |= 0x07800000;//bit
	LPC_GPIO2->FIODIR &= 0xFFFFEFFF;//switch
	
	while(1){
		k = LPC_GPIO2->FIOPIN >> 12; //We read input from 2.12
		k &= 0x00000001;
		delay();
		display();
		seg_count +=1;
		if(seg_count == 0x04){
			seg_count = 0x00;
			
			if(k==1){
				dig1+=1;
				if(dig1 == 0x10){
					dig1=0;
					dig2+=1;
					if(dig2 == 0x10){
						dig2=0;
						dig3+=1;
						if(dig3 == 0x10){
							dig3=0;
							dig4+=1;
							if(dig4 == 0x10){
								dig4=0;
							}//eod4
						}//eod3
					}//eod2
				}//eod1
			}
			else{
				dig1-=1;
				if(dig1 < 0){
					dig1=0x0F;
					dig2-=1;
					if(dig2 < 0){
						dig2=0x0F;
						dig3-=1;
						if(dig3 < 0){
							dig3=0x0F;
							dig4-=1;
							if(dig4 < 0){
								dig4=0x0F;
							}//eod4
						}//eod3
					}//eod2
				}//eod1
			}//eoelse
			
		}//eosegcount
	}//eowhile
}//eomain

void display(void){
	LPC_GPIO1->FIOPIN = seg_select[seg_count];
	if(seg_count == 0x00){//for segment U9
		temp1=dig1;
	}
	else if(seg_count == 0x01){//for segment U10
		temp1=dig2;
	}
	else if(seg_count == 0x02){//for segment U11
		temp1=dig3;
	}
	else if(seg_count == 0x03){//for segment U11
		temp1=dig4;
	}
	
	LPC_GPIO0->FIOPIN = arr_dec[temp1]<<4;//Taking Data Lines for 7-Seg
	for(i=0;i<100000;i++);
}

void delay(void){
	unsigned int i;
	for(i=0;i<10000;i++);
}
