#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <errno.h>

#include <unistd.h>

#include <time.h>
#include <stdlib.h>

#define PERM 0644


int main(int argc,char* argv[] ){
	int num_read;
	char my_char;
	int flip;
	int frequency;
	int which_bit;
	unsigned char mask;

	// check for correct number of command line arguments
	if (argc != 2){
		fprintf(stderr, "usage: %s frequency_of_noise \n", argv[0]);
		exit(0);
	}
	// extract argument values
	frequency = atoi(argv[1]);

	// initialize for random number generation
	srand(time(NULL));

	// read a character at time from the input file
	while ((num_read = read(0, &my_char, 1)) > 0){
		//generate a random number to decide whether or not to add noise
		flip = rand();

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
		}	

		//write the character to stdout 
		if (write(1, &my_char, 1) < 1){
			perror("writing updated char");
		}

	} //end while

	exit(0);
}
