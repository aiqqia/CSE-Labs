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
int main()
{
	int sd,nd,n,len,reult,n1;
	struct sockaddr_in seraddress, cliaddr;
	char buf[256], buf1[256];
	sd=socket(AF_INET, SOCK_STREAM,0);
	seraddress.sin_family=AF_INET;
	seraddress.sin_addr.s_addr=INADDR_ANY;
	seraddress.sin_port=htons(10200);
	len=sizeof(seraddress);
	connect(sd,(struct sockaddr*)&seraddress,len);
	printf("Enter the message token : \n");
	gets(buf);
	n=write(sd,buf,strlen(buf));
        n1=read(sd,buf1,sizeof(buf1));
        buf1[n1]='\0';
	printf("Message from server : %s\n",buf1);
	getchar();
        close(sd);


}