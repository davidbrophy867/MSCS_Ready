#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t return_pid;
	pid_t wait_result;
	int stat_loc;

	return_pid = fork();

	if (return_pid == 0) { // The child process
		printf("child: pid: %d ; return_pid: %d\n", getpid(), return_pid);
		sleep(1);
    } 
	else {
		wait_result = waitpid(return_pid, &stat_loc, WUNTRACED);
		printf("parent: pid: %d ; return_pid: %d\n", getpid(), return_pid);
		printf("unsigned integer value of stat_loc is %u\n", stat_loc);
    }
	return 0;
}
