#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	// a non-zero exit value indicates an error
	if(argc > 2){
		fprintf(stderr, "Usage: %s [batchfile]\n", argv[0]);
		exit(-1);
	}
  else if(argc == 2){//batch mode
    printf("Batch processing mode with file %s\n", argv[1]);
  }
  else{//interactive mode
    printf("Interactive mode\n");
  }

	// a return value of 0 indicates success
	return 0;
}
