# TicTacToe_Romane_MARTEAU--BAZOUNI
Projet de ProgAlgo, IMAC2028 S1

Les librairies utilisées dans ce projet font parties de la bibliothèque standard C++.

Ce code a été testé sur Windows 11.

## L'organisation des dossiers :

```
- CMakeLists.txt
- README.md
- .gitignore
- src : le code
    - board.hpp
    - board.cpp : permet l'affichage du plateau de jeu

    - player.hpp
    - player.cpp : la structure Player (name et symbol) + fonction pour que l'utilisateur créé son joueur
    
    - game.hpp
    - game.cpp : fonctions d'initialisation du jeu (des joeurs et du mode de jeu) + fonctions parcourant les lignes/colonnes/diagonales pour la victoire du joeur + le déroulement d'une partie

    - ia.hpp
    - ia.cpp : fonction permettant à l'IA de jouer (c'est ici qu'est l'amélioration)

    - main.cpp
```

## L'amélioration réalisée :
L'IA est maintenant capable, à chaque tour, de déterminer si il existe une case avec laquelle le joeur humain peut gagner. Dans ce cas, elle le bloque. Elle peut aussi déterminer si il y a une case avec laquelle l'IA gagne. Sinon, elle joue aléatoirement.

Pour se faire, j'ai créé une fonction boxIA, qui copie le tableau de jeu. Pour chaque case, elle vérifie si elle est pleine. Si non, l'IA remplace le vide de la case par son symbole. Si elle gagne, elle choisit cette case. Si elle ne gagne nulle part, elle vérifie si l'humain gagne en re-parcourant le tableau. Si rien de tout ça, elle joue aléatoirement.

## Logique du code :

On initialise le mode de jeu et les joueurs. Tant que le joueur actuel (currentPlayer dans la fonction runGame) ne gagne pas, le joueur entre la case qu'il souhaite jouer (entre 1 et 9). Si la case est prise, il recommence. Pour l'IA, elle réalise les étapes décrites précedemment pour trouver sa case à jouer. La case du plateau est alors remplacée par le symbole du joueur actuel. A chaque tour, 3 fonctions (countLine, countColumn et countDiag) vérifient si le joueur gagne avec ce coup et une fonction vérifie si le match est nul.

## Problèmes rencontrés :

Problème rencontré #1 :
Et si le joueur currentPlayer joue sur une case déjà prise ? --> ajout de la fonction boxIsFull

Problème rencontré #2 :
Et si le joueur entre un numéro de case autre qu'un chiffre de 1 à 9 ? --> ajout de conditions

Problème rencontré #3 :
Mon main.cpp était d'une centaine d'une ligne mais le code marchait très bien. Il y a-t-il moyen d'ajouter des fonctions dans un header pour alléger le main ?
--> Solution : création de la fonction runGame

Problème rencontré #4 :
L'IA jouait toujours le coup dans la case ayant l'indice le plus haut car je n'avais pas fait 2 boucles "for" dans la fonction boxIA, donc boxToPlay été toujours écrasée --> ajout de 2 boucles