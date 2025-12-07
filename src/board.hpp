#pragma once
#include <array>

void draw_game_board(std::array<char,9> &boardSymbol);

bool countLine(std::array<int, 9> &arrayPlayer);

bool countColumn(std::array<int, 9>& arrayPlayer);

bool countDiag(std::array<int, 9>& arrayPlayer);