#pragma once
#include <string>
#include <array>

struct Player {
    std::string name {""};
    char symbol {};
    std::array<int, 9> arrayPlayer {0, 0, 0, 0, 0, 0, 0, 0, 0};
};

Player create_player();