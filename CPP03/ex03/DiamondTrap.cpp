#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), Name(name)
{
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap " << Name << " created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << Name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << Name
              << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}
