#include "Dog.hpp"

Dog::Dog()
{
    this->type = "dog";
    std::cout << "The dog was created." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	*this = copy;
}

Dog &Dog::operator=(const Dog &a)
{
	if (this != &a)
		this->type = a.type;
	return *this;
}

Dog::~Dog()
{
    std::cout << "The dog was destroyed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "woof!" << std::endl;
}

