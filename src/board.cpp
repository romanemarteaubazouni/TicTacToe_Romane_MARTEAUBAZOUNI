#include "board.hpp"
#include <iostream>

void draw_game_board(std::array<char,9> &boardSymbol)
{
    for (int i {}; i<7; i+=3)
    {
        std::cout << "| " << boardSymbol[i] << " | " << boardSymbol[i+1] << " | " << boardSymbol[i+2] << " |\n";
    }
}
bool countLine(const std::array<int, 9>& arrayPlayer)
{
    for (int i = 0; i < 7; i += 3)
    {
        if (arrayPlayer[i] == 1 &&
            arrayPlayer[i+1] == 1 &&
            arrayPlayer[i+2] == 1)
        {
            return true;
        }
    }
    return false;
}