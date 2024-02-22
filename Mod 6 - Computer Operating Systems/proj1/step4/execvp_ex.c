#include <unistd.h>

int main() {
	/* 
	 * Notes:
	 * The first argument is the name of the command.
	 * The second argument is the address of an array 
	 * that contains the name of the command, all the arguments
	 * thar are passed to the command, and a terminating NULL.
	 */
	char *argv[] = {"ls", "-l", "-t", "-a", NULL};
	execvp(argv[0], argv);
	return 0;
}
