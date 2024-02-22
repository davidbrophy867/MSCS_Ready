#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define _GNU_SOURCE
#define MAX_ARGS 32

void parse(char*, char**);
void interactive();
void execute(char**);

int main(int argc, char *argv[]) {
  //my_shell1 will go in here to determine mode
  interactive();

  return 0;

}

//--------------------------------------------------------------------

void parse(char *line, char **my_args){ //copied from my_shell3
   char *token;
   int my_argc = 0;
   const char s[3] = " \n";

	/* set all the elements of my_args to null (0) */
   bzero(my_args,MAX_ARGS);

	/* temporary code: echo out line received */
  //printf("\nline recieved: %s", line);

	/* use strtok to pull out all the tokens
    * and put them into the my_args array
	 */

  /* get the first token */
  token = strtok(line, s);
  my_args[my_argc] = token;

  /* walk through other tokens */
  while( token != NULL ) {
     //printf( " %s\n", token );
     token = strtok(NULL, s);
     my_argc++;
     my_args[my_argc] = token;
  }


	/* temporary code: display the my_argc counter value
    * and updated elements of the my_args vector
    */
    /*
    printf("my_argc is %i\n", my_argc);
    for(int i = 0; i < my_argc; i++){
      printf("my_args[%i] is %s\n", i, my_args[i]);
    }
    */
}

void interactive(){ //my_shell3 main program, which itself uses my_shell2
   // variable declarations go here
   char *line_buf = NULL;
   size_t len = 0;
   ssize_t nread;
   char *my_args[MAX_ARGS];

   // display initial my_shell: prompt
  printf("my_shell: ");

  //while ( ... you read in the line of input into line_buf using getline ... ){
      //parse(line_buf, my_args);
  while ((nread = getline(&line_buf, &len, stdin)) != -1) {
    parse(line_buf, my_args); //splits line into array of words

		// later we'll add more special-case code here
		// but for now, just execute whatever the user typed in
    if(strcmp(my_args[0], "exit") == 0){ //exit
      free(line_buf);
      exit(EXIT_SUCCESS);
    }
    else if(strcmp(my_args[0], "my_ls") == 0){ //my_ls
      printf("my_ls: a built-in command, recieving parameters:\n");
      int i = 0;
      while(my_args[i]!=NULL){
        printf("%s\n",my_args[i]);
        i++;
      }
    }
    else if(strcmp(my_args[0], "my_chmod") == 0){ //my_chmod
      printf("my_chmod: a built-in command, recieving parameters:\n");
      int i = 0;
      while(my_args[i]!=NULL){
        printf("%s\n",my_args[i]);
        i++;
      }
    }
    else if(strcmp(my_args[0], "my_cp") == 0){ //my_cp
      printf("my_cp: a built-in command, recieving parameters:\n");
      int i = 0;
      while(my_args[i]!=NULL){
        printf("%s\n",my_args[i]);
        i++;
      }
    }
    else{
      execute(my_args);
    }


    // display my_shell: prompt again
    printf("my_shell: ");
  }

  //redundant / unused
  free(line_buf);
  exit(EXIT_SUCCESS);
}

void execute(char **argv){
	pid_t pid;
	int status;
  pid_t wait_result;

	// fork a child process and check the return value for errors
	// if error then print *** ERROR: forking child process failed"
	// and exit with error code 1
  pid = fork();

  if (pid < 0) {
		perror("ERROR: forking child process failed");
    exit(1);
	}

	// if the return value indicates that this is the child
	// invoke execvp, using the content of the argv array for parameters
  if (pid == 0) {
    execvp(argv[0], argv);
  }
	// if the return value indicates that this is the parent
	// wait for the child; capture child status in the int status variable
  else{
    wait_result = waitpid(pid, &status, WUNTRACED);
  }
}
