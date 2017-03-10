/*
 * Interface d'une liste cha�n�e tri�e de cha�nes de caract�res.
 * Le tri est celui de strcmp(3)
 *
 * Note : les cha�nes de caract�res sont copi�es dans des zones m�moire
 * allou�es lors de l'insertion dans la liste. L'utilisateur peut donc
 * d�truire ou r�utiliser les cha�nes pass�es en param�tres et re�ues des
 * sous-programmes de ce module.
 *
 * Auteur : E. Chaput
 * Date   : 08/10/2000
 */
#ifndef LISTE_TRIEE_NOMS
#define LISTE_TRIEE_NOMS

#include <nom.h>  /* Pour le type Nom */

/*
 * Type d'une cellule de la cha�ne
 */
typedef struct _CelluleTrieeNom {
   Nom nom;
   struct _CelluleTrieeNom * suivant;
} CelluleTrieeNom;

/*
 * Une liste de noms est caract�ris�e simplement par son premier
 * et son dernier �l�ment
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
 * Insertion d'un nom � sa place dans la liste
 */

void extrairePremierNom(ListeTrieeNoms * l, Nom * nom);
/*
 * Extraction du premier �l�ment de la liste
 */

void afficherListeTrieeNoms(ListeTrieeNoms l);
/*
 * Affichage de la liste, du premier au dernier �l�ment
 * un �l�ment par ligne.
 */

int listeTrieeVide(ListeTrieeNoms l);
#endif
