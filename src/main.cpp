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
    initiateMode(gameMode);
/***********************Initialisation des joueurs**************************/
    Player p1{};
    Player p2{};

    initiatePlayers(p1, p2, gameMode);
/***********************Affichage du tableau de jeu**************************/
    std::cout << "Voici le plateau de départ.\n";
    std::array<char, 9> board {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    draw_game_board(board);
/***********************Déroulement du jeu**************************/
    runGame(p1, p2, gameMode, board);
    
    return 0;
}