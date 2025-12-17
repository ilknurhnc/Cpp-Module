#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* a = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "--- ANIMAL ARRAY LEAK TEST ---" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];

    std::cout << "--- Creating Animal Array ---" << std::endl;
    for (int k = 0; k < arraySize / 2; ++k)
        animals[k] = new Dog();
    
    for (int k = arraySize / 2; k < arraySize; ++k)
        animals[k] = new Cat();
    
    std::cout << "--- Deleting Animal Array ---" << std::endl;
    for (int k = 0; k < arraySize; ++k)
        delete animals[k];

    Dog originalDog;
    {
        std::cout << "--- Creating Copied Dog (Copy Constructor) ---" << std::endl;
        Dog copiedDog = originalDog; 
    }

    return 0;
}