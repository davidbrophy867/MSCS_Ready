#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

int main(void){
  int n;
  int fd_top[2];
  int fd_bottom[2];
  pid_t pid;
  char line[80];

  // create two pipes and check for errors
  if (pipe(fd_top) < 0) perror("pipe error on top pipe");
  if (pipe(fd_bottom) < 0) perror("pipe error on bottom pipe");

  if ((pid = fork()) < 0){ // fork off child process
    perror("fork error");
  }
  else if (pid > 0){ // parent process
    close(fd_top[0]); // close read on top
    close(fd_bottom[1]); // close write on bottom
    // parent prompts user for a string
    printf("Please enter a string to xmit\n");
    fgets(line,80,stdin);
    n = strlen(line);
    // parent sends string to child
    write(fd_top[1], line, n);
    // parent reads updated string from child
    n = read(fd_bottom[0], line, 80);
    // parent echos updated string to screen
    write(1,"Yes, I said ... " ,16);
    write(1,line,n);
    // parent waits for child
    if (waitpid(pid,NULL, 0) < 0) perror("waitpid error");
    // parent exits
    exit(0);
  }
  else{ // child process
    close(fd_top[1]); // close write on top
    close(fd_bottom[0]); // close read on bottom
    // Read a message from the parent.
    n = read(fd_top[0], line, 80);
    // Echo the message to the screen (Did you say?: $whatever).
    write(1,"Did you say? ... ",18);
    write(1,line, n);
    // Change the received message to all uppercase
    for (int i=0; i<n; i++)
      line[i] = toupper(line[i]);
    // Send it back to the parent.
    write(fd_bottom[1],line, n);
    exit(0);
  }
}
