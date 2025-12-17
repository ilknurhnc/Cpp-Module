#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "cat";
    std::cout << "The cat was created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &a)
{
	if (this != &a)
		this->type = a.type;
	return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "The cat was destroyed." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "meow!" << std::endl;
}
