
#include "Fixed.hpp"

Fixed::Fixed()
{
    this->number = 0;
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &obj)
{
    this->number = obj.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &copy)
{
    if (this != &copy)// self-assignment kontrolü
        this->number = copy.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;

    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}