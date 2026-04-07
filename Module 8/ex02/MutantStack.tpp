#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T, typename C>
MutantStack<T, C>::MutantStack() {}

template<typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack &other) : std::stack<T, C>(other) {}

template<typename T, typename C>
MutantStack<T, C> &MutantStack<T, C>::operator=(const MutantStack &other) {
    if (this != &other)
        std::stack<T, C>::operator=(other);
    return *this;
}

template<typename T, typename C>
MutantStack<T, C>::~MutantStack() {}

template<typename T, typename C>
typename C::iterator MutantStack<T, C>::begin() {
    return this->c.begin();
}

template<typename T, typename C>
typename C::iterator MutantStack<T, C>::end() {
    return this->c.end();
}

#endif