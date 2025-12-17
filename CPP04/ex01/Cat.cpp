#include "Cat.hpp"

Cat::Cat()
{
    this->type = "cat";
    this->brain = new Brain();
    std::cout << "The cat was created." << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << "Copy Constructor called" << std::endl;
    this->brain = new Brain(*obj.brain);    
}

Cat &Cat::operator=(const Cat &a)
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

Cat::~Cat()
{
    delete this->brain;
    std::cout << "The cat was destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow!" << std::endl;
}

