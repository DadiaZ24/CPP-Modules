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

// COMPARISON OPERATORS

bool Fixed::operator>(Fixed const &fixed) const
{
    return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(Fixed const &fixed) const
{
    return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(Fixed const &fixed) const
{
    return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(Fixed const &fixed) const
{
    return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(Fixed const &fixed) const
{
    return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(Fixed const &fixed) const
{
    return this->toFloat() != fixed.toFloat();
}

// ARITHMETIC OPERATIONS
// Note: Operators + and - works well with scale 256. But if I multiply a scale 256 with other scale 256, the scale will be 256 * 256.
// that's why I need to bitshiffting. Same thing with division.

Fixed Fixed::operator+(Fixed const &fixed)
{
    Fixed res;

    res.setRawBits(this->getRawBits() + fixed.getRawBits());
    return res;
}

Fixed Fixed::operator-(Fixed const &fixed)
{
    Fixed res;

    res.setRawBits(this->getRawBits() - fixed.getRawBits());
    return res;
}

Fixed Fixed::operator*(Fixed const &fixed)
{
    Fixed res;

    res.setRawBits((this->getRawBits() * fixed.getRawBits()) >> this->_fracBits);
    return res;
}

Fixed Fixed::operator/(Fixed const &fixed)
{
    Fixed res;

    res.setRawBits((this->getRawBits() << _fracBits) / fixed.getRawBits());
    return res;
}

Fixed &Fixed::operator++()
{
    this->_rawValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed &Fixed::operator--()
{
    this->_rawValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    operator--();
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a > b) ? b : a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a > b) ? b : a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
