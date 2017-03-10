#ifndef __TRI_FICHIER
#define __TRI_FICHIER

#include <liste-noms.h>
#include <liste-triee-noms.h>

/*
 * Structure de données manipulée par une recherche
 */
typedef struct {
   char      * nomRepertoire;
   ListeNoms * liste;
} RechercheNomsFichiers;

/*
 * Recherche de tous les noms des fichiers contenus dans un
 * répertoire (et ses sous-répertoires).
 */
void chercherFichiers(RechercheNomsFichiers * recherche);

/*
 *    Tri d'une liste de noms. La valeur de retour est un
 * pointeur vers une liste triées de noms contenant les
 * noms présents dans la liste passée en paramètre.
 *    La liste passée en paramètre est vidée.
 */
ListeTrieeNoms * trier(ListeNoms * liste);


#endif
