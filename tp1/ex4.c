#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int numAppel = 0;

void raz(int sig){
	numAppel = 0;
	printf("Appuyer deux fois sur Ctrl-C pour terminer le processus.\n");
}

void interuption(int sig){
	if (numAppel == 0){		
		numAppel++;
		printf("\nVous avez demandé la terminaison du processus. Appuyer une seconde fois sur Ctrl-C pour confirmer.\n");
		alarm(5);
	} else
		exit(0);
}

int main(){
	signal(SIGINT, interuption);
	signal(SIGALRM, raz);
	
	getchar();

	return 0;

}
