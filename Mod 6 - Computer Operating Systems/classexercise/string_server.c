/*
 ** string_server.c -- a stream socket server demo
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

// the port users will be connecting to
// use 7777 + your_group_number
#define MYPORT 7777+4

#define BACKLOG 10	 // how many pending connections queue will hold
#define MAXDATASIZE 80	 // max size of message between client & server

// does nothing if a signal comes in ...
void sigchld_handler(int s) {
	while(waitpid(-1, NULL, WNOHANG) > 0);
}

int main(void)
{
	int sockfd, new_fd;  			// listen on sock_fd, new connection on new_fd
	struct sockaddr_in my_addr;	// my address information
	struct sockaddr_in their_addr; // connector's address information
	socklen_t sin_size;
	struct sigaction sa;
	int yes=1;
	char buf[MAXDATASIZE];
	int retval;
	int bytes_recvd;
	int bytes_sent;


	// Quiz question #1
	// Enter the code needed to create an endpoint for network communication
	// (i.e., open a socket)
	// assign the returned file descriptor to sockfd
	// Let the domain be the IPv4 Internet protocol,
	//     the type be sequenced, reliable, two-way, and connection-based
	//     the protocol can be specified as 0
	// sockfd = ???

	sockfd = socket(AF_INET,SOCK_STREAM,0);


	// report errors if they occur
	if (sockfd == -1) {
		perror("socket");
		exit(1);
	}

	// set appropriate options on that socket
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
		perror("setsockopt");
		exit(1);
	}

	// fill in the elements of the my_addr data structure
	// the structure is of type struct sockaddr_in
	my_addr.sin_family = AF_INET;		 		// host byte order
	/* Quiz question 2: how to set the port value? */
	//my_addr.sin_port = 7777+7;	   // short, network byte order */
	my_addr.sin_port = htons(MYPORT);	   // short, network byte order
	// automatically fill with my IP
	my_addr.sin_addr.s_addr = INADDR_ANY;
	// zero out the rest of the structure
	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

	/* Quiz question 3: what command assigns an address to the socket
	   created above? */
	retval = bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr);
	if (retval == -1) {
		perror("error assigning address to socket ");
		exit(1);
	}


	/* Quiz question 4:what command marks this socket as a passive socket? */
	retval = listen(sockfd, BACKLOG);
	/* Quiz question 5:what is the function of the BACKLOG argument?*/
	//retval = ????(sockfd, BACKLOG);
	if (retval == -1) {
		perror("error marking socket as passive ");
		exit(1);
	}

	// do some signal handling stuff to take care of dead processes
	sa.sa_handler = sigchld_handler; // reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	while(1) {  // main accept() loop
		sin_size = sizeof their_addr;
		/*
		 * Quiz question 6 :
		   Which call will extract the first connection request on the queue of
			pending connections for the listening socket, sockfd, and create a
			new connected socket, and return a new file descriptor referring to
			that socket.
			Note:
				* The newly created socket is not in the listening state.
				* The original socket sockfd is unaffected by this call.
		 */
		new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if (new_fd == -1) {
			perror("error extracting connection request from queue");
			continue;
		}
		if (fork() == 0 ) {
			// this is the child process
			// child doesn't need the listener
			/* Quiz question 7 - how can the child
			 * sever its connection to the listener?
			 */
			close(sockfd);

		bzero(buf,MAXDATASIZE);
		/*
		 * Quiz question 8 -- how can this process
		 * read data from the client through the new socket?
		 */
		bytes_recvd=recv(new_fd, buf, MAXDATASIZE, 0);
		if (bytes_recvd == -1) {
        perror("error receiving data from client ");
        exit(1);
    	}

		// add an end of string to the buffer
		buf[bytes_recvd] = '\0';

		// code below reverses the data into rev_buf
		char rev_buf[MAXDATASIZE];
		for (int i=0; i <= bytes_recvd; i++){
			rev_buf[i] = buf[bytes_recvd-(i+1)];
		}
		rev_buf[bytes_recvd] = '\0';

		/*
		 * Quiz question 9 -- how can this process
		 * send  data to the client through the new socket?
		 */
		bytes_sent = send(new_fd, rev_buf, bytes_recvd, 0);
		if (bytes_sent == -1){
				perror("error sending dataing to client");
		}

		/*
		 * Quiz question 10 -- how can the child process terminate
		 * its connection to the new socket?
		 */
		close(new_fd);
		exit(0);
		}

		else{
			//this is the parent
		/*
		 * Quiz question 11 -- how can the parent process terminate
		 * its connection to the new socket (which it does not need)
		 */
		close(new_fd);
		}
	}

	return 0;
}
