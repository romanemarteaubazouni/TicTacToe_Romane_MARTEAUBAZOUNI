#pragma once
#include <iostream>
#include <array>
#include "player.hpp"

/***********************Amélioration de l'IA : bloquer les coups gagnants de l'humain + gagner si elle en a la possibilité*************************/
void chooseWinningBox(std::array<char, 9> board, Player &p, int &boxToPlay);

int boxIA(std::array<char, 9> board, Player &p, Player &ia);