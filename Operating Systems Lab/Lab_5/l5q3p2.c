#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<limits.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<string.h>

#define FIFO_NAME "my_queue"
#define BUFFER_SIZE 10000

int main(int argc, char const *argv[]){
	int pipe_fd, res, open_mode1 = O_WRONLY, open_mode2 = O_RDONLY, n = 0;
	char buffer[BUFFER_SIZE+1];
	if(access(FIFO_NAME, F_OK) == -1){
		res = mkfifo(FIFO_NAME, 0777);
		if(res != 0){
			fprintf(stderr, "Could not create files%s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}

	printf("Currently in Program 2 and starting communication with Program 1...\n");
	while(1){
		pipe_fd = open(FIFO_NAME, open_mode1);

		printf("\nEnter the text to send to Program 1: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		res = write(pipe_fd, buffer, BUFFER_SIZE);

		close(pipe_fd);

		pipe_fd = open(FIFO_NAME, open_mode2);

		printf("\nText from the Program 1: ");
		res = read(pipe_fd, buffer, BUFFER_SIZE);
		if(strstr(buffer, "exit") != NULL)
			break;
		printf("%s\n", buffer);

		close(pipe_fd);
	}
	close(pipe_fd);
	printf("Process %d finished.\n", getpid());
	exit(EXIT_SUCCESS);
}