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
        bool currentPlayerWin{false};
        bool isp1Turn{true};

        std::cout << "Voici le plateau de départ.\n";
        std::array<char, 9> board {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
        draw_game_board(board);
        
        while (!currentPlayerWin)
        {
            Player& currentPlayer = isp1Turn ? p1 : p2;
            Player& notCurrentPlayer = isp1Turn ? p2 : p1;
            
            std::cout << currentPlayer.name << ", saisissez le numéro de la case dans laquelle vous voulez jouer (compris entre 1 et 9):\n";
            std::cin >> currentBox;
            
            while (notCurrentPlayer.arrayPlayer[currentBox-1]==1 || currentPlayer.arrayPlayer[currentBox-1] == 1)
            {
                std::cout << currentPlayer.name << ", saisissez un autre numéro de case (compris entre 1 et 9):\n";
                std::cin >> currentBox;
                std::cin.clear();
                std::cin.ignore(255, '\n');
            }

            board[currentBox-1]=currentPlayer.symbol;
            currentPlayer.arrayPlayer[currentBox-1]=1;
            draw_game_board(board);

            if (countLine(currentPlayer.arrayPlayer))
            {
                currentPlayerWin=true;
                break;
            }
            else if (countColumn(currentPlayer.arrayPlayer))
            {
                currentPlayerWin=true;
                break;
            }
            else if (countDiag(currentPlayer.arrayPlayer))
            {
                currentPlayerWin=true;
                break;
            }
// pb si deux X ou deux O
            // idée pour si personne ne gagne : if somme de ts les élements des 2 currentPlayer.arrayPlayer ==9, break; et return "personne ne gagne"
            isp1Turn = !isp1Turn;
        };
        std::cout << (isp1Turn ? p1.name : p2.name) << " a gagné !\n";
    }

    return 0;
}