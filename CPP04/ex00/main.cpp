#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;

		std::cout << "Type of Dog -> " << j->getType() << " " << std::endl;
		std::cout << "Type of Cat -> " << i->getType() << " " << std::endl;

		std::cout << std::endl;

		std::cout << "Cat says : ";
		i->makeSound();
		std::cout << "Dog says : ";
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl;

		delete meta;
		delete i;
		delete j;
	}
	std::cout << "------------------------------------" << std::endl;
	{
		const WrongAnimal *meta = new WrongAnimal;
		const WrongAnimal *cat = new WrongCat;

		std::cout << std::endl;

		std::cout << "Wrong Animal Type -> " << meta->getType() << std::endl;
		std::cout << "Wrong Cat Type-> " << cat->getType() << std::endl;

		std::cout << std::endl;

		std::cout << "Meta says : ";
		meta->makeSound();
		std::cout << "Wrong Cat says : ";
		cat->makeSound();

		std::cout << std::endl;

		delete meta;
		delete cat;
	}
}