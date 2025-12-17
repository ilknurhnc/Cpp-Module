#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    Name = "Def_Frag";
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << Name << " (Default) created!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << Name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    std::cout << "FragTrap Copy Constructor called" << obj.Name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    std::cout << "FragTrap Assignment Operator called" << obj.Name << " into " << this->Name << std::endl;
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " has been destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (EnergyPoints <= 0 || HitPoints <= 0)
        return ;
    EnergyPoints--;
    std::cout << "FragTrap " << Name << " attacks " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << Name << " give u a high five!" << std::endl;
}
