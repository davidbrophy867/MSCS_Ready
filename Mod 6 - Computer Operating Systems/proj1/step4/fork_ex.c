#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t return_pid = fork();
	
	if (return_pid < 0) {
		perror("Bad fork");
	}
        
	if (return_pid == 0) {
		// The child process
		printf("Child: pid: %d ; return_pid: %d\n", getpid(), return_pid);
    } 
	else {
		printf("Parent: pid: %d ; return_pid: %d\n", getpid(), return_pid);
    }
	return 0;
}
