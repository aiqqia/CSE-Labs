#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char const *argv[]){
	if(argc < 2){
		printf("Incorrect number of arguments, Expected 1, Got: %d\n",argc-1);
		return 0;
	}
	struct stat file_stat;
	int return_value = stat(argv[1], &file_stat);
	if(return_value != 0){
		perror("stat");
		return 1;
	}
	printf("File: %s ---- Inode: %ld\n", argv[1], file_stat.st_ino);
	return 0;
}