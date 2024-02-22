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

void sig_usr(int signo ){
	/* argument is signal number */
   if( signo == SIGUSR1 )
      printf("\nReceived signal from interface\n");
   else
      printf("Error: received signal %d\n", signo);
   signal( SIGUSR1,SIG_IGN);
   return;
}


int main(int argc,char* argv[] ){
	int num_read;
	int fd2;
	char my_char;
	int flip;
	int frequency;
	int num_iterations;
	int which_bit;
	unsigned char mask;

	// check for correct number of command line arguments
	if (argc != 3){
		fprintf(stderr, "usage: %s frequency_of_noise num_iterations \n", argv[0]);
		exit(0);
	}
	// extract argument values
	frequency = atoi(argv[1]);
	num_iterations = atoi(argv[2]);

	// get pid and display to screen so user can provide to interface
	pid_t my_pid = getpid();
	printf("noise_maker's pid id %d \n", my_pid);

	// install sig_usr as the signal handler for SIGUSR1
   if( signal( SIGUSR1,sig_usr ) == SIG_ERR )
      printf("Cannot catch SIGUSR1\n");

	// wait for a signal from interface
   // pause until signal handler has processed signal 
   pause();

	// obtain pid for interface so that we can send 
	// it a signal once the noise_making has completed
	printf("Enter the pid for interface: ");
	pid_t other_pid;
	scanf("%d",&other_pid);

	// open files for input and output
	if ((fd2 = open("input.txt", O_RDWR)) == -1)
		perror("opening input file");

	// initialize for random number generation
	srand(time(NULL));

	// loop through the file
	//		- read a character
	//		- flip a coin
	//			- if heads, add noise
	//			- back up and write the updated character

	for (int i=0; i<num_iterations; i++){
		// read a character at time from the input file
		while ((num_read = read(fd2, &my_char, 1)) > 0){
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

				// back up by one so we can overwrite the prior character
				lseek(fd2, -1, SEEK_CUR);

				//overwrite the character in the file
				if (write(fd2, &my_char, 1) < 1){
					perror("writing updated char");
				}

			} //end if 
		} // end while

		// reposition file pointer back to beginning of file
		// so we can make another pass
		lseek(fd2,0,SEEK_SET);
	}//end for

	// close the file
	close(fd2);

	// and send a signal to interface so that it can
	// proceed to display the updated text 
	kill(other_pid, SIGUSR2);

	// and then exit
	exit(0);
}
