/*
 * noise_server.c -- a stream "noise" server
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define MYPORT 7777	// the port users will be connecting to -- choose your own

#define BACKLOG 10	 // how many pending connections queue will hold

//for handling child processes as they terminate
void sigchld_handler(int s) {
	while(waitpid(-1, NULL, WNOHANG) > 0);
}

int main(int argc, char *argv[]) {
	int sockfd, new_fd;  			// listen on sock_fd, new connection on new_fd
	struct sockaddr_in my_addr;	// my address information
	struct sockaddr_in their_addr; // connector's address information
	socklen_t sin_size;
	struct sigaction sa;
	int yes=1;
	unsigned char my_char;
	int flip, mask, which_bit, frequency;
	int numbytes;

	// check number of arguments
	if (argc != 2){
		fprintf(stderr, "usage: %s frequency_of_noise \n", argv[0]);
		exit(0);
	}

	// extract frequency parameter
	frequency = atoi(argv[1]);


	/*
	 * create a socket
	 * report any errors
	 */
	if ((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1) {
		perror("socket");
	}

	/*
	 * set the socket options
	 * report any errors
	 */
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {//--
 		perror("setsockopt");
 	}

	/*
	 * fill in the my_addr structure appropriately
	 */
	my_addr.sin_family = AF_INET;
 	my_addr.sin_port = htons(MYPORT);
 	my_addr.sin_addr.s_addr = INADDR_ANY;
 	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

	/*
	 * bind the address to the socket
	 * report any errors
	 */
 	if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
 		perror("error assigning address to socket ");
 	}

	/*
	 * invoke listen to indicate that this socket is for passive listening
	 * (i.e., it is the server)
	 * specify the number of connections that may queue to connect (the backlog)
	 * report any errors
	 */
 	if (listen(sockfd, BACKLOG) == -1) {
 		perror("error marking socket as passive ");
 	}

	/*
	 * install the signal handler and process as needed
	 */
	sa.sa_handler = sigchld_handler; // reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	/*
	 * main accept() loop
	 */
	while(1) {
		// get the size of the address structure designed to
		// hold the address of the connecting client (their_addr)
		sin_size = sizeof their_addr;

		/*
		 * wait for a connection (accept)
		 * and store the returned fd in new_fd
		 * report any errors
		 */
 		if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1) {
 			perror("error extracting connection request from queue");
 		}

		// call fork and use the return value to decide
		// if the process that returns from fork is the parent or the child
		// if (your code goes here ...) {
		if (fork() == 0 ) { // this is the child process

			// close the accepting socket -- child doesn't need it
			close(sockfd);


		   /*
			 * block of code below reads the text stream
			 * from the client, adds noise with some frequency
			 * and sends back when done
			 */

			// get the first character
			if ((numbytes = recv(new_fd, &my_char, 1, 0)) == -1) {
	        perror("error receiving data from client ");
	    	}

			/*
			 * while the number of bytes read is less than zero AND
			 * the character is now ETB (end transmission block) (23)
			 */ //is this supposed to say not less then zero and not ETB?
			while(!(numbytes < 0) && (my_char != 23)){	// ???????????????????????
				// read a character at time from the input file
				//generate a random number to decide whether or not to add noise
				//recv(new_fd, &my_char, 1, 0);
				flip = rand();
				// 'flip a coin' to decide to add noise
				// not really a coin flip because frequency controls
				// how often we get heads
				if ((flip % frequency) == 0){
					// if we're flipping ...

					//create a bit mask with the value 1
					mask = 0b00000001;

					//generate a random number to decide which bit to flip
					flip = rand();

					//and then flip it
					which_bit = flip % 6;

					//shift the 1 in the mask to the selected position
					mask = mask << which_bit;

					//apply the xor operation to the original char to flip the bit
					my_char ^= mask;

				} //end if

				/*
				 * in any case, send the character back to the client
				 * report errors
				 */
				 if (send(new_fd, &my_char, 1, 0) == -1){
		 				perror("error sending dataing to client");
		 		}

				// and read another character before looping back to top of while
				numbytes = recv(new_fd, &my_char, 1, 0);
    		} // end while

			printf("client request serviced \n");
			// close that connection and end this child process
			// your code goes here
			exit(0);

		}//end if fork

		// parent code
		// close the fd returned by accept -- pparent doesn't need this
		close(new_fd);

	} // end of while(1) loop
	return(0);
}
