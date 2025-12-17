#include "ClapTrap.hpp"

int main() {
    ClapTrap c1("Alpha");
    ClapTrap c2("Beta");

    c1.attack("Beta");
    c2.takeDamage(3);

    c2.beRepaired(2);

    c2.attack("Alpha");
    c1.takeDamage(4);

    c1.beRepaired(5);

    return 0;
}