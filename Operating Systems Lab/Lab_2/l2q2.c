#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

void executeFunc(char* dir, int depth){
	struct dirent *myfile;
	struct stat mystat;
	DIR *mydir = opendir(dir);
	chdir(dir);
	while((myfile = readdir(mydir)) != NULL){
		bzero(&mystat, sizeof(mystat));
		stat(myfile->d_name, &mystat);
		for(int i=0;i<depth;i++)
			printf(" ");
		printf("%s", myfile->d_name);
		if(S_ISDIR(mystat.st_mode))
			printf("/");
		printf("\n");
		if(S_ISDIR(mystat.st_mode) && strcmp(myfile->d_name, ".") != 0 && strcmp(myfile->d_name, "..") != 0){
			executeFunc(myfile->d_name, depth+1);
		}
	}
	chdir("..");
	closedir(mydir);
}

int main(){
	executeFunc(".", 0);
	return 0;
}