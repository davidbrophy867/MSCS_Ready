/*
 * string-client.c -- a stream socket client demo
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

/* define a port number to connect to ....*/
/* use 777 + your group number */
#define PORT 7777+4 // the port client will be connecting to

#define MAXDATASIZE 100 // max number of bytes we can get at once

int main(int argc, char *argv[]) {
	int sockfd, numbytes;
	char buf[MAXDATASIZE];
	struct hostent *he;
	struct sockaddr_in their_addr; // connector's address information
	int retval;

	if (argc != 2) {
		fprintf(stderr,"usage: client hostname\n");
		exit(1);
	}

	/// get the host info
	/*
	 *  Quiz Question 12 -- how can we get the host entry info
	 *  in a struct hostent, given a host name?
	 */
    he=gethostbyname(argv[1]);

    if (he == NULL) {
        perror("error getting host entry info ");
        exit(1);
    }

	// create socket structure through which the client
	// can connect to the server
	/*
	 * Quiz Question 13 -- how can we create the
	 * socket structure and receive as a return value the
	 * file descriptor associated with that connection?
	 */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// report errors
	if (sockfd  == -1) {
        perror("error creating the client socket structure");
        exit(1);
    }

	 // set up the data structure containing the server's address
    their_addr.sin_family = AF_INET;    // host byte order
    their_addr.sin_port = htons(PORT);  // short, network byte order
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    bzero(&(their_addr.sin_zero), 8);   // zero the rest of the struct

	 //and then make the connection
	/*
	 * Quiz Question 14 -- how can the client now connect to the server?
	 */
 	retval = connect(sockfd,(struct sockaddr *)&their_addr, sizeof(struct sockaddr));

    if (retval == -1) {
        perror("error making client connection to server");
        exit(1);
    }

	// prompt user to enter a string
	 bzero(buf, MAXDATASIZE);
	 printf("Please enter a string: ");
	 scanf("%[^\t\n]",buf);
	 printf("User entered:  %s \n", buf);

	// then send that initial string to the server
	/*
	 * Quiz Question 15 -- how can the client now send the string to the server?
	 */
	retval = send(sockfd, buf, strlen(buf),0);

	if (retval == -1){
		perror("error when client sends string to server");
		exit(1);
	}

	// Receive back the reversed string
	/*
	 * Quiz Question 16 -- how can the client now receive the reversed string
	 * back from the server?
	 */
	 numbytes = recv(sockfd, buf, MAXDATASIZE, 0);

	if (numbytes == -1) {
		perror("error when client tries to receive string from server");
		exit(1);
  	}
	// ensure it is null-terminated
  	buf[numbytes] = '\0';

	// display the reversed string
	printf("Server replied: %s\n",buf);
	close(sockfd);
	/*
	 * Quiz Question 17 -- how can the client terminate its connection
	 * to the server?
	 */
   //???
	return 0;
}
