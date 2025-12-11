#pragma once
#include <array>


// Tests pour la victoire

bool boxIsFull(std::array<char, 9> &board, int box);

bool boardIsFull(std::array<char, 9> &board);

bool countLine(std::array<char, 9> &board);

bool countColumn(std::array<char, 9>& board);

bool countDiag(std::array<char, 9>& board);