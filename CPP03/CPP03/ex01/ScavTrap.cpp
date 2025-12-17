#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    Name = "Def_Scav";
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << this->Name << " (Default) created!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << Name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap Copy Constructor called to create a copy of " << obj.Name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout << "ScavTrap Assignment Operator called to copy " << obj.Name << " into " << this->Name << std::endl;

    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (EnergyPoints <= 0 || HitPoints <= 0)
        return;
    EnergyPoints--;
    std::cout << "ScavTrap " << Name << " attacks " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode!" << std::endl;
}