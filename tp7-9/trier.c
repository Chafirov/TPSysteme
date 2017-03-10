/*
 * Classement dans l'ordre alphab�tique des noms des fichiers contenus
 * dans un r�pertoire et ses sous-r�pertoires.
 *
 * Utilisation : trier <r�pertoire>
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

   /* Traitement des param�tres */
   if (argc == 2) {
      recherche.nomRepertoire = argv[1];
   } else {
      printf("Usage : %s <r�pertoire>\n", argv[0]);
      exit(1);
   }

   /* On remplit la liste */
   chercherFichiers(&recherche);

   /* On trie */
   listeTriee = trier(recherche.liste);

   /* On affiche la liste tri�e */
   afficherListeTrieeNoms(*listeTriee);

   return 0;
}
