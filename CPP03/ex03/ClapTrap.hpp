#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;

public:
    ClapTrap(const std::string& name);
    virtual ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
};

#endif
