#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string n) : name(n) {}
    ~Zombie();

    void announce(void);
    std::string getName() { return name; }
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif 