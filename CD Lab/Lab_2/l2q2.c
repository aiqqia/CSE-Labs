#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *finp = fopen("samplein.c","r");
	FILE *fout = fopen("sampleout.c","w+");
	char c = 0;
	char buffer[100];
	buffer[0] = '\0';
	int i = 0;
	char *includeStr = "include", *defineStr = "define", *mainStr = "main";
	int mainFlag = 0;
	while(c != EOF){
		c = fgetc(finp);
		if(c == '#' && mainFlag == 0){
			while(c != ' '){
				c = fgetc(finp);
				buffer[i++] = c;
			}
			buffer[i] = '\0';
			if(strstr(buffer, includeStr) != NULL || strstr(buffer, defineStr) != NULL){
				while(c != '\n'){
					c = fgetc(finp);
				}
			}
			else{
				fputc('#', fout);
				for(int j=0;j<i;j++){
					fputc(buffer[j], fout);
				}
				while(c != '\n'){
					c = fgetc(finp);
					fputc(c, fout);
				}
			}
			i = 0;
			buffer[0] = '\0';
		}
		else{
			if(mainFlag == 0){
				buffer[i++] = c;
				buffer[i] = '\0';
				if(strstr(buffer, mainStr) != NULL){
					mainFlag = 1;
				}
			}
			if(c == ' ' || c == '\n'){
				buffer[0] = '\0';
				i = 0;
			}
			fputc(c, fout);
		}
	}
	fclose(finp);
	fclose(fout);
	return 0;
}