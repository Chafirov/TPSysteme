/*
* Classement dans l'ordre alphabétique des noms des fichiers contenus
* dans un répertoire et ses sous-répertoires.
*
* Utilisation : trier <répertoire>
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
	return (void*)trier((ListeNoms*)attr);
}

void* chercherFichiers_mt(void* attr){
	chercherFichiers((RechercheNomsFichiers*)attr);
	return (void*)1;
}	

int main(int argc, char * argv[])
{
	RechercheNomsFichiers   recherche;
	ListeTrieeNoms        * listeTriee = NULL;
	
	/* Initialisation de la structure de recherche */
	recherche.liste = creerListeNoms();
	
	/* Traitement des paramètres */
	if (argc == 2) {
		recherche.nomRepertoire = argv[1];
	} else {
		printf("Usage : %s <répertoire>\n", argv[0]);
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
	
	/* On affiche la liste triée */
	afficherListeTrieeNoms(*listeTriee);
	
	return 0;
}
