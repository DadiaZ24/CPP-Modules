#include "../includes/Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Cat::~Cat() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << SOUND << "[SOUND] " << RESET << "Miau miau" << std::endl;
}
