#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"

int main()
{
    std::cout << "\n== NOT FUNNY EXAMPLE GIVEN BY THE SUBJECT == \n";

    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    std::cout << "\n\033[33m\n=== THE EPIC BATTLE OF MUSTAFAR ===\n\n\033[0m";

    Weapon lightsaber("\033[94mBlue Lightsaber\033[0m");
    Weapon redLightsaber("\e[0;31mRed Lightsaber\033[0m");
    Weapon force("\e[0;32mThe Force\033[0m");

    HumanA obiWan("\e[0;36mObi-Wan Kenobi\033[0m", lightsaber);
    HumanB anakin("\e[1;35mAnakin Skywalker\033[0m");

    std::cout << "\033[33mThe battle begins...\n\n\033[0m";

    // Initial confrontation
    anakin.attack();
    obiWan.attack();
    anakin.setWeapon(redLightsaber);
    anakin.attack();

    // Force battle
    anakin.setWeapon(force);
    anakin.attack();

    std::cout << "\n\033[33mObi-Wan: \"It's over Anakin! I have the high ground!\"\033[0m\n";

    std::string highGroundType = "\e[0;32mHigh Ground\033[0m";
    lightsaber.setType(highGroundType);
    obiWan.attack();

    std::cout << "\033[33mAnakin Skywalker: \"You underestimate my power!\"\n\n\033[0m";

    anakin.setWeapon(redLightsaber);
    anakin.attack();

    obiWan.attack();
    std::cout << "\033[33m\nAnakin Skywalker: \"AAAAAAARGH!\"\n\033[0m";
    std::cout << "\e[0;36mAnakin Skywalker has been defeated!\n\n\033[0m";

    std::cout << "\033[33m=== END OF BATTLE ===\n\033[0m"
              << std::endl;

    return 0;
}