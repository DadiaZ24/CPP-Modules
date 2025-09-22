#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "WrongCat assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "WRongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << SOUND << "[SOUND] " << RESET "glu glu glu" << std::endl;
}
