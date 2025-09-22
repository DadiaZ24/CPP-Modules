#ifndef BRAIN_HPP
#define BRAIN_HPP

//COLORS:
#define RESET "\033[0m"
#define CLASS_CALL "\033[35m"
#define TEST "\033[36m"
#define SOUND "\033[33m"
#define TITLE "\033[32m"

#include <iostream>
#include <string>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        virtual ~Brain();

        void setIdea(int i, const std::string& idea);
        std::string getIdea(int i) const;

};

#endif