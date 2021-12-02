#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st{
	long int my_msg_type;
	int num;
};

int main(){
	int running = 1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_to_receive = 0;
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if(msgid == -1){
		perror("msgget failed");
		exit(EXIT_FAILURE);
	}
	while(running){
		printf("Enter a number : ");
		int n;
		scanf("%d", &n);        
		some_data.my_msg_type = 1;        
		some_data.num = n;        
		if(msgsnd(msgid, (void *)&some_data, sizeof(msgid), 0) == -1){
			perror("msgsnd failed");
			exit(EXIT_FAILURE);
		}
		if(n == -1){
			running = 0;
		}
	}
	exit(EXIT_SUCCESS);
}