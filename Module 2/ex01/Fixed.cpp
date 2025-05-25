#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_rawValue = other.getRawBits();
    return *this;
}

Fixed::Fixed(const int &nbr)
{
    std::cout << "Int constructor called\n";
    _rawValue = nbr << _fracBits;
}

Fixed::Fixed(const float &nbr)
{
    std::cout << "Float constructor called\n";
    _rawValue = roundf(nbr * (1 << _fracBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    return this->_rawValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_rawValue = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_rawValue) / (1 << _fracBits);
}

int Fixed::toInt() const
{
    return _rawValue >> _fracBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
