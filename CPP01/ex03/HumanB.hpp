#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
private:
    std::string name;
    Weapon* weapon; // pointer: başta silahsız olabilir
public:
    HumanB(const std::string& name);
    ~HumanB();

    void setWeapon(Weapon& w);
    void attack();
};

#endif