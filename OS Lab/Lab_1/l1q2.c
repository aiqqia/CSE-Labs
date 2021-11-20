#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	int sfd, sfd2, i=0, k=0, p=0;
	char ch[100], ch2[100], chr;

	if(argc != 3){
		printf("\nInsufficient Arguments\n");
		exit(1);
	}
	if((sfd = open(argv[1],O_RDONLY)) == -1){
		printf("File not found!\n");
		exit(2);
	}
	while((read(sfd, &chr, 1)) > 0){
		if(chr != '\n'){
			ch[i++] = chr;
		} else{
			k++;
			p++;
			ch[i] = '\0';
			i=0;
			printf("Line : %d\t %s\n",p,ch);
			if(k == 20){
				fgetc(stdin);
				k=0;
			}
		}
	}
	close(sfd);

	if((sfd2 = open(argv[2],O_RDONLY)) == -1){
		printf("File not found!\n");
		exit(2);
	}
	p=0;
	while((read(sfd2, &chr, 1)) > 0){
		if(chr != '\n'){
			ch2[i++] = chr;
		} else{
			k++;
			p++;
			ch[i] = '\0';
			i=0;
			printf("Line : %d\t %s\n",p,ch2);
			if(k == 20){
				fgetc(stdin);
				k=0;
			}
		}
	}
	exit(0);
}