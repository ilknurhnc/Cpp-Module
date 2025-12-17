#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string Name;

public:
    DiamondTrap(const std::string& name);
    ~DiamondTrap();

    void whoAmI();
    using ScavTrap::attack;
};

#endif
