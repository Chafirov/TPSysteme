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
	pthread_cond_init(&(f->cond), NULL);
	f->writers = 0;
	pthread_mutex_init(&(f->mutexListe), NULL);
}

void ouvrirListeNoms(ListeNoms* f){
	
	pthread_mutex_lock(&(f->mutexListe));
	f->writers++;
	
	pthread_mutex_unlock(&(f->mutexListe));
}

void fermerListeNoms(ListeNoms* f){

	pthread_mutex_lock(&(f->mutexListe));
	f->writers--;
	pthread_cond_broadcast(&(f->cond));

	pthread_mutex_unlock(&(f->mutexListe));
}

void insererNom(ListeNoms * f, Nom nom)
{
	pthread_mutex_lock(&(f->mutexListe));
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
	pthread_mutex_unlock(&(f->mutexListe));
	pthread_cond_signal(&(f->cond));
}

void extraireNom(ListeNoms * f, Nom * nom)
{	
	pthread_mutex_lock(&(f->mutexListe));
   CelluleNom * cv = f->premier; // Cellule vidée à détruire

	if (!f->premier && f->writers != 0){ 	
		pthread_cond_wait(&(f->cond), &(f->mutexListe));
   	}

	if (f->premier) {
     /* Son suivant devient le premier */
     *nom = f->premier->nom;
     f->premier = f->premier->suivant;

     /* Si c'était le dernier */
     if (f->dernier == cv) {
        f->dernier = NULL;
	
     }                                                                          

     free(cv);
   } else {
     *nom = NULL;
   }
	
	pthread_mutex_unlock(&(f->mutexListe));
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
   return (f.premier == NULL && f.writers == 0);
}
