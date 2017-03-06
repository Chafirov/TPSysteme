#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int compteur;

int numAppel = 0;

void annulCompt(int sig){	
	sigset_t mask; 
	if (numAppel == 0){
		numAppel = 1;
		sigemptyset(&mask);
		
		sigaddset(&mask, SIGUSR1);
		sigaddset(&mask, SIGUSR2);
		sigsuspend(&mask);
	} else {
		numAppel = 0;

	}
}


void raz(int sig){
	printf("%i\n", compteur);
	compteur = 0;
}

void incr(int sign){
	compteur++;
}

int main(){
	signal(SIGUSR1, raz);
	signal(SIGUSR2, incr);
	signal(SIGINT, annulCompt);

	getchar();

	return 0;

}
