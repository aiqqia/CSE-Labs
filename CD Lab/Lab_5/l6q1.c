#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr = 0;
char str[100];
void S();
void T();
void tPrime();

void printValid(){
	printf("\n *** Sucessful! ***\n");
	exit(0);
}

void printInvalid(){
	printf("\n *** Unsucessful! ***\n");
	exit(0);
}

void S(){
	if(str[curr] == 'a' || str[curr] == '>'){
		curr++;
		return;
	}
	else if(str[curr] == '('){
		curr++;
		T();
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

void T(){
	S();
	tPrime();
}

void tPrime(){
	if(str[curr] == ','){
		curr++;
		S();
		tPrime();
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