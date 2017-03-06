#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int compteur;
	int status;

	pid_t pid = fork();	

	switch (pid) {
	case -1:
		perror("Echec fork");
		exit(0);
	break;

	case 0:
		for (compteur = 0; compteur < 20; compteur += 2){
			printf("compteur fils : %i\n", compteur);
			sleep(1);
		}
	break;

	default:
		for (compteur = 0; compteur < 20; compteur = compteur+1){
                        printf("%i : compteur pere : %i\n", pid, compteur);
			sleep(1);
		}
		wait(&status);
		printf("%i\n", status);
	break;	
	}
	
	return 0;
}
