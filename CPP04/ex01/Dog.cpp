#include "Dog.hpp"

Dog::Dog()
{
    this->type = "dog";
    this->brain = new Brain();
    std::cout << "The dog was created." << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Copy Constructor called" << std::endl;
    this->brain = new Brain(*obj.brain);
}

Dog &Dog::operator=(const Dog &a)
{
    std::cout << "Assignment Operator called" << std::endl;
    if (this != &a)
    {
        Animal::operator=(a);
        delete this->brain;
        this->brain = new Brain(*a.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "The dog was destroyed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "woof!" << std::endl;
}

