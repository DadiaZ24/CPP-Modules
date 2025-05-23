#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong usage. Usage: " << av[0] << " <level>\n";
        return 1;
    }

    Harl harl;
    harl.complain(av[1]);
    return 0;
}
