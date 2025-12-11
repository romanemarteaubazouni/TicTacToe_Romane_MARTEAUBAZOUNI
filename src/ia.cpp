#include "ia.hpp"
#include "player.hpp"
#include <iostream>
#include <array>

int canBlock(std::array<char, 9> board, Player &ia) {
    int boxToPlay {0};
    for (int i {}; i<9; i++) {
        if (board[i]!='.') {
            continue;
        }
        else {
            board[i]=ia.symbol;
            if (countLine(board) || countColumn(board) || countDiag(board)) {
                boxToPlay=i;
            }
            else {
                continue;
            }
        }
    }
    if (boxtoPlay==0) {
        currentBox=(std::rand()%9 + 1);
        while (boxIsFull(board, currentBox-1)) {
            std::srand(std::time(nullptr));
            currentBox=(std::rand()%9 + 1);
        }
    }
}