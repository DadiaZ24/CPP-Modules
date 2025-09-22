#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"


int main() {

    std::cout << "\n===== Deep copy test (Dog) =====\n";
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase the ball");
    dog1.getBrain()->setIdea(1, "Eat food");

    Dog dog2 = dog1; // Copy constructor
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << "\n";
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << "\n";

    dog2.getBrain()->setIdea(0, "Sleep all day");
    std::cout << "After modification:\n";
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << "\n";
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << "\n";

    std::cout << "\n===== Deep copy test (Cat) =====\n";
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Climb the tree");

    Cat cat2;
    cat2 = cat1; // Assignment operator
    std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << "\n";
    std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << "\n";

    cat2.getBrain()->setIdea(0, "Scratch the sofa");
    std::cout << "After modification:\n";
    std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << "\n";
    std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << "\n";

    return 0;
}
