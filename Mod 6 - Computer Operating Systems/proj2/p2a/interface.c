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

void sig_usr(int signo ){
   /* argument is signal number */
   if( signo == SIGUSR2 )
      printf("\nReceived signal that noise_maker is complete \n");
   else
      printf("Error: received signal %d\n", signo);
   //signal( SIGUSR2,SIG_IGN);
   return;
}


int main(int argc, char *argv[] ){
	char buf[BUF_CHARS];
	int num_read,num_written;
	int fd1, fd2;
	int noise_pid;

	if (argc != 2){
		printf("usage: interface pid_of_noise_maker \n");
		exit(0);
	}
	noise_pid = atoi(argv[1]);


	// prompt the user to enter a text block
	write(2, "\nEnter text, <CTRL-D> to end: \n", 32);

	// open up the file to which their text will be save
	// report any errors
	if((fd1 = open("input.txt", O_WRONLY | O_TRUNC | O_CREAT, PERM)) == -1){
		perror("opening initial text file");
		exit(0);
	}

	// receive user input, and write it out to the file
	// until the user enters <CTRL-D>
	while ((num_read = read(0, buf, BUF_CHARS)) > 0){
		num_written = write(fd1, buf, num_read);
		if (num_written != num_read) {
			perror("writing initial text file");
		}
	}

	//and then close the file
	close(fd1);

	// send signal TO noise_maker to indicate that the file is ready
	kill(noise_pid,SIGUSR1);

	// install sig_usr as the signal handler for SIGUSR2
	// so this program can handle that signal when received
	// from the noisemaker
   if( signal( SIGUSR2,sig_usr ) == SIG_ERR )
      printf("Cannot catch SIGUSR2\n");

	// now wait for a signal FROM noise_maker
	printf("\ninterface process %d, waiting for signal from noise_maker \n",
		getpid());
	pause();

	// open file, now with updated (noisy) content
	if ((fd2 = open("input.txt", O_RDONLY)) < 0){
		perror("opening updated text file");
		exit(0);
	}

	char my_char;

	printf("\nAfter noise_maker, the text is now: \n");
	// display updated content of file
	// reading and writing one character at a time from file to screen
	while ( (num_read = read(fd2, &my_char, 1)) > 0){
		num_written = write(1, &my_char, 1);
		if (num_written != num_read) {
			perror("writing updated text file");
		}
	}

	// then close the file
	close (fd2);

	// and exit
	return(0);
}
