#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2) : filename(filename), s1(s1), s2(s2) {}

void Sed::replace(std::ifstream &infile, std::ofstream &outfile)
{
    // Read the file
    std::string line;
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line << std::endl;
    }
}

bool Sed::program()
{
    // Open file and transform into C string
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: Could not open the file" << std::endl;
        return false;
    }

    // Create output file
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Error: Could not create the output file" << std::endl;
        return false;
    }
    Sed::replace(infile, outfile);
    infile.close();
    outfile.close();
    return true;
}
