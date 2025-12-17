#include "Zombie.hpp"

Zombie* zombieHorde(int z, std::string name)
{
    Zombie* horde = new Zombie[z];
    for (int i = 0; i < z; i++)
    {
        horde[i].setName(name, i);
    }
    return horde;
}
