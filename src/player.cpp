#include "player.hpp"
#include <iostream>

Player create_player() {
    Player p;
    std::cout << "Entrez le nom du joueur : \n";
    std::cin >> p.name;

    std::cout << "Entrez le caractere avec lequel vous souhaitez jouer : \n";
    std::cin >> p.symbol;

    return p;
}