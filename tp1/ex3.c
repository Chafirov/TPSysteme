#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int compteur;

int numAppel = 0;

int try(int ret){
	if (ret == -1){
		perror("Erreur signal");
		exit(EXIT_FAILURE);
	}
	return ret;	
}

void annulCtrlC(int sig){
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


void raz(int sig){
	printf("%i\n", compteur);
	compteur = 0;
}

void incr(int sign){
	compteur++;
}

int main(){
	try((int)signal(SIGUSR1, raz));
	try((int)signal(SIGUSR2, incr));
	try((int)signal(SIGINT, interuption));
	try((int)signal(SIGALRM, annulCtrlC));
	try((int)signal(SIGKILL, annulCtrlC));

	getchar();

	return 0;

}
