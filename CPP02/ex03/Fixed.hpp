#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int number;
    static const int fractBit = 8;
public:
    Fixed();                             // Default constructor
    Fixed(const int n);                  // Int constructor
    Fixed(const float f);                // Float constructor
    Fixed(const Fixed &obj);             // Copy constructor
    Fixed& operator=(const Fixed &copy); // Copy assignment operator
    ~Fixed();                            // Destructor

    bool operator>(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;
    bool operator==(const Fixed &obj) const;
    bool operator!=(const Fixed &obj) const;


    Fixed operator+(const Fixed &obj) const;
    Fixed operator-(const Fixed &obj) const;
    Fixed operator*(const Fixed &obj) const;
    Fixed operator/(const Fixed &obj) const;


    Fixed& operator++();    // pre-increment
    Fixed operator++(int);  // post-increment
    Fixed& operator--();    // pre-decrement
    Fixed operator--(int);  // post-decrement


    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);


    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};


std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif