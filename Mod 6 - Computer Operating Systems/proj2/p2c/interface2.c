#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include <stdio.h>
#include <errno.h>

#include <unistd.h>
#include <stdlib.h>

#include <signal.h>

#define BUF_CHARS 256
#define PERM 0644


int main(int argc, char *argv[] ){
	char buf[BUF_CHARS];
	int num_read,num_written;
	int return_pid;
	int top[2];
	int bottom[2];
	int frequency;
	char my_char;

	// check for the correct number of command line arguments
	if (argc != 2){
		printf("usage: interface2 frequency \n");
		exit(0);
	}
	// extract the frequency value
	frequency = atoi(argv[1]);

	// create two pipes (top and bottom) and report errors as needed
	if (pipe(top) < 0) perror("pipe error on top pipe");
	if (pipe(bottom) < 0) perror("pipe error on bottom pipe");

	// set up arguments for use with execl, that is:
	// create strings to represent integer values for frequency,
	// and the file descriptors through which noise_maker will communicate

	char freq[10];
	char read_fd[10];
	char write_fd[10];

	sprintf(freq, "%d", frequency);
	sprintf(read_fd, "%d", top[0]);
	sprintf(write_fd, "%d", bottom[1]);

	// fork off a child process
	return_pid = fork();

	// and then decide which case this now is -- child or parent
	if (return_pid < 0){
		perror("fork error");
		exit(3);
	}
	else if (return_pid == 0){ // this is the child process
		// close write end of the top pipe
		close(top[1]);

		// close read end of the bottom pipe
		close(bottom[0]);

		// and then exec noise_maker -- suggest using execl, which is a null-terminated list of parameters
		// int execl(const char *pathname, const char *arg, ... /* (char  *) NULL */);
		execl("./noise_maker", "./noise_maker", freq, read_fd, write_fd, NULL); //"usage: %s frequency_of_noise read_fd write_fd ---------------------------------------
		printf("should not get to this point ! \n");
	}
	else{ // this is the parent process
		// close read end of the top pipe
		close(top[0]);

		// close write end of the bottom pipe
		close(bottom[1]);

		// prompt the user to enter a text block
		printf("\nEnter text, <CTRL-D> to end:\n");

		// receive user input, and write it out to the PIPE
		// until the user enters <CTRL-D>
		while ((num_read = read(0, buf, BUF_CHARS)) > 0){
			num_written = write(top[1], buf, num_read);
			if (num_written != num_read) {
				perror("writing to pipe");
			}
		}

		// and then close the write end of top
		// which is how noise_maker will get an EOF at the read end
		close(top[1]);

		// and then start reading from the bottom pipe
		// to get the noisy input from the child process (noise_maker))

		printf("\nAfter noise_maker, the text is now: \n");
		// display updated content by reading and writing
		// a character at a time from PIPE to screen
		while (read(bottom[0], &my_char, 1) > 0){
			if (write(1, &my_char, 1) < 1) {
				perror("writing to screen");
			}
		}
		printf("\n");

		// then close the PIPE
		close(bottom[0]);
	} // end else this is the parent

	// and exit
	return(0);
}
