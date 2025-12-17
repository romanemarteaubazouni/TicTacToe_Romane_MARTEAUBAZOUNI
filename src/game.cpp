#include "game.hpp"
#include "board.hpp"
#include "ia.hpp"
#include <iostream>

/*****************Déroulement du jeu*******************/

void initiateMode(int &gameMode) {
    std::cout << "Bienvenue dans le jeu du TicTacToe. Veuillez choisir un mode de jeu :\n";
    std::cout << "1. Deux joueurs\n";
    std::cout << "2. Un joueur contre l'IA\n";
    std::cin >> gameMode;
    while (gameMode != 1 && gameMode !=2) {
        askAgain(gameMode);
    }
}

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
    if ((board[0]!='.' && board[0]==board[4] && board[0]==board[8]) ||
        (board[2]!='.' && board[2]==board[4] && board[2]==board[6]))
    {
        return true;
    }
    return false;
}

/***********************Déroulement de la partie*************************/

void runGame(Player &p1, Player &p2, int gameMode, std::array<char, 9> &board) {
    int currentBox{};
    bool currentPlayerWin{false};
    bool isp1Turn{true};
    
    while (!currentPlayerWin) {
        Player& currentPlayer = isp1Turn ? p1 : p2;
        Player& notCurrentPlayer = isp1Turn ? p2 : p1;

        if (gameMode==1 || (gameMode==2 && isp1Turn)) {
            std::cout << currentPlayer.name << ", saisissez le numéro de la case dans laquelle vous voulez jouer (compris entre 1 et 9):\n";
            std::cin >> currentBox;
            
            while (boxIsFull(board, currentBox-1) || currentBox > 9 || currentBox < 1) {
                askAgain(currentBox);
            }
        }
        else {
            currentBox=boxIA(board, notCurrentPlayer, currentPlayer);
	    }

        board[currentBox-1]=currentPlayer.symbol;
        draw_game_board(board);
        std::cout << '\n';

        if (countLine(board) || countColumn(board) || countDiag(board)) {
            currentPlayerWin=true;
            std::cout << (isp1Turn ? p1.name : p2.name) << " a gagné !\n";
        }
        else if (boardIsFull(board)) {
            currentPlayerWin=true;
            std::cout << "Match nul !\n";
        }
        isp1Turn = !isp1Turn;
    };
}
