#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void crawlIntro()
{
    std::cout << "A long time ago in a galaxy far, far away...\n\n";
    std::cout << "Episode V — THE RISE OF FRAGTRAP\n\n";
    std::cout << "While the ClapTrap rebellion spreads across the galaxy,\n"
              << "a new hero emerges from the circuitry of destiny...\n"
              << "Can he unite the bots and bring balance to the source code?\n\n";
}

void printSeparator(const std::string &title)
{
    std::cout << "\n==== " << title << " ====\n"
              << std::endl;
}

int main()
{
    crawlIntro();

    printSeparator("ClapTrap Rebellion Begins");

    ClapTrap r2d2("R2-D2");
    r2d2.attack("Imperial Probe Droid");
    r2d2.takeDamage(5);
    r2d2.beRepaired(3);

    ClapTrap c3po("C-3PO");
    c3po.attack("Stormtrooper");
    c3po.takeDamage(2);
    c3po.beRepaired(1);

    printSeparator("ScavTrap Joins the Fight");

    ScavTrap chewie("ChewieTrap");
    chewie.attack("Tie Fighter");
    chewie.guardGate();
    chewie.takeDamage(20);
    chewie.beRepaired(10);

    printSeparator("A Wild FragTrap Appears");

    FragTrap luke("LukeTrap");
    luke.attack("Death Star Laser");
    luke.takeDamage(40);
    luke.beRepaired(30);
    luke.highFivesGuys();

    printSeparator("Empire Strikes Back");

    FragTrap vader("VaderBot");
    vader.attack("LukeTrap");
    vader.highFivesGuys(); // ironically

    printSeparator("Final Words");

    std::cout << "As the binary suns set, our heroes prepare for the next challenge...\n";
    std::cout << "May the source be with you.\n";

    return 0;
}
