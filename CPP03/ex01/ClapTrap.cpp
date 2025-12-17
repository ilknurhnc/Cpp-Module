#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
{
    Name = name;  //this->name = name
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "ClapTrap " << Name << " created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (EnergyPoints <= 0 || HitPoints <= 0)
        return ;
    EnergyPoints--;
    std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints <= 0)
        return;
    HitPoints = HitPoints - amount;
    std::cout << "ClapTrap " << Name << " takes " << amount << " damage!" << " HP:" << HitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints <= 0 || HitPoints <= 0)
        return ;

    EnergyPoints--;
    HitPoints = HitPoints + amount;
    std::cout << "ClapTrap " << Name << " repairs itself " << std::endl;
}
