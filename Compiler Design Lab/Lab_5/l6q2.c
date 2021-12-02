#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr = 0;
char str[100];
void S();
void U();
void V();
void W();

void printValid(){
	printf("\n *** Sucessful! ***\n");
	exit(0);
}

void printInvalid(){
	printf("\n *** Unsucessful! ***\n");
	exit(0);
}

void S(){
	U();
	V();
	W();
}

void U(){
	if(str[curr] == '('){
		curr++;
		S();
		if(str[curr] == ')'){
			curr++;
			return;
		}
		else
			printInvalid();
	}
	else if(str[curr] == 'a'){
		curr++;
		S();
		if(str[curr] == 'b'){
			curr++;
			return;
		}
		else
			printInvalid();
	}
	else if(str[curr] == 'd'){
		curr++;
		return;
	}
	else
		printInvalid();
}

void V(){
	if(str[curr] == 'a'){
		curr++;
		V();
	}
}

void W(){
	if(str[curr] == 'c'){
		curr++;
		W();
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