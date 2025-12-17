#include "ScavTrap.hpp"

int main() {
    std::cout << "--- Creating Robots ---\n" << std::endl;
    ClapTrap c1("Alpha");
    ScavTrap s1("Bravo");

    std::cout << "\n--- Initial Status ---\n" << std::endl;
    std::cout << "Alpha: HP=10, Energy=10, Attack=0" << std::endl;
    std::cout << "Bravo: HP=100, Energy=50, Attack=20" << std::endl;

    std::cout << "\n--- Battle Simulation ---\n" << std::endl;

    // ClapTrap attacks ScavTrap
    c1.attack("Bravo");
    s1.takeDamage(0); // Alpha'nın attack damage = 0

    // ScavTrap attacks ClapTrap
    s1.attack("Alpha");
    c1.takeDamage(20); // Bravo'nun attack damage = 20

    // Multiple attacks
    c1.attack("Bravo");
    s1.takeDamage(0);

    s1.attack("Alpha");
    c1.takeDamage(20);

    std::cout << "\n--- Repairs ---\n" << std::endl;
    c1.beRepaired(5);
    s1.beRepaired(10);

    std::cout << "\n--- Special Mode ---\n" << std::endl;
    s1.guardGate();

    std::cout << "\n--- End of Simulation ---\n" << std::endl;

    return 0;
}


