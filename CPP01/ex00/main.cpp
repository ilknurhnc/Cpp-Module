#include "Zombie.hpp"

int main() {

    Zombie* zom1 = newZombie("zom1");
    zom1->announce();
    delete zom1;

    randomChump("zom2");
    return 0;
}