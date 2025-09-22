#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

//COLORS:
#define RESET "\033[0m"
#define CLASS_CALL "\033[35m"
#define TEST "\033[36m"
#define SOUND "\033[33m"

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
};

#endif