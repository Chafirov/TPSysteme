#ifndef __TRI_FICHIER
#define __TRI_FICHIER

#include <liste-noms.h>
#include <liste-triee-noms.h>

/*
 * Structure de donn�es manipul�e par une recherche
 */
typedef struct {
   char      * nomRepertoire;
   ListeNoms * liste;
} RechercheNomsFichiers;

/*
 * Recherche de tous les noms des fichiers contenus dans un
 * r�pertoire (et ses sous-r�pertoires).
 */
void chercherFichiers(RechercheNomsFichiers * recherche);

/*
 *    Tri d'une liste de noms. La valeur de retour est un
 * pointeur vers une liste tri�es de noms contenant les
 * noms pr�sents dans la liste pass�e en param�tre.
 *    La liste pass�e en param�tre est vid�e.
 */
ListeTrieeNoms * trier(ListeNoms * liste);


#endif
