#include "../includes/Dog.hpp"

Dog::Dog() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Dog copy constructor called" << std::endl;
    type = other.type;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        delete brain;
        brain = new Brain(*other.brain);
        type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << SOUND << "[SOUND] " << RESET << "Woof Woof" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->brain;
}
