#include "HumanA.hpp"

HumanA::HumanA(const std::string& n, Weapon& w)
    : name(n), weapon(w) // <- initializer list kullanıyoruz
{
    // Gövde boş çünkü tüm üyeler initializer list ile başlatıldı
}

HumanA::~HumanA() {}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}