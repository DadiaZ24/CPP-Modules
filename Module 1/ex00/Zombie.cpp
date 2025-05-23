#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << name << ": Hello there!\n";
}

Zombie::~Zombie()
{
    std::cout << name << ": Goodbye, old friend. May the Force be with you.\n";
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
