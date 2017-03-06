#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char** argv){
	
	int pipefd[2];
	pipe(pipefd);

	pid_t pid = fork();

	switch (pid){
	case -1:
		perror("Erreur fork");
		exit(EXIT_FAILURE);
	break;

	case 0:
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execlp("find", "find",".", "-exec", "basename", "{}", ";", NULL);
		close(pipefd[1]);
	break;

	default:
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		execlp("sort", "sort", NULL);
		close(pipefd[0]);
		wait(NULL);
	break;
	}

	return 0;
}
