#include "Functions.hpp"

Base *generate() {
    int random = std::rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A";
    else if (dynamic_cast<B *>(p))
        std::cout << "B";
    else if (dynamic_cast<C *>(p))
        std::cout << "C";
    else
        std::cout << "Unknown";
}

void identify(Base &p) {
    try {
        dynamic_cast<A &>(p);
        std::cout << "A";
        return;
    }
    catch (std::exception &e) {}

    try {
        dynamic_cast<B &>(p);
        std::cout << "B";
        return;
    }
    catch (std::exception &e) {}

    try {
        dynamic_cast<C &>(p);
        std::cout << "C";
        return;
    }
    catch (std::exception &e) {}

    std::cout << "Unknown";
}