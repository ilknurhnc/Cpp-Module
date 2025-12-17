#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "undefined";
    std::cout << "The animal was created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
	if (this != &a)
		this->type = a.type;
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The animal was destroyed." << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "No animal was identified." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}