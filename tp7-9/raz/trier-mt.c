/*
* Classement dans l'ordre alphab�tique des noms des fichiers contenus
* dans un r�pertoire et ses sous-r�pertoires.
*
* Utilisation : trier <r�pertoire>
*
* Auteur : E. Chaput
* Date   : 08/10/2000
*/
#include <stdio.h>
#include <stdlib.h>   /* malloc */
#include <string.h>
#include <pthread.h>

#include <tri-fichier.h>
#include <liste-noms-mt.h>

void* trier_mt(void* attr){
	ListeTrieeNoms* listeTriee = trier((ListeNoms*)attr);
	afficherListeTrieeNoms(*listeTriee);
	printf("Tri fini\n");	

	return (void*)trier((ListeNoms*)attr);
}

void* chercherFichiers_mt(void* attr){
	RechercheNomsFichiers* recherche = (RechercheNomsFichiers*)attr;
	chercherFichiers(recherche);
	recherche->liste->writing = 0;
	printf("Recherche terminee : writing = %i\n", recherche->liste->writing);
	return (void*)1;
}	

int main(int argc, char * argv[])
{
	RechercheNomsFichiers   recherche;
	ListeTrieeNoms        * listeTriee = NULL;
	
	/* Initialisation de la structure de recherche */
	recherche.liste = creerListeNoms();
	
	/* Traitement des param�tres */
	if (argc == 2) {
		recherche.nomRepertoire = argv[1];
	} else {
		printf("Usage : %s <r�pertoire>\n", argv[0]);
		exit(1);
	}
	
	pthread_t threadRecherche;
	pthread_t threadTri;
	
	/* On remplit la liste */
	pthread_create(&threadRecherche, NULL, chercherFichiers_mt, (void*)(&recherche));
	//chercherFichiers(&recherche);
	
	/* On trie */
	pthread_create(&threadTri, NULL, trier_mt, (void*)(recherche.liste));
	
	pthread_join(threadRecherche, NULL);
	pthread_join(threadTri, (void**)listeTriee);
	
	/* On affiche la liste tri�e */
	//afficherListeTrieeNoms(*listeTriee);
	
	return 0;
}
