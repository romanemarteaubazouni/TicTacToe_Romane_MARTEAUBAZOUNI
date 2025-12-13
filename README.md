# TicTacToe_Romane_MARTEAU--BAZOUNI
Projet de ProgAlgo, IMAC2028 S1

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


Amélioration de l'IA :
Faire une copie du tableau dans une fonction. Dans cette fonction, l'IA teste toutes les possibilités restantes et regarde si elle peut bloquer le joueur. Si elle peut, elle fait se mouv dans le "vrai tableau" (celui que l'utilisateur voit). Sinon, elle joue aléatoirement.