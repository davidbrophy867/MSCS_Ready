#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define PERMS 0644

char *filename="newfile";

int main()
{

  int filedes;

  if ((filedes = open(filename, O_RDWR|O_CREAT, PERMS)) == -1)
   {
        printf("Couldn't open %s\n", filename);
        exit(1); /* abnormal (error) exit */
   }

  /* read/write in loop until EOF */

 exit(0); /* normal exit */

}

