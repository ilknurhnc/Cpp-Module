#include "DiamondTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Testing Exercise 00: ClapTrap ---" << std::endl;
    ClapTrap ct("Clappy");
    
    ct.attack("a wooden barrel");
    ct.takeDamage(5);
    ct.beRepaired(3);
    ct.takeDamage(8); 
    ct.attack("another barrel");
    std::cout << std::endl;

    std::cout << "--- Testing Exercise 01: ScavTrap ---" << std::endl;
    ScavTrap st("Scavy");

    st.attack("a stone wall"); 
    st.takeDamage(20);
    st.beRepaired(10);
    st.guardGate();
    std::cout << std::endl;

    std::cout << "--- Testing Exercise 02: FragTrap ---" << std::endl;
    FragTrap ft("Fraggy");

    ft.attack("a metal container");
    ft.takeDamage(30);
    ft.beRepaired(15);
    ft.highFivesGuys();
    std::cout << std::endl;

    std::cout << "--- Testing Exercise 03: DiamondTrap ---" << std::endl;
    DiamondTrap dt("Diablo"); 
    std::cout << std::endl;

    dt.whoAmI(); 
    std::cout << std::endl;

    dt.attack("the final boss");
    std::cout << std::endl;

    dt.guardGate();
    dt.highFivesGuys();
    std::cout << std::endl;
    
    dt.takeDamage(40);
    dt.beRepaired(20);
    std::cout << std::endl;
    std::cout << "--- End of main (Destruction) ---" << std::endl;
    return 0;
}
