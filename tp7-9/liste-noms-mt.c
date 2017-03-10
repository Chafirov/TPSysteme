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

/*
 * Type d'une cellule de la liste
 */
typedef struct _CelluleNom {
   Nom                  nom;
   struct _CelluleNom * suivant;
} CelluleNom;

/*
 * Une liste de noms est caractérisée simplement par son premier
 * et son dernier éléments.
 */
struct ListeNoms {
   CelluleNom * premier;
   CelluleNom * dernier;
   pthread_mutex_t mutexListe;
   int wait4write;
};

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
	pthread_mutex_init(&(f->mutexListe), NULL);
	f->wait4write = FALSE;
}

void insererNom(ListeNoms * f, Nom nom)
{
	f->wait4write = TRUE;
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
   f->wait4write = FALSE;
   pthread_mutex_unlock(&(f->mutexListe));
}

void extraireNom(ListeNoms * f, Nom * nom)
{
	pthread_mutex_lock(&(f->mutexListe));
   CelluleNom * cv = f->premier; // Cellule vidée à détruire

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
	pthread_mutex_lock(&(f.mutexListe));
   return ((f.premier == NULL) && !(f.wait4write));
	pthread_mutex_unlock(&(f.mutexListe));
}
