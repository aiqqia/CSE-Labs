//Server program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 10200

struct sentbyclient
{
    char name[50];
    int registration;
};

struct sentbyserver
{
    char servername[50];
    int serverid;
    char clientname[50];
};

int main()
{
    int connection_socket, data_socket, len, n;
    struct sockaddr_in seraddress, cliaddr;
    int arr[20];
    int arr_size = 0;

    connection_socket = socket(AF_INET, SOCK_STREAM, 0);

    seraddress.sin_family = AF_INET;

    seraddress.sin_addr.s_addr = INADDR_ANY;             // loopbaack address 127.0.0.1
    seraddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // any address

    seraddress.sin_port = htons(PORT);

    printf("%d", getpid());

    bind(connection_socket, (struct sockaddr *)&seraddress, sizeof(seraddress));

    listen(connection_socket, 5);

    len = sizeof(cliaddr);

    while (1)
    {
        data_socket = accept(connection_socket, (struct sockaddr *)&cliaddr, &len);
        printf("Connected to client");
        int child = fork();
        if (child == 0)
        {
            close(connection_socket);
            int pid = getpid();
            struct sentbyclient recv;
            struct sentbyserver sent;
            strcpy(sent.servername, "vande matram");
            sent.serverid = getpid();
            n = read(data_socket, &recv, sizeof(recv));
            strcpy(sent.clientname, recv.name);

            //Sort

            n = write(data_socket, (void *)&sent, sizeof(sent));
            getchar();
        }
        close(data_socket);
    }
}