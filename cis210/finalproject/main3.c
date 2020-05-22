#include <stdio.h>
#include <sense/sense.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#define BUFFER 4096

int stop=0;

void inthand(int signum) {
    stop = 1;
}

void error(char* msg) {
	perror(msg);
	exit(0);
}

int CreateServer(int port) {
	int sockfd,newsockfd,clilen;
	struct sockaddr_in serv_addr,cli_addr;

	// Creating a socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd < 0) {
		error("ERROR opening socket");
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);

	// Binding the created socket to the server
	if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		error("ERROR on binding");
	}

	listen(sockfd, 5);
	clilen = sizeof(cli_addr);

	// Allows the socket to listen to the client
	newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
	if (newsockfd < 0) {
		error("ERROR connecting socket to client");
	}

	return newsockfd;
}

int RecvServer(int sock) {
	// Receives a GET request from the client
	int n;
	char buffer[4096];

	bzero(buffer,4096);
	n = recv(sock, buffer, 4095, MSG_DONTWAIT);

	return n;
}

int SendServer(int sock, char* buffer) {
	// The server displays HTML that is represntative
	// of the GET request from the client
	int n;

	n = send(sock, buffer, strlen(buffer), 0);

	return n;
}

int main(int argc, char*argv[]) {
	int sockfd, portno,n;
        struct sockaddr_in serv_addr;
        struct hostent*server;
        char buffer[BUFFER];

	while (!stop){
		int res = recv(sockfd, buffer, BUFFER-1, MSG_DONTWAIT);
		if (res>0){
			int newsockfd,n,portno;
			pi_i2c_t* device=geti2cDevice();
			float temp,humidity;
			char sendTemp[2096];
			char buff[4096];
	
			portno = atoi(argv[1]);

			// Create a server with the given port number
			newsockfd = CreateServer(portno);

			// Server receiving a GET request from the client
			n = RecvServer(newsockfd);
			if (n < 0) {
				printf("Couldn't receive message");
			}

			if (device) {
				configureHumiditySensor(device);
				temp = getTemp(device);
				humidity = getHumidity(device);
			}


			bzero(buff,4096);

			// Concatenating the html to the buffer that will be sent to the client
			gcvt(temp,6,sendTemp);
			strcat(buff, "Temperature: ");
			strcat(buff, sendTemp);
			strcat(buff, "\n");
			strcat(buff, "Humidity: ");
			gcvt(humidity,6,sendTemp);
			strcat(buff, sendTemp);

			// Sending HTML to the client
			n = SendServer(newsockfd, buff);

			close(newsockfd);
			freei2cDevice(device);
			return 0;
		
			}
		if (argc == 3){
			int sockfd, portno,n;
        		struct sockaddr_in serv_addr;
        		struct hostent*server;
        		char buffer[BUFFER];

        		if (argc != 3){
            	    		fprintf(stderr,"usage %s hostname port\n", argv[0]);
                		exit(0);
       	 			}

			portno =atoi(argv[2]);

        		sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        		if (sockfd<0)
                		error("ERROR openingsocket");
			server =gethostbyname(argv[1]);
			if(server== NULL){
				fprintf(stderr,"ERROR,no suchhost\n");
			exit(0);
			}

			bzero((char *) &serv_addr,sizeof(serv_addr));
			serv_addr.sin_family =AF_INET;
			bcopy((char *)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
			serv_addr.sin_port =htons(portno);

			if(connect(sockfd, (const struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
				error("ERROR connecting");

			printf("Please press the Enter Key.\n");
			bzero(buffer,BUFFER);fgets(buffer,BUFFER-1,stdin);
			n =send(sockfd,buffer,strlen(buffer),0);
			if (n< 0)
				error("ERROR writing to socket");
				bzero(buffer,BUFFER);
				n = recv(sockfd,buffer,BUFFER-1,0);
			if (n <0)
				error("ERROR reading from socket");
			printf("%s\n",buffer);
			close(sockfd);
			return 0;	
			}
		}
	return 0;
}
