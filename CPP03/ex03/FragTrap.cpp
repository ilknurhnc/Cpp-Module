#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    Name = name;         
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << Name << " created!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " has been destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (EnergyPoints <= 0 || HitPoints <= 0)
        return;
    EnergyPoints--;
    std::cout << "FragTrap " << Name << " attacks " << target
              << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " give u a high five!" << std::endl;
}
