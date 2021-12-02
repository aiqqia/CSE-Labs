#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(){
	int countline=0,countc=0;
	char c;FILE *fptr;
	fptr= fopen("input.txt","r");
	if(!fptr){
		printf("Cannot open file\n");
		exit(0);
	}
	c=getc(fptr);
	while(c!=EOF){
		if(c=='\n') countline++;
		/*Assuming that whitespace and new line are not considered as characters*/
		else countc++;

		c=getc(fptr);
	}
	if(countc >0) countline++;
	printf("Total number of lines and characters is %d and %d respectively\n",countline,countc);
	return 0;
}