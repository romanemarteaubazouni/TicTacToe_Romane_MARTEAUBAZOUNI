#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.hpp"
#include "board.hpp"

int main() {
    std::srand(std::time(nullptr));
    int gameMode {};
    std::cout << "Bienvenue dans le jeu du TicTacToe. Veuillez choisir un mode de jeu :\n";
    std::cout << "1. Deux joueurs\n";
    std::cout << "2. Un joueur contre l'IA\n";
    std::cin >> gameMode;
    Player p1{};
    Player p2{};

    if (gameMode == 1) {
        p1 = create_player();
        p2 = create_player();
    }
    else if (gameMode == 2) {
        p1 = create_player();
        p2 = {"IA", 'X', {0, 0, 0, 0, 0, 0, 0, 0, 0}};
        if (p1.symbol=='X') {
            p2.symbol='O';
        }
    }

        int currentBox{};
        bool currentPlayerWin{false};
        bool isp1Turn{true};

        std::cout << "Voici le plateau de départ.\n";
        std::array<char, 9> board {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
        draw_game_board(board);
        
        while (!currentPlayerWin) {
            Player& currentPlayer = isp1Turn ? p1 : p2;
            Player& notCurrentPlayer = isp1Turn ? p2 : p1;
            
            if (gameMode==1) {
                std::cout << currentPlayer.name << ", saisissez le numéro de la case dans laquelle vous voulez jouer (compris entre 1 et 9):\n";
                std::cin >> currentBox;
                
                /*Pour éviter de remplir 2 fois la même case*/
                while (notCurrentPlayer.arrayPlayer[currentBox-1]==1 || currentPlayer.arrayPlayer[currentBox-1] == 1) {
                    std::cout << currentPlayer.name << ", saisissez un autre numéro de case (compris entre 1 et 9):\n";
                    std::cin >> currentBox;
                    std::cin.clear();
                    std::cin.ignore(255, '\n');
                }
            }
            else if (gameMode==2) {
                if (isp1Turn) {
                    std::cout << currentPlayer.name << ", saisissez le numéro de la case dans laquelle vous voulez jouer (compris entre 1 et 9):\n";
                    std::cin >> currentBox;
                /*Pour éviter de remplir 2 fois la même case*/
                    while (notCurrentPlayer.arrayPlayer[currentBox-1]==1 || currentPlayer.arrayPlayer[currentBox-1] == 1) {
                        std::cout << currentPlayer.name << ", saisissez un autre numéro de case (compris entre 1 et 9):\n";
                        std::cin >> currentBox;
                        std::cin.clear();
                        std::cin.ignore(255, '\n');
                };
                }
                else if (!isp1Turn) {
                    currentBox=(std::rand()%9 + 1);
                    while (notCurrentPlayer.arrayPlayer[currentBox-1]==1 || currentPlayer.arrayPlayer[currentBox-1] == 1) {
                        std::srand(std::time(nullptr));
                        currentBox=(std::rand()%9 + 1);
                };
                }
            }

            board[currentBox-1]=currentPlayer.symbol;
            currentPlayer.arrayPlayer[currentBox-1]=1;
            draw_game_board(board);

            /*Conditions pour gagner*/
            if (countLine(currentPlayer.arrayPlayer)) {
                currentPlayerWin=true;
                std::cout << (isp1Turn ? p1.name : p2.name) << " a gagné !\n";
            }
            else if (countColumn(currentPlayer.arrayPlayer)) {
                currentPlayerWin=true;
                std::cout << (isp1Turn ? p1.name : p2.name) << " a gagné !\n";
            }
            else if (countDiag(currentPlayer.arrayPlayer)) {
                currentPlayerWin=true;
                std::cout << (isp1Turn ? p1.name : p2.name) << " a gagné !\n";
            }
            else if (sumArray(currentPlayer.arrayPlayer)+sumArray(notCurrentPlayer.arrayPlayer)==9) {
                std::cout << "Match nul !\n";
                break;
            }
            isp1Turn = !isp1Turn;
        };
    return 0;
}