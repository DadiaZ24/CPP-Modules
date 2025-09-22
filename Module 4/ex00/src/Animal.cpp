#include "../includes/Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Animal Copy constructor called" << std::endl;
    if (this != &other)
        this->type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << SOUND << "[SOUND] " << RESET << "Generic Animal sound..." << std::endl;
}
