#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream> 

//Bir sınıfı soyut hale getirmek için,
//o sınıftaki en az bir fonksiyonu "saf sanal" (pure virtual) olarak işaretlemen gerekir.

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &copy);
		Animal &operator=(const Animal &a);
        virtual ~Animal();
        virtual void makeSound() const = 0;
        std::string getType() const;
};  

#endif