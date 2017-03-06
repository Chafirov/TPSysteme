#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main(int argc, char** argv){

	int fdin = open(argv[1], O_RDONLY);
	int fdout = open(argv[2], O_RDWR|O_CREAT, S_IRWXU);

	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);

	execlp("tr", "tr","'A-Z'", "'a-z'", NULL);
	exit(EXIT_FAILURE);
	
	return 0;
}
