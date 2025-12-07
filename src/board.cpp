#include "board.hpp"
#include <iostream>

void draw_game_board(std::array<char,9> &boardSymbol)
{
    for (int i {}; i<7; i+=3)
    {
        std::cout << "| " << boardSymbol[i] << " | " << boardSymbol[i+1] << " | " << boardSymbol[i+2] << " |\n";
    }
}

bool countLine(std::array<int, 9>& arrayPlayer)
{
    for (int i {}; i < 7; i += 3)
    {
        if (arrayPlayer[i]+arrayPlayer[i+1]+arrayPlayer[i+2] == 3)
        {
            return true;
        }
    }
    return false;
}

bool countColumn(std::array<int, 9>& arrayPlayer)
{
    for (int i{}; i < 3; i ++)
    {
        if (arrayPlayer[i]+arrayPlayer[i+3]+arrayPlayer[i+6] == 3)
        {
            return true;
        }
    }
    return false;
}

bool countDiag(std::array<int, 9>& arrayPlayer)
{
    if (arrayPlayer[0]+arrayPlayer[4]+arrayPlayer[8] == 3 ||
        arrayPlayer[2]+arrayPlayer[4]+arrayPlayer[6] == 3)
    {
        return true;
    }
    return false;
}