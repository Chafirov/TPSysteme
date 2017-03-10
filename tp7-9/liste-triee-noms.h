/*
 * Interface d'une liste chaînée triée de chaînes de caractères.
 * Le tri est celui de strcmp(3)
 *
 * Note : les chaînes de caractères sont copiées dans des zones mémoire
 * allouées lors de l'insertion dans la liste. L'utilisateur peut donc
 * détruire ou réutiliser les chaînes passées en paramètres et reçues des
 * sous-programmes de ce module.
 *
 * Auteur : E. Chaput
 * Date   : 08/10/2000
 */
#ifndef LISTE_TRIEE_NOMS
#define LISTE_TRIEE_NOMS

#include <nom.h>  /* Pour le type Nom */

/*
 * Type d'une cellule de la chaîne
 */
typedef struct _CelluleTrieeNom {
   Nom nom;
   struct _CelluleTrieeNom * suivant;
} CelluleTrieeNom;

/*
 * Une liste de noms est caractérisée simplement par son premier
 * et son dernier élément
 */
typedef struct {
   CelluleTrieeNom * premier;
   CelluleTrieeNom * dernier;
} ListeTrieeNoms;

void initialiserListeTrieeNoms(ListeTrieeNoms * l);
/*
 * Initialisation de la liste de noms
 */

void trierNom(ListeTrieeNoms * l, Nom nom);
/*
 * Insertion d'un nom à sa place dans la liste
 */

void extrairePremierNom(ListeTrieeNoms * l, Nom * nom);
/*
 * Extraction du premier élément de la liste
 */

void afficherListeTrieeNoms(ListeTrieeNoms l);
/*
 * Affichage de la liste, du premier au dernier élément
 * un élément par ligne.
 */

int listeTrieeVide(ListeTrieeNoms l);
#endif
