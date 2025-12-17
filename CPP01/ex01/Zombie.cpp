#include "Zombie.hpp"

Zombie::Zombie()
{
    // default constructor
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string setName, int index)
{
    name = setName + "_" + std::to_string(index + 1);
}
