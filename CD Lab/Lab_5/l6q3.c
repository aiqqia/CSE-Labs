#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr = 0;
char str[100];
void S();
void A();
void B();
void aPrime();

void printValid(){
	printf("\n *** Sucessful! ***\n");
	exit(0);
}

void printInvalid(){
	printf("\n *** Unsucessful! ***\n");
	exit(0);
}

void S(){
	if(str[curr] == 'a'){
		curr++;
		A();
		if(str[curr] == 'c'){
			curr++;
			B();
			if(str[curr] == 'e'){
				curr++;
				return;
			}
			else
				printInvalid();
		}
		else
			printInvalid();
	}
	else
		printInvalid();
}

void A(){
	if(str[curr] == 'b'){
		curr++;
		aPrime();
	}
	else
		printInvalid();
}

void aPrime(){
	if(str[curr] == 'b'){
		curr++;
		aPrime();
	}
}

void B(){
	if(str[curr] == 'd'){
		curr++;
		return;
	}
	else
		printInvalid();
}

void main(){
	printf("Enter the String: \n");
	scanf("%s",str);
	S();
	if(str[curr] == '$')
		printValid();
	else
		printInvalid();
}