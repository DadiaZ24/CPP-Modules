#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\e[0;32mConstructor called\n\e[0m";
    std::cout << "FragTrap " << _name << " is alive!\n";
    _hitPoints = 100;
    _energy = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "\e[0;32mCopy Constructor called\n\e[0m";
    std::cout << "FragTrap " << _name << " is alive!\n";
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energy = other._energy;
        _attackDamage = other._attackDamage;
    }
    std::cout << "\e[0;32mAssignment operator called\n\e[0m";
    std::cout << "FragTrap " << _name << " is alive!\n";
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "\e[0;32mFragTrap destructor called\n\e[0m";
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " high fived the guys!" << std::endl;
}