#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.hpp"
#include "board.hpp"
#include "game.hpp"
#include "ia.hpp"

int main() {
    std::srand(std::time(nullptr));
    int gameMode {};
    std::cout << "Bienvenue dans le jeu du TicTacToe. Veuillez choisir un mode de jeu :\n";
    std::cout << "1. Deux joueurs\n";
    std::cout << "2. Un joueur contre l'IA\n";
    std::cin >> gameMode;
    while (gameMode != 1 && gameMode !=2) {
        askAgain(gameMode);
    }
/***********************Initialisation des joueurs**************************/
    Player p1{};
    Player p2{};

    initiatePlayers(p1, p2, gameMode);

    int currentBox{};
    bool currentPlayerWin{false};
    bool isp1Turn{true};

    std::cout << "Voici le plateau de départ.\n";
    std::array<char, 9> board {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    draw_game_board(board);
    
    while (!currentPlayerWin) {
        Player& currentPlayer = isp1Turn ? p1 : p2;
        Player& notCurrentPlayer = isp1Turn ? p2 : p1;
/***********************Déroulement du jeu**************************/
        if (gameMode==1) {
            std::cout << currentPlayer.name << ", saisissez le numéro de la case dans laquelle vous voulez jouer (compris entre 1 et 9):\n";
            std::cin >> currentBox;
            
            while (boxIsFull(board, currentBox-1) || currentBox > 9 || currentBox < 1) {
                askAgain(currentBox);
            }
        }
        else if (gameMode==2) {
            if (isp1Turn) {
                std::cout << currentPlayer.name << ", saisissez le numéro de la case dans laquelle vous voulez jouer (compris entre 1 et 9):\n";
                std::cin >> currentBox;
                while (boxIsFull(board, currentBox-1) || currentBox > 9 || currentBox < 1) {
                    askAgain(currentBox);
            };
            }
            else if (!isp1Turn) {
                currentBox=boxIA(board, notCurrentPlayer);
            };
            }
        
        board[currentBox-1]=currentPlayer.symbol;
        draw_game_board(board);
        std::cout << '\n';
/***********************Tests de victoire**************************/
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
    return 0;
}