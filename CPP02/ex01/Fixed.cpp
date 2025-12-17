#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
    this->number = 0;
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int n)
{
    this->number = n << fractBit; // int → fixed-point
    std::cout << "Int constructor called" << std::endl;
}

// Float constructor
Fixed::Fixed(const float f)
{
    this->number = roundf(f * (1 << fractBit)); // float → fixed-point
    std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &obj)
{
    this->number = obj.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator = (const Fixed &copy)
{
    if (this != &copy)// self-assignment kontrolü
        this->number = copy.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;

    return *this;
}

// Destructor
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

// Convert fixed → float
float Fixed::toFloat(void) const
{
    return (float)this->number / (1 << fractBit);
}

// Convert fixed → int
int Fixed::toInt(void) const
{
    return this->number >> fractBit;
}

// Operator<< overload
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
