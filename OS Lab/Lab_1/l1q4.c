#include<stdio.h>
#include <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	char c;
	int in,out;
	char buffer[128];
	int nread;
	if(argc!=3){
		printf("\nInsufficient Arguments\n");
		exit(1);
	}
	in=open(argv[1],O_RDWR);
	out=open(argv[2],O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	if( in==-1 || out==-1){
		printf("File not found\n");
		exit(1);
	}
	while(read(in,&c,1) == 1){
		write(out,&c,1);
	}
	printf("Contents of file copied\n");
	exit(0);
}