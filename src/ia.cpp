#include "ia.hpp"
#include "game.hpp"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

/***********************Calcul de la case optimale à jouer**************************/
void chooseWinningBox(std::array<char, 9> board, Player &p, int &boxToPlay) {
    for (int i {}; i<9; i++) {
        if (boxIsFull(board, i)) {
            continue;/*On ne joue pas sur une case déjà prise*/
        }
        else {
            board[i]=p.symbol;
            if (countLine(board) || countColumn(board) || countDiag(board)) {
                boxToPlay=i; /*si le joueur gagne, l'IA jouera cette case*/
                break;
            }
            board[i]='.';
        }
    }
}

int boxIA(std::array<char, 9> board, Player &p, Player &ia) {
    int boxToPlay {-1};
    chooseWinningBox(board, ia, boxToPlay);

    if (boxToPlay==-1) { /*s'il n'y a aucun coup gagnant pour l'IA, elle regarde pour l'humain*/
        chooseWinningBox(board, p, boxToPlay);
        if (boxToPlay==-1) { /*s'il n'y a aucun coup gagnant, elle joue aléatoirement*/
        boxToPlay=(std::rand()%9);
        while (boxIsFull(board, boxToPlay)) {
            boxToPlay=(std::rand()%9);
        }
        }
    }
    return boxToPlay+1;
}