#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	pid_t pid;
	int status;
	pid = fork();
	switch(pid){
		case -1: printf("Error occured!...\n");
				 exit(-1);
		case 0: printf("Executing child process of main program.\n");
				printf("______\n");
				execlp("./l3q1", "l3q1", NULL);
				exit(0);
		default: wait(&status);
				 printf("______\nExecuting parent process of main program.\nChild Status has returned: %d\nNow, Exiting parent process of main program...\n", status);		 

	}
}