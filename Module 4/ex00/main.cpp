#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"


int main()
{
    //********************** SUBJECT MAIN *****************/
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "Miau miau" << std::endl;
    j->makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "Woof Woof" << std::endl;
    meta->makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "Generic Animal sound..." << std::endl;

    delete meta;
    delete j;
    delete i;

    //********************** GOOD POLYMORPHISM *****************/

    std::cout << TITLE << "---- GOOD Polymorphism ----" << RESET << std::endl;
    const Animal* meta2 = new Animal();
    const Animal* j2 = new Dog();
    const Animal* i2 = new Cat();

    std::cout << TEST << "[TEST] " << RESET << j2->getType() << " " << std::endl;
    std::cout << TEST << "[TEST] " << RESET << i2->getType() << " " << std::endl;
    i2->makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "Miau Miau" << std::endl;
    j2->makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "Woof Woof" << std::endl;
    meta2->makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "Generic Animal sound..." << std::endl;

    delete meta2;
    delete j2;
    delete i2;

    //********************** WRONG POLYMORPHISM *****************/
    std::cout << TITLE << "\n---- Wrong Polymorphism ----" << RESET << std::endl;
    const WrongAnimal* wAnimal = new WrongAnimal();
    const WrongAnimal* wCat = new WrongCat();

    std::cout << TEST << "[TEST] " << RESET << wCat->getType() << " " << std::endl;
    wCat->makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "WrongAnimal generic sound..." << std::endl;
    wAnimal->makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "WrongAnimal generic sound..." << std::endl;

    delete wAnimal;
    delete wCat;

    //********************** ANIMAL ARRAY *****************/


    std::cout << TITLE << "---- Array of Animals ----" << RESET << std::endl;
    const Animal* zoo[4];

    for (int k = 0; k < 2; k++)
        zoo[k] = new Dog();
    for (int k = 2; k < 4; k++)
        zoo[k] = new Cat();

    for (int k = 0; k < 4; k++)
        std::cout << TEST << "[TEST] " << RESET << zoo[k]->getType() << " makes sound: ",
        zoo[k]->makeSound();

    for (int k = 0; k < 4; k++)
        delete zoo[k];

    //********************** COPY TESTS *****************/
    
    std::cout << TITLE << "---- Copy tests ----" << RESET << std::endl;

    Dog basicDog;
    {
        Dog tmpDog = basicDog; 
        tmpDog.makeSound();
        std::cout << TITLE << "[EXPECTED]: " << RESET << "Woof Woof" << std::endl;
    } 
    basicDog.makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "Woof Woof" << std::endl;

    Cat kitty;
    Cat copyCat;
    copyCat = kitty;
    copyCat.makeSound();
    std::cout << TITLE << "[EXPECTED]: " << RESET << "Miau Miau" << std::endl;


return 0;
}
