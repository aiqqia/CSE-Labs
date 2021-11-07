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
#define BUFFER_SIZE 1000

int main(int argc, char *argv[]){
	int pipe_fd, res, open_mode = O_RDONLY, n = 0;
	char buffer[BUFFER_SIZE+1];
	memset(buffer, '\0', sizeof(buffer));
	printf("Process %d opening FIFO O_RDONLY\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);
	int bytes_read = 0;
	if(pipe_fd != -1){
		do{
			printf("%d : ", n+1);
			res = read(pipe_fd, buffer, BUFFER_SIZE);
			printf("%s\n", buffer);
			bytes_read += BUFFER_SIZE;
			n++;
		}while(n<4);
		close(pipe_fd);
	}
	else{
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished, %d bytes read.\n", getpid(), bytes_read);
	exit(EXIT_SUCCESS);
	return 0;
}