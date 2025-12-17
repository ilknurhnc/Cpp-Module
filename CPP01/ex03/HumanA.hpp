#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
private:
    std::string name;
    Weapon& weapon; // reference: HumanA her zaman silahlı olacak
public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();

    void attack();
};

#endif