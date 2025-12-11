#pragma once
#include <array>
#include "player.hpp"

void initiatePlayers(Player &p1, Player &p2, int gameMode);

void askAgain(int &currentBox);

// Tests pour la victoire

bool boxIsFull(std::array<char, 9> &board, int box);

bool boardIsFull(std::array<char, 9> &board);

bool countLine(std::array<char, 9> &board);

bool countColumn(std::array<char, 9>& board);

bool countDiag(std::array<char, 9>& board);