/* Implantation du module ListeNoms.
 *
 * Auteur : E. Chaput
 * Date   : 08/10/2000
 */
#include <liste-noms-mt.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <pthread.h>

#include <assert.h>

#define TRUE	1
#define FALSE	0
ListeNoms * creerListeNoms()
{
  ListeNoms * result = (ListeNoms *) malloc(sizeof(ListeNoms));
  initialiserListeNoms(result);
  return result;
}

void initialiserListeNoms(ListeNoms * f)
{
   f->premier = NULL;
   f->dernier = NULL;
	f->writing = 1;
	pthread_mutex_init(&(f->mutexListe), NULL);
	pthread_mutex_lock(&(f->mutexListe));
}

void insererNom(ListeNoms * f, Nom nom)
{
   CelluleNom * nc = (CelluleNom *)malloc(sizeof(CelluleNom));

   nc->nom = strdup(nom);

   /* Mise dans la chaine */
   nc->suivant = NULL;

   if (f->dernier != NULL) {
      f->dernier->suivant = nc;
   }
   f->dernier = nc;

   /* Si c'est le seul, c'est aussi le premier */
   if (f->premier == NULL) {
      f->premier = nc;
   }
   	printf("UNLOCK : element ajoute\n");
	pthread_mutex_unlock(&(f->mutexListe));
}

void extraireNom(ListeNoms * f, Nom * nom)
{
	printf("Demande de lecture\n");
	pthread_mutex_lock(&(f->mutexListe));
	printf("LOCK : lecture en cours\n");
   CelluleNom * cv = f->premier; // Cellule vidée à détruire

   if (f->premier) {
     /* Son suivant devient le premier */
     *nom = f->premier->nom;
     f->premier = f->premier->suivant;

     /* Si c'était le dernier */
     if (f->dernier == cv) {
        f->dernier = NULL;
	
     } else if (f->writing){
	printf("UNLOCK : lecture fini, mais ce n'est pas le dernier\n");
	pthread_mutex_lock(&(f->mutexListe));
	}

	//il n'y a plus d'ecriture                                                                           
	if (!(f->writing)){
		pthread_mutex_unlock(&(f->mutexListe));
		printf("UNLOCK: fin de lecture et recherche est fini\n");
	}
     free(cv);
   } else {
     *nom = NULL;
   }
}

void afficherListeNoms(ListeNoms f)
{
   CelluleNom * cc = f.premier;

   while (cc != NULL) {
      printf("%s\n", cc->nom);
      cc = cc->suivant;
   }
}

int listeNomsVide(ListeNoms f)
{
   return (f.premier == NULL);
}
