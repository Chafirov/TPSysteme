#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

pid_t pid;

void tuerFils(int sig){
	kill(pid, SIGINT);
}


int main(int argc, char** argv){
	
	pid = fork();
	
	if (pid == 0){
		execvp(argv[2], &argv[2]);
	} else {
		int status;
	
		alarm(atoi(argv[1]));
		signal(SIGALRM, tuerFils);
	
		wait(&status);
	}


	return 0;
}
