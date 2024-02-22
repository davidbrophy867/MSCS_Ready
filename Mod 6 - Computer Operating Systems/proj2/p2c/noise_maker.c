#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <errno.h>

#include <unistd.h>

#include <time.h>
#include <stdlib.h>

#include <signal.h>

#define PERM 0644

int main(int argc,char* argv[] ){
	int frequency;
	int read_fd, write_fd;
	int num_read;
	char my_char;
	int flip;
	int which_bit;
	unsigned char mask;

	// check for correct number of command line arguments
	if (argc != 4){
		fprintf(stderr, "usage: %s frequency_of_noise read_fd write_fd \n", argv[0]);
		exit(0);
	}

	// extract argument values (frequency, read_fd, write_fd)
	frequency = atoi(argv[1]);
	read_fd = atoi(argv[2]);
	write_fd = atoi(argv[3]);

	// initialize for random number generation
	srand(time(NULL));

	// loop through the input stream arriving through the pipe
	//		- read a character
	//		- flip a coin
	//			- if heads, add noise
	//			- write the (possibly) updated character back through the pipe

	// read a character at time from the input file
	while ((num_read = read(read_fd, &my_char, 1)) > 0){
			//generate a random number to decide whether or not to add noise
			flip = rand();

			// 'flip a coin' to decide to add noise
			// not really a coin flip because frequency controls
			// how often we get heads

			if ((flip % frequency) == 0){

				//create a bit mask with the value 1
				mask = 0b00000001;

				//generate a random number to decide which bit to flip
				flip = rand();
				which_bit = flip % 6;

				//shift the 1 in the mask to the selected position
				mask = mask << which_bit;

				//apply the xor operation to the original char to flip the bit
				my_char ^= mask;

			} //end if

		//write the character back to the interface
		// be sure to check for and report errors in writing
		if (write(write_fd, &my_char, 1) < 1) {
			perror("writing updated char");
		}

	} // end while


	// close the file descriptors for the pipe
	close(read_fd);
	close(write_fd);

	// and then exit
	exit(0);
}
