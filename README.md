# 3D-Morpion
ENSIIE, IPI, Projet 1, Morpion 3D

Projet 1 d'IPI, groupe actuellement composé de Flemmard et Enzo.

Objectif: Créer un Morpion en 3D, avec 2 Variantes de jeu et une option, son affichage et son interface. Pour plus de détail voir Sujet.pdf

Séparation du travail (Mettez vos noms/pseudos si vous voulez vous charger d'une partie et précisez en la branche:
-Modélisation:  Flemmard (modelisation).
  -Typedef de board (int ***, tableau en 3 dimensions)
  -Typedef de grid (int **, tableau en deux dimensions)
  -Typedef de stack (int *, tableau en une dimension)
  -Modélisation actuelle: Le plateau de jeu est un board de dimension fixe n*n*n+1. Créé par la fonction board create_board(int n)
  add_item et rem_item sont tout deux là pour respectivement ajouter un élément donné à une pile ou retirer l'élément du dessus.
  La taille maximale des piles n'étant pas précisé, l'utilisation de add_item sur une pile de taille maximale re-alloc une table deux fois plus grande et s'en sert comme nouvelle stack.
  Les éléments dans une pile sont des int/char. Le dernier élément d'une pile est toujours '\1' qui délimite la taille max d'une pile.
  De façon parallèle, on entretien une grid contenant la taille actuele de chaque pile pour savoir quel élément aller chercher.
-Affichage et interface:
  -Fonction(s) pour afficher l'état du jeu actuel conformément au sujet.
    -début d'une fonction d'affichage commencé dans modélisation. Encore buggué, il faudrait la rapattrier dans une branche affichage.
  -Fonction(s) pour récupérer les commandes
  -Fonction(s) pour synthétiser les deux


N'hésitez pas à commenter, proposer ou gueuler.
