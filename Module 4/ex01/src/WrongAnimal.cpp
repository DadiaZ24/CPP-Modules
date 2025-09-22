#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "WrongAnimal asignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << SOUND << "[SOUND] " << RESET << "WrongAnimal generic sound..." << std::endl;
}
