#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"


int main() {

    std::cout << "===== Test 1: Basic Polymorphism =====" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " says: ";
    dog->makeSound();

    std::cout << cat->getType() << " says: ";
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n===== Test 2: Array of Animals =====" << std::endl;
    const int N = 6;
    Animal* animals[N];
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < N; i++) {
        animals[i]->makeSound();
    }
    for (int i = 0; i < N; i++) {
        delete animals[i];
    }

    std::cout << "\n===== Test 3: Deep Copy (Dog) =====" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase the ball");

    Dog dog2 = dog1;
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    dog2.getBrain()->setIdea(0, "Eat food");
    std::cout << "After modifying Dog2 idea[0]:" << std::endl;
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n===== Test 4: Deep Copy (Cat) =====" << std::endl;
    Cat cat1;
    cat1.getBrain()->setIdea(1, "Sleep on the couch");

    Cat cat2;
    cat2 = cat1;
    std::cout << "Cat1 idea[1]: " << cat1.getBrain()->getIdea(1) << std::endl;
    std::cout << "Cat2 idea[1]: " << cat2.getBrain()->getIdea(1) << std::endl;

    cat2.getBrain()->setIdea(1, "Scratch the sofa");
    std::cout << "After modifying Cat2 idea[1]:" << std::endl;
    std::cout << "Cat1 idea[1]: " << cat1.getBrain()->getIdea(1) << std::endl;
    std::cout << "Cat2 idea[1]: " << cat2.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n===== Test 5: WrongAnimal vs WrongCat =====" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    std::cout << wrong->getType() << " says: ";
    wrong->makeSound(); 
    delete wrong;

    return 0;
}
