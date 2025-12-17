#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
    this->number = 0;
}

// Int constructor
Fixed::Fixed(const int n)
{
    this->number = n << fractBit; // int → fixed-point
}

// Float constructor
Fixed::Fixed(const float f)
{
    this->number = roundf(f * (1 << fractBit)); // float → fixed-point
}

// Copy constructor
Fixed::Fixed(const Fixed &obj)
{
    this->number = obj.getRawBits();
}

// Copy assignment operator
Fixed& Fixed::operator = (const Fixed &copy)
{
    if (this != &copy)// self-assignment kontrolü
        this->number = copy.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed(){}

int Fixed::getRawBits( void ) const
{
	return this->number;
}

void Fixed::setRawBits( int const raw )
{
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


bool Fixed::operator>(const Fixed &obj) const {
    return this->number > obj.number;
}

bool Fixed::operator<(const Fixed &obj) const {
    return this->number < obj.number;
}

bool Fixed::operator>=(const Fixed &obj) const {
    return this->number >= obj.number;
}

bool Fixed::operator<=(const Fixed &obj) const {
    return this->number <= obj.number;
}

bool Fixed::operator==(const Fixed &obj) const {
    return this->number == obj.number;
}

bool Fixed::operator!=(const Fixed &obj) const {
    return this->number != obj.number;
}



Fixed Fixed::operator+(const Fixed &obj) const {
    return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const {
    return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const {
    return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const {
    if (obj.getRawBits() == 0) {
        std::cout << "Cannot be divided by zero!" << std::endl;
        exit(1);
    }
    return Fixed(this->toFloat() / obj.toFloat());
}


// Pre-increment
Fixed& Fixed::operator++() {
    number += 1;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    number += 1;
    return temp;
}

// Pre-decrement
Fixed& Fixed::operator--() {
    number -= 1;
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    number -= 1;
    return temp;
}



Fixed& Fixed::min(Fixed &a, Fixed &b) {
    // Eğer a, b'den küçükse a'yı döndür
    if (a < b) {
        return a;
    }
    // Aksi halde b'yi döndür
    else {
        return b;
    }
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b) {
        return a;  // sadece okunabilir, değiştirilemez
    } else {
        return b;
    }
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b) {
        return a;  // sadece okunabilir
    } else {
        return b;
    }
}


// Operator<< overload
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}