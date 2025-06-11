#include "ClapTrap.hpp"

int main()
{
    ClapTrap anakin("Anakin Skywalker");
    ClapTrap obiWan("Obi-Wan Kenobi");

    std::cout << "\n🔥 The Battle of Mustafar begins! 🔥\n"
              << std::endl;

    // Turn 1
    anakin.attack("Obi-Wan Kenobi");
    obiWan.takeDamage(3);

    // Turn 2
    obiWan.attack("Anakin Skywalker");
    anakin.takeDamage(4);

    // Turn 3
    anakin.attack("Obi-Wan Kenobi");
    obiWan.takeDamage(4);
    obiWan.beRepaired(2);

    // Turn 4
    obiWan.attack("Anakin Skywalker");
    anakin.takeDamage(5);

    // Turn 5
    anakin.beRepaired(3);
    anakin.attack("Obi-Wan Kenobi");
    obiWan.takeDamage(5);

    // Turn 6
    std::cout << "\n⚔️ Obi-Wan: \"It's over, Anakin! I have the high ground!\"\n";
    std::cout << "⚡ Anakin: \"You underestimate my power!\"\n"
              << std::endl;

    obiWan.attack("Anakin Skywalker");
    anakin.takeDamage(10); // Obi-Wan goes all in

    std::cout << "\n💥 Anakin is defeated...\n"
              << std::endl;

    return 0;
}
