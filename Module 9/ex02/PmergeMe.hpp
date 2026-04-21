#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        void sortVec(std::vector<int> &vec);
        void sortDeq(std::deque<int> &deq);
        std::vector<size_t> jacobsthalOrderVec(size_t n) const;
        std::deque<size_t> jacobsthalOrderDeq(size_t n) const;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void run(char** numbers);
};

#endif
