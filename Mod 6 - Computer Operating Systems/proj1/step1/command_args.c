#include <stdio.h>
#include <stdlib.h>

// these two versions of main are equivalent
//int main(int argc, char *argv[]) {
int main(int argc, char **argv) {

	// a non-zero exit value indicates an error
	if(argc > 5){
		fprintf(stderr, "Usage: %s ... up to 4 additional arguments\n", argv[0]);
		exit(-1);
	}

	// display the argument count (argc)
	printf("argc is %d\n", argc);

	// display the argument vector (argv)
	for (int i=0; i<argc; i++){
		printf("argv[%d] is %s \n", i, argv[i]);
	}

	// a return value of 0 indicates success
	return 0;
}
