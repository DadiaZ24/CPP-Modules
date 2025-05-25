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
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
