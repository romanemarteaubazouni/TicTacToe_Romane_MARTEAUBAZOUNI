#include "game.hpp"
#include <iostream>

void initiatePlayers(Player &p1, Player &p2, int gameMode) {
    if (gameMode == 1) {
        p1 = create_player();
        p2 = create_player();
    }
    else if (gameMode == 2) {
        p1 = create_player();
        p2 = {"IA", 'X'};
        if (p1.symbol=='X') {
            p2.symbol='O';
        }
    }
}

void askAgain(int &currentBox) {
    std::cout << "Saisissez un autre numéro :\n";
    std::cin >> currentBox;
    std::cin.clear();
    std::cin.ignore(255, '\n');
}

/***********************Vérification de la victoire*************************/

bool boxIsFull(std::array<char, 9> &board, int box) {
    if (board[box]!='.') {
        return true;
    }
    return false;
}

bool boardIsFull(std::array<char, 9> &board) {
    int boxFull {};
    for (int i{}; i<9; i++) {
        if (board[i]!='.') {
            boxFull+=1;
        }
    }

    if (boxFull==9) {
        return true;
    }
    return false;
}

bool countLine(std::array<char, 9>& board) {
    for (int i {}; i < 7; i += 3)
    {
        if (board[i]!='.' && board[i]==board[i+1] && board[i]==board[i+2])
        {
            return true;
        }
    }
    return false;
}

bool countColumn(std::array<char, 9>& board) {
    for (int i{}; i < 3; i ++)
    {
        if (board[i]!='.' && board[i]==board[i+3] && board[i]==board[i+6])
        {
            return true;
        }
    }
    return false;
}

bool countDiag(std::array<char, 9>& board) {
    if (board[0]!='.' && board[0]==board[4] && board[0]==board[8] ||
        board[2]!='.' && board[2]==board[4] && board[2]==board[6])
    {
        return true;
    }
    return false;
}