#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        typedef typename C::iterator iterator;

        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif