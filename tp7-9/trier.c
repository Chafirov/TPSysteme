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

#include <tri-fichier.h>

int main(int argc, char * argv[])
{
   RechercheNomsFichiers   recherche;
   ListeTrieeNoms        * listeTriee;

   /* Initialisation de la structure de recherche */
   recherche.liste = creerListeNoms();

   /* Traitement des paramètres */
   if (argc == 2) {
      recherche.nomRepertoire = argv[1];
   } else {
      printf("Usage : %s <répertoire>\n", argv[0]);
      exit(1);
   }

   /* On remplit la liste */
   chercherFichiers(&recherche);

   /* On trie */
   listeTriee = trier(recherche.liste);

   /* On affiche la liste triée */
   afficherListeTrieeNoms(*listeTriee);

   return 0;
}
