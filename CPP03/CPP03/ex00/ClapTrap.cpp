#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    Name = "Def_clap";
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "ClapTrap " << Name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
    Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "ClapTrap " << Name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "ClapTrap Copy Constructor called" << obj.Name << std::endl;
    *this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap Assignment Operator called to copy " << obj.Name << " into " << this->Name << std::endl;

    if (this != &obj)
    {
        this->Name = obj.Name;
        this->HitPoints = obj.HitPoints;
        this->EnergyPoints = obj.EnergyPoints;
        this->AttackDamage = obj.AttackDamage;
    }
    return *this;
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