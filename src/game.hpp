#pragma once
#include <array>
#include "player.hpp"

/*****************Initialisation du jeu*******************/
void initiateMode(int &gameMode);

void initiatePlayers(Player &p1, Player &p2, int gameMode);

void askAgain(int &currentBox);

/*****************Tests de victoire********************/

bool boxIsFull(std::array<char, 9> &board, int box);

bool boardIsFull(std::array<char, 9> &board);

bool countLine(std::array<char, 9> &board);

bool countColumn(std::array<char, 9>& board);

bool countDiag(std::array<char, 9>& board);

/*****************Déourelemnt de la partie******************/
void runGame(Player &p1, Player &p2, int gameMode, std::array<char, 9> &board);
