#include "../includes/Cat.hpp"

Cat::Cat() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Cat copy constructor called" << std::endl;
    type = other.type;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        delete brain;
        brain = new Brain(*other.brain);
        type = other.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << SOUND << "[SOUND] " << RESET << "Miau miau" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->brain;
}
