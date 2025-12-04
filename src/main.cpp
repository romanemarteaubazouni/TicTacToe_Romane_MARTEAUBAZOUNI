#include <iostream>
#include "player.hpp"
#include "board.hpp"

int main() {
    // Player p1 = create_player();

    // std::cout << "Nom : " << p1.name << "\n";
    // std::cout << "Symbole : " << p1.symbol << "\n";
    std::array<char,9> tableau {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    draw_game_board(tableau);

    return 0;
}