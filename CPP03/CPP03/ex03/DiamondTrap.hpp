#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string Name;

    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();

        void whoAmI();
        using ScavTrap::attack;
};

#endif
