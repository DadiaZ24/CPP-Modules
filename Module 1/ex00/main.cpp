#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie *obiWan = newZombie("Obi-Wan Kenobi");
    obiWan->announce();
    delete obiWan;

    std::cout << "---------------------\n";
    randomChump("Darth Vader");
    std::cout << "---------------------\n";
    randomChump("Yoda");
    std::cout << "---------------------\n";
    randomChump("Luke Skywalker");
    std::cout << "---------------------\n";
    randomChump("Leia Organa");
    std::cout << "---------------------\n";
    randomChump("Han Solo");
}
