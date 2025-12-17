#include "Cat.hpp"

Cat::Cat()
{
    this->type = "cat";
    std::cout << "The cat was created." << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	*this = copy;
}

Cat &Cat::operator=(const Cat &a)
{
	if (this != &a)
		this->type = a.type;
	return *this;
}

Cat::~Cat()
{
    std::cout << "The cat was destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow!" << std::endl;
}

