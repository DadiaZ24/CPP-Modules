#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>

class Sed
{
private:
    std::string filename;
    std::string s1;
    std::string s2;

public:
    Sed(std::string filename, std::string s1, std::string s2);
    void replace(std::ifstream &infile, std::ofstream &outfile);
    bool program();
};

#endif