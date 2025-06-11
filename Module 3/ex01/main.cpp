#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void printLine()
{
    std::cout << "\n========================================\n"
              << std::endl;
}

int main()
{
    std::cout << "A long time ago in a galaxy far, far away...\n\n";
    std::cout << "Episode IV — A NEW HOPE FOR CLAPTRAPS\n";
    std::cout << "Rebel robots are assembling to defend the galaxy from the evil Empire!\n";

    printLine();

    ClapTrap luke("Luke-SkyClapper");
    ClapTrap leia("Leia-Circuit");

    luke.attack("Stormtrooper");
    leia.attack("Darth-Vacuum");

    luke.takeDamage(4);
    leia.beRepaired(3);

    printLine();

    std::cout << "Meanwhile, a mysterious guardian awakens...\n\n";

    ScavTrap obiWan("ObiTrap Kenobi");

    obiWan.attack("Darth-Trapious");
    obiWan.guardGate();
    obiWan.takeDamage(30);
    obiWan.beRepaired(15);

    printLine();

    std::cout << "Darth-Trapious approaches...\n";

    ScavTrap vader("VaderBot");
    vader.attack("ObiTrap Kenobi");
    vader.guardGate();

    printLine();

    std::cout << "The force will be with them... always.\n";

    return 0;
}