#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define PERM 0644

int bufsize=0;

int copyfile(const char *name1, const char *name2)
{
  
  int infile, outfile;
  ssize_t nread;
  char buffer[bufsize];
  
  if ((infile = open(name1, O_RDONLY))== -1)
   return(-1); /* error on open infile */
  
  if ((outfile = open(name2, O_WRONLY | O_CREAT | O_TRUNC, PERM))== -1)
  {
   close(infile);
   return(-2); /* error on open outfile */
  }
  
  while ( (nread=read(infile, buffer, bufsize)) > 0)
  {
   if (write(outfile, buffer, nread) < nread)
   { 
     close(infile);
     close(outfile);
     return(-3);  /* error on write */
   }
  }

close(infile);
close(outfile);

if (nread == -1)
  return(-4);     /* error on final read */
else
  return (0);

}

int main(int argc, char **argv) {

  if (argc != 4){
   printf("usage: %s infile outfile bufsize\n", argv[0]);
   exit(0);
  }

  bufsize = atoi(argv[3]);
  copyfile(argv[1],argv[2]);
}

