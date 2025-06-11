#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(FragTrap const &other);
    ~FragTrap();
    void highFivesGuys();
};

#endif