#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define SIZE_BUF 10

ssize_t readWrite(int fdin, int fdout, void* buf, size_t count){

	ssize_t nbChar = read(fdin, (void*)buf, count);
	write(fdout, (void*)buf, nbChar);

	return nbChar;
	
}

int main(int argc, char** argv){

	int pipefd[2];

	char buf[SIZE_BUF];

	pipe(pipefd);
	pid_t pid = fork();
	
	switch (pid) {
	case -1:
		perror("fork");
		exit(EXIT_FAILURE);
	break;

	case 0:
		close(pipefd[1]);
	
		while(readWrite(pipefd[0], STDOUT_FILENO, (void*)buf, SIZE_BUF) == SIZE_BUF)
		
		close(pipefd[0]);
	break;
	
	default:	
		close(pipefd[0]);
	
		while(readWrite(STDIN_FILENO, pipefd[1], (void*)buf, SIZE_BUF)== SIZE_BUF)
		
		close(pipefd[1]);

		wait(NULL);
	break;
	}

	return 0;
}
