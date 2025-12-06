#include <iostream>
#include "player.hpp"
#include "board.hpp"

int main() {
    
    int gameMode {};
    std::cout << "Bienvenue dans le jeu du TicTacToe. Veuillez choisir un mode de jeu :\n";
    std::cout << "1. Deux joueurs\n";
    std::cout << "2. Un joueur contre l'IA\n";
    std::cin >> gameMode;

    if (gameMode == 1)
    {
        Player p1 = create_player();
        Player p2 = create_player();
        int currentBox{};
        Player currentPlayer{p1};
        bool currentPlayerWin{false};

        std::cout << "Voici le plateau de départ.\n";
        std::array<char, 9> board {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
        draw_game_board(board);
        
        while (!currentPlayerWin)
        {
            std::cout << currentPlayer.name << ", saisissez le numéro de la case dans laquelle vous voulez jouer (compris entre 1 et 9):\n";
            std::cin >> currentBox;
            board[currentBox-1]=currentPlayer.symbol;
            draw_game_board(board);

            if (currentPlayer.name==p1.name)
            {
                currentPlayer=p2;
            }
            else
            {
                currentPlayer=p1;
            }
        }; //problèmes restants : condition du WIN ; si personne ne gagne, ne pas pouvoir remplir sur une case déjà remplie ?
    }

    return 0;
}