#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
    int _rawValue;
    static const int _fracBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    Fixed(const int &nbr);
    Fixed(const float &nbr);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat() const;
    int toInt() const;

    // COMPARISON OPERATORS
    bool operator>(Fixed const &fixed) const;
    bool operator<(Fixed const &fixed) const;
    bool operator>=(Fixed const &fixed) const;
    bool operator<=(Fixed const &fixed) const;
    bool operator==(Fixed const &fixed) const;
    bool operator!=(Fixed const &fixed) const;
    // ARITHMETIC OPERATIONS
    Fixed operator+(Fixed const &fixed);
    Fixed operator-(Fixed const &fixed);
    Fixed operator*(Fixed const &fixed);
    Fixed operator/(Fixed const &fixed);
    // INCREMENT/DECREMENT OPERATORS
    Fixed &operator++();   //++i
    Fixed operator++(int); // i++
    Fixed &operator--();   //--i
    Fixed operator--(int); // i--
    // OVERLOADED FUNCTIONS
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
