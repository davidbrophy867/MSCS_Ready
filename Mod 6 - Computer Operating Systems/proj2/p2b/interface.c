#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include <stdio.h>
#include <errno.h>

#include <unistd.h>
#include <stdlib.h>

#include <signal.h>

#define BUF_CHARS 512
#define PERM 0644

int main(int argc, char *argv[] ){
	char buf[BUF_CHARS];
	int num_read,num_written;

	if (argc != 1){
		printf("usage: interface \n");
		exit(0);
	}

	// prompt the user to enter a text block
	write(2, "\nEnter text, <CTRL-D> to end: \n", 32);

	// receive user input, and write it out to stdout
	// until the user enters <CTRL-D> 
	while ((num_read = read(0, buf, BUF_CHARS)) > 0){
		num_written = write(1, buf, num_read);
		if (num_written != num_read) {
			perror("writing initial text file");
		}
	}

	// and exit
	return(0);
}
