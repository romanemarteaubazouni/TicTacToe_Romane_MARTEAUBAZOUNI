#include "player.hpp"
#include <iostream>

Player create_player() {
    Player p{};

    std::cout << "Entrez le nom du joueur : \n";
    std::cin >> p.name;
    
    while (p.symbol != 'X' && p.symbol != 'O') //on devrait avoir || ?
    {
        std::cout << "Entrez le caractere avec lequel vous souhaitez jouer (soit X, soit O) : \n";
        std::cin >> p.symbol;
        std::cin.clear();
        std::cin.ignore(255, '\n');
    };
    return p;
}