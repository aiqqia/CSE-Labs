#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("Incorrect number of arguments, Expected 1, Got: %d", argc-1);
		return 0;
	}
	char *oldpath = argv[1];
	char *newpath = "newpath.txt";
	struct stat file_stat;
	printf("Before linking new link:\n");
	system("ls");
	int return_value = stat(oldpath, &file_stat);
	if(return_value != 0){
		perror("stat");
		return 1;
	}
	printf("Number of links before linking: %ld\n", file_stat.st_nlink);

	symlink(oldpath, newpath);

	printf("After linking new link:\n");
	system("ls");
	int return_value_2 = stat(newpath, &file_stat);
	if(return_value_2 != 0){
		perror("stat");
		return 1;
	}
	printf("Number of links after linking: %ld\nThe new path is: %s\n", file_stat.st_nlink, newpath);
	unlink(newpath);
	printf("After unlinking new soft link:\n");
	system("ls");
	int return_value_3 = stat(oldpath, &file_stat);
	if(return_value_3 != 0){
		perror("stat");
		return 1;
	}
	printf("Number of links after unlinking: %ld\n", file_stat.st_nlink);
	return 0;
}