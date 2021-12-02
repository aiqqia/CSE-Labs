
// server program for udp connection 

#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#define PORT 5004 
#define MAXLINE 1000 

// Driver code 
int main() 
{ 
	char buffer[100]; 
	char *message = "Hello Client"; 
	int listenfd, len,n; 
	struct sockaddr_in servaddr, cliaddr; 
	bzero(&servaddr, sizeof(servaddr)); 

	// Create a UDP Socket 
	listenfd = socket(AF_INET, SOCK_DGRAM, 0);		 
	//servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_family = AF_INET; 

	// bind server address to socket descriptor 
	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
	
	//receive the datagram 
	len = sizeof(cliaddr);  
    
	n = recvfrom(listenfd, buffer, sizeof(buffer),0, (struct sockaddr*)&cliaddr,&len); 
	buffer[n] = '\0'; 
	puts(buffer); 
    //getchar();
      
		
	// send the response 
    //getchar();
	sendto(listenfd, buffer, n, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
	getchar();
	close(listenfd);
} 