/*
 * Interface d'une liste �l�mentaire de cha�nes de caract�res.
 *
 * Note : les cha�nes de caract�res sont copi�es dans des zones m�moire
 * allou�es lors de l'insertion dans la liste. L'utilisateur peut donc
 * d�truire ou r�utiliser les cha�nes pass�es en param�tres et re�ues des
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
 * Cr�ation d'une liste de noms
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
 * Extraction du premier �l�ment de la liste.
 *
 * Retourne le premier �l�ment ou NULL si la liste est vide
 */

void afficherListeNoms(ListeNoms f);
/*
 * Affichage de la liste, du premier au dernier �l�ment
 * un �l�ment par ligne.
 */

int listeNomsVide(ListeNoms f);

#endif
