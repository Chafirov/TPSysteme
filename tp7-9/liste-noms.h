/*
 * Interface d'une liste élémentaire de chaînes de caractères.
 *
 * Note : les chaînes de caractères sont copiées dans des zones mémoire
 * allouées lors de l'insertion dans la liste. L'utilisateur peut donc
 * détruire ou réutiliser les chaînes passées en paramètres et reçues des
 * sous-programmes de ce module.
 *
 * Auteur : E. Chaput
 * Date   : 08/10/2000
 */
#ifndef FILE_NOMS
#define FILE_NOMS

#include <nom.h>

struct ListeNoms;

typedef struct ListeNoms ListeNoms;

ListeNoms * creerListeNoms();
/*
 * Création d'une liste de noms
 * 
 * Assure
 *    listeNomsVide(*f)
 */

void initialiserListeNoms(ListeNoms * f);
/*
 * Initialisation de la liste de noms
 * 
 * Assure
 *    listeNomsVide(*f)
 */

void insererNom(ListeNoms * f, Nom nom);
/*
 * Insertion d'un nom en fin de liste
 */

void extraireNom(ListeNoms * f, Nom * nom);
/*
 * Extraction du premier élément de la liste.
 *
 * Retourne le premier élément ou NULL si la liste est vide
 */

void afficherListeNoms(ListeNoms f);
/*
 * Affichage de la liste, du premier au dernier élément
 * un élément par ligne.
 */

int listeNomsVide(ListeNoms f);

#endif
