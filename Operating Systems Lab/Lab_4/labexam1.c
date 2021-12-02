#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int n = atoi(argv[1]);
    int fd;
    char ch;
    int status,x,d;
    int res;
    pid = fork();
    switch(pid){
        case -1:
                printf("Error!");
                exit(-1);
        case 0:
                fd = open("hello.txt", O_WRONLY);
                if(fd == -1){
                    printf("File error!");
                    exit(-1);
                }
                ch = '5';
                d = 10;
                x = write(fd,&d,1);
                exit(1);
        default:
                wait(&status);
                fd = open("hello.txt", O_RDONLY);
                if(fd == -1){
                    printf("File error!");
                    exit(-1);
                }
                x = read(fd,&res,1);
                printf("The number is : %d", res);
                exit(0);
    }
    return 0;
}
