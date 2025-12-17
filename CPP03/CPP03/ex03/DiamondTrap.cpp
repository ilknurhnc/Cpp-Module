#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Def_clap_name"), FragTrap(), ScavTrap()
{
    Name = "Def_Diamond";
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap " << Name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    Name = name;
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap " << Name << " created!" << std::endl;
}

// --- OCF 2: Kopya Yapıcı ---
// Kopyalama yaparken de tüm üst sınıfları kopyalamalıyız.
DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "DiamondTrap Copy Constructor called for " << other.Name << std::endl;
    // Kendi özel üyesini manuel kopyala
    this->Name = other.Name;
    // Statüler zaten üst sınıfların kopyalayıcıları tarafından ayarlandı.
}

// --- OCF 3: Atama Operatörü ---
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap Assignment Operator called for " << other.Name << std::endl;
    if (this != &other)
    {
        // Tüm üst sınıfların atama operatörlerini çağır
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        // Kendi özel üyesini manuel ata
        this->Name = other.Name;
        
        // Statüleri de yeniden ata (çünkü üst sınıflar bunları ayarlamış olabilir)
        this->HitPoints = FragTrap::HitPoints;
        this->EnergyPoints = ScavTrap::EnergyPoints;
        this->AttackDamage = FragTrap::AttackDamage;
    }
    return *this;
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
