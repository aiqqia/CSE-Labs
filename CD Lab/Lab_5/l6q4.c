#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr = 0;
char str[100];
void S();
void L();
void lPrime();

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
		return;
	}
	else if(str[curr] == '('){
		curr++;
		L();
		if(str[curr] == ')'){
			curr++;
			return;
		}
		else
			printInvalid();
	}
	else
		printInvalid();
}

void L(){
	S();
	lPrime();
}

void lPrime(){
	if(str[curr] == ','){
		curr++;
		S();
		lPrime();
	}
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