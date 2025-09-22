#ifndef ANIMAL_HPP
#define ANIMAL_HPP

//COLORS:
#define RESET "\033[0m"
#define CLASS_CALL "\033[35m"
#define TEST "\033[36m"
#define SOUND "\033[33m"
#define TITLE "\033[32m"

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const;

};

#endif