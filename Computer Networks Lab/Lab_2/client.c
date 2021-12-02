#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

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
    int socket_descriptor, len, n;
    struct sockaddr_in seraddress, cliaddr;
    int arr[20];
    int arr_size, pid;

    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    seraddress.sin_family = AF_INET;
    seraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    seraddress.sin_port = htons(10200);

    connect(socket_descriptor, (struct sockaddr *)&seraddress, sizeof(seraddress));

    struct sentbyclient sent;
    strcpy(sent.name, "ayush goyal");
    sent.registration = 190905522;
    struct sentbyserver recv;
    n = write(socket_descriptor, (void *)&sent, sizeof(sent));
    n = read(socket_descriptor, &recv, sizeof(recv));

    printf("\n received : \nserver name : %s \nnumber : %d\nclient name : %s", recv.servername, recv.serverid, recv.clientname);
    close(socket_descriptor);
}