#include "ia.hpp"
#include "game.hpp"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

/***********************Calcul de la case optimale à jouer**************************/

int boxIA(std::array<char, 9> board, Player &p, Player &ia) {
    int boxToPlay {-1};
    for (int i {}; i<9; i++) {
        if (boxIsFull(board, i)) {
            continue;/*On ne joue pas sur une case déjà prise*/
        }
        else {
            board[i]=ia.symbol;
            if (countLine(board) || countColumn(board) || countDiag(board)) {
                boxToPlay=i; /*si l'IA gagne, elle choisit cette case*/
                break;
            }
            board[i]='.';
        }
    }

    if (boxToPlay==-1) { /*s'il n'y a aucun coup gagnant pour l'IA, elle regarde pour l'humain*/
        for (int i {}; i<9; i++) {
            if (boxIsFull(board, i)) {
                continue;/*On ne joue pas sur une case déjà prise*/
            }
            else {
                board[i]=p.symbol;
                if (countLine(board) || countColumn(board) || countDiag(board)) {
                    boxToPlay=i; /*si l'IA gagne, elle choisit cette case*/
                    break;
                }
                board[i]='.';
            }
        }
        if (boxToPlay==-1) {
        boxToPlay=(std::rand()%9);
        while (boxIsFull(board, boxToPlay)) {
            std::srand(std::time(nullptr));
            boxToPlay=(std::rand()%9);
        }
        }
    }
    return boxToPlay+1;
}