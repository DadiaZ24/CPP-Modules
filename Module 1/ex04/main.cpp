#include "Sed.hpp"

int main(int ac, char **argv)
{
    if (ac != 4)
    {
        std::cerr << "Wrong usage! Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    Sed sed(argv[1], argv[2], argv[3]);

    if (!sed.program())
        return 1;
    return 0;
}
