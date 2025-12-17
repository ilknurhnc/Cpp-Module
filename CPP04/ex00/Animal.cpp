#include "Animal.hpp"

Animal::Animal()
{
    this->type = "undefined";
    std::cout << "The animal was created." << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
}

Animal &Animal::operator=(const Animal &a)
{
	if (this != &a)
		this->type = a.type;
	return *this;
}

Animal::~Animal()
{
    std::cout << "The animal was destroyed." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "No animal was identified." << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
