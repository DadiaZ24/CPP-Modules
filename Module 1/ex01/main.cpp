#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
    int N = 24;
    Zombie *horde = zombieHorde(N, "Obi-Wan Kenobi");

    if (!horde)
    {
        std::cerr << "Failed to create zombie horde.\n";
        return 1;
    }

    for (int i = 0; i < N; ++i)
    {
        std::cout << "Obi-Wan Kenobi " << i + 1 << ": ";
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
