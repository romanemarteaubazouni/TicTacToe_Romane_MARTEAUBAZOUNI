# TicTacToe_Romane_MARTEAU--BAZOUNI
Projet de ProgAlgo, IMAC2028 S1

La structure Player a était légèrement modifiée par rapport à la consigne. J'y ai ajouté du tableau d'int arrayPlayer. Lorsque le joueur met son symbole dans une case, alors le arrayPlayer ajoute un 1 dans cette même case. Cela facilite les conditions countLine, countColumn et countDiag qui n'ont plus qu'à faire la somme des lignes/colonnes/diagonales. Ces tableaux auraient pu être directement écrits dans le main, mais pour éviter des lignes de codes en plus, je les ai mis dans la strucutre, malgré la consigne.


Condition du WIN :
Faire 2 tableaux (1 pour chaque joueur) à remplir de 1 et de 0 : faire 3 fonctions (lireLigne, lireColonne, lireDiagonale) qui calcule la somme (si égale à 3 : WIN)
+ plus pratique pour améliorer l'IA (si somme égale à 2, bloquer)

Problème rencontré : au début, le currentPlayer était reconnu par son nom (currentPlayer=p1 puis à chaque fin de tour, currentPlayer changeait). Sauf que, avec la méthode des tableaux de 0 ajoutés dans la structure qui semblait beaucoup plus pratique pour améliorer l'IA (car elle a juste à savoir si la somme des lignes/colonnes et diagonales est égale à 2), arrayPlayer était alors écrasé à chaque fin de tour.
Je l'ai donc remplacé par un booléen isp1True : plus pratique mais suggère que p1 commence toujours... à améliorer ?