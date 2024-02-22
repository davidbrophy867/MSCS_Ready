#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while ((nread = getline(&line, &len, stdin)) != -1) {
		printf("Read line of length %zu:\n", nread);
		fwrite(line, nread, 1, stdout);
	}

  free(line);
  exit(EXIT_SUCCESS);
}
