#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  printf("my_shell: ");

	while ((nread = getline(&line, &len, stdin)) != -1) {
		printf("line entered: ");
		fwrite(line, nread, 1, stdout);
    printf("\nmy_shell: ");
	}

  free(line);
  exit(EXIT_SUCCESS);
}
