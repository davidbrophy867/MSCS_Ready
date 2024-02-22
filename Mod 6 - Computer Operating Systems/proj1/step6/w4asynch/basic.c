#include <fcntl.h>
#include <unistd.h>

int main()
{
  int fd;
  ssize_t nread;
  char buf[1024];

  /* open file "data" for reading *
     if fd is negative -- an error (-1)
     if fd is non-negative, a file descriptor (fd)
     fd is used to identify and further access the file */
  fd = open("data-file", O_RDONLY);

  /* read in the data *
     try to read 1024 bytes from the file referred to by fd
     into the memory named "buf" */
  nread = read(fd, buf, 1024);

  /* close the file */
  /* releases that fd for future use*/
  /* program termination would have same effect */
  close(fd);

}

