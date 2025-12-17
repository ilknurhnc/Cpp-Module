#include "Weapon.hpp"

Weapon::Weapon(const std::string& t) : type(t) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType(){
    return type;
}

void Weapon::setType(const std::string &a) {
    type = a;
}