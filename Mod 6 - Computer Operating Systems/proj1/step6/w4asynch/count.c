#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 512

int main() {

  char buffer[BUFSIZE];
  int  filedes;
  ssize_t nread;
  long total = 0;
  

  printf("Read BUFSIZ is %d \n", BUFSIZ);

  /* open the test file */
  if ((filedes = open("test.txt", O_RDONLY)) == -1)
   {
        printf("Couldn't open test.txt \n");
        exit(1);
   }

  /* read in loop until EOF */
  while ( (nread = read(filedes, buffer, BUFSIZE)) > 0)
   {
   printf("Read %ld bytes this time \n", nread);
   total += nread;
   }
  
  
  printf("Read %ld bytes in total \n", total);
  exit(0); /* normal exit */

}
