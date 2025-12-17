#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "--- Creating Robots ---\n" << std::endl;

    ClapTrap c1("Alpha");
    ScavTrap s1("Bravo");
    FragTrap f1("Charlie");

    std::cout << "\n--- Battle Simulation ---\n" << std::endl;

    c1.attack("Charlie");
    f1.takeDamage(0);

    s1.attack("Alpha");
    c1.takeDamage(20);

    f1.attack("Bravo");
    s1.takeDamage(30);

    std::cout << "\n--- Repairs ---\n" << std::endl;
    c1.beRepaired(5);
    s1.beRepaired(10);
    f1.beRepaired(15);

    std::cout << "\n--- Special Abilities ---\n" << std::endl;
    s1.guardGate(); 
    f1.highFivesGuys();

    std::cout << "\n--- End of Simulation ---\n" << std::endl;

    return 0;
}