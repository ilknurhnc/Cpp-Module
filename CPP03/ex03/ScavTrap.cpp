#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    Name = name;    
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << Name << " created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (EnergyPoints <= 0 || HitPoints <= 0)
        return;
    EnergyPoints--;
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode!" << std::endl;
}