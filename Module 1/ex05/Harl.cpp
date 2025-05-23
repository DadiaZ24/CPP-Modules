#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[ DEBUG ]\n"
              << "I just recalibrated the hyperdrive on my T-16. Feels like I'm cruising through Beggar's Canyon again!\n";
}

void Harl::info()
{
    std::cout << "[ INFO ]\n"
              << "Did you know R2 once hacked into an Imperial mainframe using just a buzz and a beep? Honestly, the droid deserves a promotion.";
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n"
              << "The shields are at 27%. If someone doesn't fix the deflector dish soon, we're space dust!";
}

void Harl::error()
{
    std::cout << "[ ERROR ]\n"
              << "This is madness! The Death Star is fully operational, and we’re still debating battle plans?! We're doomed!\n";
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (size_t i = 0; i < level.length(); ++i)
    {
        if (level[i] >= 'a' && level[i] <= 'z')
            level[i] = std::toupper(level[i]);
    }
    void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    }
}
