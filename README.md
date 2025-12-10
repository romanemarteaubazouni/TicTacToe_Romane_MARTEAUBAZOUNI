# TicTacToe_Romane_MARTEAU--BAZOUNI
Projet de ProgAlgo, IMAC2028 S1

La structure Player a était légèrement modifiée par rapport à la consigne. J'y ai ajouté du tableau d'int arrayPlayer. Lorsque le joueur met son symbole dans une case, alors le arrayPlayer ajoute un 1 dans cette même case. Cela facilite les conditions countLine, countColumn et countDiag qui n'ont plus qu'à faire la somme des lignes/colonnes/diagonales. Ces tableaux auraient pu être directement écrits dans le main, mais pour éviter des lignes de codes en plus, je les ai mis dans la strucutre.

Problème rencontré #1 :
Au début, le currentPlayer était reconnu par son nom (currentPlayer=p1 puis à chaque fin de tour, currentPlayer changeait). Sauf que, avec la méthode des tableaux de 0 ajoutés dans la structure qui semblait beaucoup plus pratique pour améliorer l'IA (car elle a juste à savoir si la somme des lignes/colonnes et diagonales est égale à 2), arrayPlayer était alors écrasé à chaque fin de tour.
Je l'ai donc remplacé par un booléen isp1True : plus pratique.

Problème rencontré #2 :
Et si le joueur currentPlayer joue sur une case déjà prise ? --> ajout de la boucle while l.47 et l.60

Problème rencontré #3 :
J'avais laissé les joueurs rentrer un indice de case qui n'est pas compris dans [1, 9] ? --> ajout de " || currentBox > 9 || currentBox < 1" dans la boucle while des l.47 et l.60

Problème rencontré #4 :
Mon main.cpp était d'une centaine d'une ligne mais le code marchait très bien. Il y a-t-il moyen d'ajouter des fonctions dans un header pour alléger le main ?

Amélioration de l'IA :
L'idée serait de faire la somme des lignes, des colonnes et des diagonales à chaque tour. Si une des sommes est égale à 2, l'IA choisit alors la case vide dans cette ligne/colonne/diag.