#include "../includes/Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Dog copy constructor called" << std::endl;
    if (this != &other)
        this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Dog::~Dog() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << SOUND << "[SOUND] " << RESET << "Woof Woof" << std::endl;
}
