#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energy(10), _attackDamage(0)
{
    std::cout << "\e[0;32mConstructor called\n\e[0m";
    std::cout << "ClapTrap " << _name << " is alive!\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "\e[0;32mCopy Constructor called\n\e[0m";
    std::cout << "ClapTrap " << _name << " is alive!\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energy = other._energy;
        _attackDamage = other._attackDamage;
    }
    std::cout << "\e[0;32mAssignment operator called\n\e[0m";
    std::cout << "ClapTrap " << _name << " is alive!\n";
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "\e[0;32mClapTrap destructor called\n\e[0m";
}

void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0 || _energy <= 0)
    {
        std::cout << "ClapTrap " << _name << " can not attack! It is dead or does not have energy!\n";
        return;
    }
    _energy--;
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " of damage! HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energy <= 0)
    {
        std::cout << "ClapTrap " << _name << " can not be repaired! It is dead or does not have energy!\n";
        return;
    }
    _energy--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs " << amount << " points of HP! New HP: " << _hitPoints << std::endl;
}
