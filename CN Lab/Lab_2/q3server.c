#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#define MAX 80
#define PORT 5000
#define SA struct sockaddr

void servfunc(int sockfd, struct sockaddr_in *cli){
    char buff[MAX];
    int n;
    for(;;){
        bzero(buff, sizeof(buff));
        n = recv(sockfd, buff, sizeof(buff), 0);
        buff[n] = '\0';
        if (strcmp(buff, "QUIT") == 0){
            printf("Server Exit...\n");
            break;
        } else if (strcmp(buff, "time") == 0){
            time_t rawtime;
            struct tm *info;
            time(&rawtime);
            info = localtime(&rawtime);
            char *str = asctime(info);
            ssize_t size_str = strlen(str);
            n = send(sockfd, str, size_str, 0);
            if (n == -1){
                printf("Error in sending message. Try Again!\n");
                continue;
            }
        } else{
            char str[] = "ERROR";
            if(send(sockfd, str, sizeof(str), 0) == -1){
                printf("Error in sending message. Try Again!\n");
                continue;
            }
        }
    }
}


int main(){
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0){
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd < 0)
    {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");
    servfunc(connfd, (struct sockaddr_in *)&cli);
    close(sockfd);
}