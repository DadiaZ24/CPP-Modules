#include "../includes/Brain.hpp"

Brain::Brain() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Brain Copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout << CLASS_CALL << "[CLASS CALL] " << RESET << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, const std::string& idea) {
    if (i >= 0 && i < 99)
        ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
    if (i >= 0 && i < 99)
        return ideas[i];
    return "";
}
