#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- Creating Robots ---\n\n";

    ClapTrap c1("Alpha");
    ScavTrap s1("Bravo");
    FragTrap f1("Charlie");
    DiamondTrap d1("Delta");

    std::cout << "\n--- Initial Status ---\n\n";
    std::cout << "ClapTrap " << c1.getName() << ": HP=" << 10 
              << ", Energy=" << 10 << ", Attack=" << 0 << "\n";

    std::cout << "ScavTrap " << s1.getName() << ": HP=" << 100 
              << ", Energy=" << 50 << ", Attack=" << 20 << "\n";

    std::cout << "FragTrap " << f1.getName() << ": HP=" << 100 
              << ", Energy=" << 100 << ", Attack=" << 30 << "\n";

    std::cout << "DiamondTrap " << d1.getName() << ": HP=" << 100 
              << ", Energy=" << 50 << ", Attack=" << 30 << "\n";

    std::cout << "\n--- Battle Simulation ---\n\n";

    c1.attack("Charlie");
    f1.takeDamage(0);

    s1.attack("Alpha");
    c1.takeDamage(20);

    f1.attack("Bravo");
    s1.takeDamage(30);

    d1.attack("Alpha");
    c1.takeDamage(30);

    std::cout << "\n--- Special Abilities ---\n\n";
    s1.guardGate();
    f1.highFivesGuys();
    d1.whoAmI();

    std::cout << "\n--- End of Simulation ---\n";

    return 0;
}
