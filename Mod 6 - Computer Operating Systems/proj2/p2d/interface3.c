/*
 * interface3.c -- a noise_making client program
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
#define PORT 7777 // the port client will be connecting to
#define BUFSIZE 256 // size of local buffer

#define MAXDATASIZE 100 // max number of bytes we can get at once

int main(int argc, char *argv[]) {
	int sockfd, numbytes, num_written;
	char buf[4096];
	struct hostent *he;
	struct sockaddr_in their_addr; // connector's address information
	char my_char;

	/*
	 * check for correct number of command line arguments
	 * display usage statement if incorrect
	 */
    if (argc != 2) {
        fprintf(stderr,"usage: client hostname\n");
        exit(1);
    }

	/*
	 * get the host info
	 * report errors
	 */
		if ((he = gethostbyname(argv[1])) == NULL) {
        perror("error getting host entry info ");
        exit(1);
    }

	/*
	 * create a socket
	 * report errors
	 */
	 if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
         perror("error creating the client socket structure");
         exit(1);
     }


	/*
	 * populate the their_addr structure with the
	 * server's info
	 */
	 their_addr.sin_family = AF_INET;
	 their_addr.sin_port = htons(PORT);
	 their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	 bzero(&(their_addr.sin_zero), 8);   // zero the rest of the struct

	/*
	 * connect to the server
	 * report errors
	 */
	 if ((connect(sockfd,(struct sockaddr *)&their_addr, sizeof(struct sockaddr))) == -1) {
			 perror("error making client connection to server");
			 exit(1);
	 }

	// prompt the user to enter a text block
	write(2, "\nEnter text, <CTRL-D> to end: \n", 32);

	/*
	 * in a while loop: receive user input, and write it out
	 * to the socket connection until the user enters <CTRL-D>
	 * report errors
	 */
	 while (read(0, buf, BUFSIZE) > 0){
		 if (send(sockfd, buf, strlen(buf),0) == -1) {
			 perror("error when client sends string to server");
		 }
	 }

	// create a character with the ETB (end of transaction block) ascii code
	// your code here
	unsigned char etb_char = 23;

	// send the ETB (end of transaction block) ascii code on the socket
	send(sockfd, &etb_char, sizeof(etb_char),0);

	printf("\nAfter noise_maker, the text is now: \n");

	/*
	 * Display updated (noisy) text, reading one character at a time
	 * from the socket and writing it to the screen
	 * report errors
	 */
		while ((numbytes = recv(sockfd, &my_char, 1, 0)) > 0){
			if (numbytes == -1) {
 	 			perror("error when client tries to receive string from server");
 	   	}

			if ((num_written = write(1, &my_char, 1)) < 1) {
				perror("writing to screen");
			}
		} //end while

	// and a final new line
	printf("\n");

	// then close the socket
	close(sockfd);

	return 0;
}
