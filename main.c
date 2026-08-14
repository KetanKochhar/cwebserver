#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <string.h>
#include "req/req.h"

int main( int argc , char * argv[]){
	int port = atoi(argv[1]);
	int portno = portnumber(port);
 	struct sockaddr_in address = {
		AF_INET , portno , 0
	};
	int server = socket(AF_INET , SOCK_STREAM , 0);
	if (bind(server,(struct sockaddr *)&address , sizeof(address)) <0){
		printf("Error while link the port %d \n",port);
		return 1;

	}
	listen(server,1);
	printf("Listening the HTTP server on port %d\n",port);
	
	int client = accept(server,0,0);

	char buffer[256];
	int a = recv(client,buffer,sizeof(buffer)-1,0);
	printf("%d\n",a);
	printf("%s",buffer);

	const char *response = 
		"HTTP/1.1 200 OK \r\n"
		"Content-Type: text/plain\r\n"
		"Content-Length: 44\r\n"
		"\r\n"
		"Hello World of web server from c language \n";
	write(client,response,strlen(response));
	close(client);
	close(server);
	return 0;
}
