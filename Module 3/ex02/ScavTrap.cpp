#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\e[0;32mConstructor called\n\e[0m";
    std::cout << "ScavTrap " << _name << " is alive!\n";
    _hitPoints = 100;
    _energy = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "\e[0;32mCopy Constructor called\n\e[0m";
    std::cout << "ScavTrap " << _name << " is alive!\n";
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energy = other._energy;
        _attackDamage = other._attackDamage;
    }
    std::cout << "\e[0;32mAssignment operator called\n\e[0m";
    std::cout << "ScavTrap " << _name << " is alive!\n";
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\e[0;32mScavTrap destructor called\n\e[0m";
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0 || _energy <= 0)
    {
        std::cout << "ScavTrap " << _name << " can not attack! It is dead or does not have energy!\n";
        return;
    }
    _energy--;
    std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " of damage!\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered Gate keeper mode\n";
}
