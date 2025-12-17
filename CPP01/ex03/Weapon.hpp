#ifndef WEAPON_H
#define WEAPON_H

#include <string>


class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string &t);
    ~Weapon();

    const std::string &getType();
    void setType(const std::string &newType);
};

#endif