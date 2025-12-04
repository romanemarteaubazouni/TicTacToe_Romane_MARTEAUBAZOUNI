#include <iostream>
#include "player.hpp"

int main() {
    Player p1 = create_player();

    std::cout << "Nom : " << p1.name << "\n";
    std::cout << "Symbole : " << p1.symbol << "\n";

    return 0;
}