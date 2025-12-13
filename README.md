# TicTacToe_Romane_MARTEAU--BAZOUNI
Projet de ProgAlgo, IMAC2028 S1

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

## Problèmes rencontrés / Chemin de pensée :

Problème rencontré #1 :
Au début, le currentPlayer était reconnu par son nom (currentPlayer=p1 puis à chaque fin de tour, currentPlayer changeait). Sauf que, avec la méthode des tableaux de 0 ajoutés dans la structure qui semblait beaucoup plus pratique pour améliorer l'IA (car elle a juste à savoir si la somme des lignes/colonnes et diagonales est égale à 2), arrayPlayer était alors écrasé à chaque fin de tour.
Je l'ai donc remplacé par un booléen isp1True : plus pratique.

Problème rencontré #2 :
Et si le joueur currentPlayer joue sur une case déjà prise ? --> ajout de la boucle while l.47 et l.60

Problème rencontré #3 :
J'avais laissé les joueurs rentrer un indice de case qui n'est pas compris dans [1, 9] ? --> ajout de " || currentBox > 9 || currentBox < 1" dans la boucle while des l.47 et l.60

Problème rencontré #4 :
Mon main.cpp était d'une centaine d'une ligne mais le code marchait très bien. Il y a-t-il moyen d'ajouter des fonctions dans un header pour alléger le main ?
--> Solution : création de la fonction runGame