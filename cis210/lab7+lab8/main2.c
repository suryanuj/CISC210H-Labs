//Name of file: main.c
//Name of author: Shaun Gupta
//Date: May 4, 2020
//Description of file: In this file is my work for Lab 8. Lab 8 asked us to practice with servers.
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void error(char *msg)
{
	perror(msg);
	exit(0);
}
//This function takes the pi's IP address and port # as arguments and then from that, you can type "http://<ip address>:<port number>" in a internet browser to connect to the webpage.
int main(int argc, char *argv[]){
	int sockfd, newsockfd, portno, clilen;
	char buffer[4096];
	struct sockaddr_in serv_addr, cli_addr;
	struct hostent*server;
	int n;

	if (argc < 2) {
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}
 	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
 	if (sockfd < 0)
 		error("ERROR opening socket");
 	bzero((char *) &serv_addr, sizeof(serv_addr));
 	portno = atoi(argv[1]);
 	serv_addr.sin_family = AF_INET;
 	serv_addr.sin_addr.s_addr = INADDR_ANY;
 	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)  
		error("ERROR onbinding");
	
	listen(sockfd,5);
	clilen= sizeof(cli_addr);
	newsockfd= accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);  

	if (newsockfd< 0) 
		error("ERROR on accept");
	bzero(buffer,4096);
	n = read(newsockfd,buffer,4095);
	
	if (n < 0) 
		error("ERROR reading from socket");

	printf("Here is the message:%s\n",buffer);
	n = write(newsockfd,"HTTP/1.1 200 OK \n\n<html><body style='color:white;background:url(https://www.eecis.udel.edu/~silber/sw.png)'><div style='width:400px;padding:10px;margin:100px auto;background:black;'><h1>May the 4<sup>th</sup> be with you...</h1><h2>...Always</h2></div></body></html>",268);

	if (n < 0) 
		error("ERROR writing to socket");
	close(newsockfd);
	close(sockfd);  
	return 0;
}


