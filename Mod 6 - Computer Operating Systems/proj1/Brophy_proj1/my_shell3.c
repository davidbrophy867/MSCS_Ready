#include <string.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>
#define MAX_ARGS 32

void parse(char*, char**);

int main(int argc, char *argv[]) {
  char *line_buf = NULL;
  size_t len = 0;
  ssize_t nread;
  char *my_args[MAX_ARGS];

  printf("my_shell: ");

	while ((nread = getline(&line_buf, &len, stdin)) != -1) {
		//printf("line entered: ");
		//fwrite(line_buf, nread, 1, stdout);
    parse(line_buf, my_args);

    printf("\nmy_shell: ");
	}

  free(line_buf);
  exit(EXIT_SUCCESS);
}






void parse(char *line, char **my_args){
   char *token;
   int my_argc = 0;
   const char s[3] = " \n";

	/* set all the elements of my_args to null (0) */
   bzero(my_args,MAX_ARGS);

	/* temporary code: echo out line received */
  printf("\nline recieved: %s", line);

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
    printf("my_argc is %i\n", my_argc);
  for(int i = 0; i < my_argc; i++){
    printf("my_args[%i] is %s\n", i, my_args[i]);
  }
}
