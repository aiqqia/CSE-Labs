#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 80
#define PORT 5000
#define SA struct sockaddr

void clifunc(int sockfd, struct sockaddr_in *cli)
{
    char buff[MAX];
    int n;
    char *client_ip = inet_ntoa(cli->sin_addr);
    int client_port = (int)ntohs(cli->sin_port);
    for (;;)
    {
        printf("I am a client. My name is Ayush Goyal.\n");
        bzero(buff, sizeof(buff));
        printf("Enter the String : ");
        n = 0;
        scanf("%[^\n]%*c", buff);
        if (send(sockfd, buff, sizeof(buff), 0) == -1)
        {
            printf("Error in sending message. Try Again!\n");
            continue;
        }
        if (strcmp(buff, "QUIT") == 0)
        {
            printf("Server Closed, client exiting!\n");
            break;
        }
        bzero(buff, sizeof(buff));
        n = recv(sockfd, buff, sizeof(buff), 0);
        buff[n] = '\0';
        if (strcmp(buff, "ERROR") == 0)
        {
            printf("Wrong time command. Enter time\n");
            continue;
        }
        else
            printf("Recieved time from Server IP:%s and Port:%d is %s\n", client_ip, client_port, buff);
    }
}


int main(){
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if(connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0){
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");
    clifunc(sockfd, &servaddr);
    close(sockfd);
}