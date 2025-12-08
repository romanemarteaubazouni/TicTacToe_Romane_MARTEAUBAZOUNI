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

int sumArray(std::array<int, 9> &arrayPlayer)
{
    int sum{};
    for (int i{}; i<9; i++)
    {
        sum+=arrayPlayer[i];
    }
    return sum;
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