#include "board.hpp"
#include <iostream>

void draw_game_board(std::array<char,9> &boardSymbol) {
    for (int i {}; i<7; i+=3)
    {
        std::cout << "| " << boardSymbol[i] << " | " << boardSymbol[i+1] << " | " << boardSymbol[i+2] << " |\n";
    }
}