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

int main(){
    int sd, len, n;
    struct sockaddr_in seraddress, cliaddr;
    int arr[20];
    int arr_size, pid;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    seraddress.sin_family = AF_INET;
    seraddress.sin_addr.s_addr = INADDR_ANY;
    seraddress.sin_port = htons(10200);

    len = sizeof(seraddress);
    connect(sd, (struct sockaddr *)&seraddress, len);

    printf("Enter number of elements: \n");
    scanf("%d", &arr_size);
    printf("Enter elements: \n");

    for (int i = 0; i < arr_size; i++){
        scanf("%d", &arr[i]);
    }

    n = write(sd, &arr_size, sizeof(int));
    n = write(sd, arr, arr_size * sizeof(int));
    n = read(sd, &pid, sizeof(int));
    n = read(sd, arr, arr_size * sizeof(int));

    printf("\nSorted array: ");
    for (int i = 0; i < arr_size; i++){
        printf("%d ", arr[i]);
    }

    printf("\nProcess ID: %d\n", pid);

    getchar();
}