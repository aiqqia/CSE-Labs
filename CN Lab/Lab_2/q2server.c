#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 5000


int calc(int a, int b, char operator)
{
    switch(operator)
    {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '/':
            return a / b;
            break;
        case '*':
            return a * b;
            break;
        default:
            return 0;
            break;
    }
}


void servfunc(int sockfd, struct sockaddr_in server_address)
{
    struct sockaddr_in client_address;
    int clientfd, a, b, res, size = sizeof(client_address);
    char op;
    while (1)
    {
        clientfd = accept(sockfd, (struct sockaddr *)&client_address, &size);
        if (fork() == 0)
        {
            //in child process
            printf("Child process created with clientfd %d\n", clientfd);
            close(sockfd);
            read(clientfd, (int *)&a, sizeof(int));
            read(clientfd, (int *)&b, sizeof(int));
            read(clientfd, (char *)&op, sizeof(char));
            res = calc(a, b, op);
            write(clientfd, (int *)&res, sizeof(int));
            close(clientfd);
            printf("Child process terminated with clientfd %d\n", clientfd);
            exit(0);
        }
        else
            close(clientfd); // parent process
    }
    printf("Server Closing!\n");
}


int main()
{
    int sockfd;
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int res = bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
    if(res < 0)
    {
        printf("Server unable to bind\n");
        exit(0);
    }
    else
        printf("Server bound successfully\n");
    res = listen(sockfd, 2);
    if(res < 0)
    {
        printf("Server unable to listne\n");
        exit(0);
    }
    else
        printf("Server listening successfully\n");
    servfunc(sockfd, server_address);
    close(sockfd);
}