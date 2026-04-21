#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

void PmergeMe::run(char **values) {
    int i = 0;

    while (values[i]) {
        int j = 0;
        while (values[i][j])
        {
            if (!isdigit(values[i][j++]))
                throw std::runtime_error("You can only use numbers to sort");
        }
        if (values[i][0] == '\0')
            throw std::runtime_error("You can not sort an empty string!");
        int n = strtol(values[i], NULL, 10);
        if (n < 0)
            throw std::runtime_error("You can only input positive numbers and not longer than INT MAX.\n");
        if (std::find(_vec.begin(), _vec.end(), n) != _vec.end())
            throw std::runtime_error("Duplicated values are not allowed!");
        _vec.push_back(n);
        _deq.push_back(n);
        i++;
    }

    std::cout << "Before:";
    for (int j = 0; j < (int)_vec.size(); j++)
        std::cout << " " << _vec[j];
    std::cout << std::endl;

    std::clock_t start = std::clock();
    sortVec(_vec);
    double elapsed = (double)(std::clock() - start) / CLOCKS_PER_SEC;
    std::cout << "After:";
    for (size_t j = 0; j < _vec.size(); j++)
        std::cout << " " << _vec[j];
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << elapsed << " s" << std::endl;
    std::clock_t start2 = std::clock();
    sortDeq(_deq);
    double elapsed2 = (double)(std::clock() - start2) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << elapsed2 << " s" << std::endl;
}

void PmergeMe::sortVec(std::vector<int> &vec) {
    int rest = 0;
    bool hasRest = false;
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> largers;

    if (vec.size() <= 1)
        return;
    if ((vec.size() % 2) != 0) {
        rest = vec.back();
        vec.pop_back();
        hasRest = true;
    }
    for (size_t i = 0; i < vec.size(); i += 2) {
        if (vec[i] >= vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }

    for (size_t i = 0; i < pairs.size(); i++)
    {
        largers.push_back(pairs[i].first);
    }
    sortVec(largers);

    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> pairUsed(pairs.size(), false);
    for (size_t i = 0; i < largers.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!pairUsed[j] && pairs[j].first == largers[i])
            {
                sortedPairs.push_back(pairs[j]);
                pairUsed[j] = true;
                break;
            }
        }
    }

    std::vector<int> chain;
    chain.push_back(sortedPairs[0].second);
    for (size_t i = 0; i < sortedPairs.size(); i++)
        chain.push_back(sortedPairs[i].first);

    std::vector<int> rests;
    for (size_t i = 1; i < sortedPairs.size(); i++)
        rests.push_back(sortedPairs[i].second);
    
    std::vector<size_t> jacob = jacobsthalOrderVec(rests.size());

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t index = jacob[i];
        int value = rests[index];
        int bound = sortedPairs[index + 1].first;

        std::vector<int>::iterator high = std::upper_bound(chain.begin(), chain.end(), bound);
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), high, value);
        chain.insert(pos, value);
    }

    if (hasRest)
    {
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), rest);
        chain.insert(pos, rest);
    }

    vec = chain;
}

std::vector<size_t> PmergeMe::jacobsthalOrderVec(size_t n) const {
    std::vector<size_t> res;
    if (n == 0)
        return res;
    
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    
    size_t prev = 0;
    for (size_t k = 1; k < jacob.size(); ++k)
    {
        size_t current = std::min(jacob[k], n);
        for (size_t i = current; i > prev; --i)
            res.push_back(i - 1);
        prev = current;
        if (prev >= n) break;
    }
    return res;
}

void PmergeMe::sortDeq(std::deque<int> &deq) {
    int rest = 0;
    bool hasRest = false;
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> largers;

    if (deq.size() <= 1)
        return;
    if ((deq.size() % 2) != 0) {
        rest = deq.back();
        deq.pop_back();
        hasRest = true;
    }
    for (size_t i = 0; i < deq.size(); i += 2) {
        if (deq[i] >= deq[i + 1])
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
        else
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
    }

    for (size_t i = 0; i < pairs.size(); i++)
    {
        largers.push_back(pairs[i].first);
    }
    sortDeq(largers);

    std::deque<std::pair<int, int> > sortedPairs;
    std::deque<bool> pairUsed(pairs.size(), false);
    for (size_t i = 0; i < largers.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!pairUsed[j] && pairs[j].first == largers[i])
            {
                sortedPairs.push_back(pairs[j]);
                pairUsed[j] = true;
                break;
            }
        }
    }

    std::deque<int> chain;
    chain.push_back(sortedPairs[0].second);
    for (size_t i = 0; i < sortedPairs.size(); i++)
        chain.push_back(sortedPairs[i].first);

    std::deque<int> rests;
    for (size_t i = 1; i < sortedPairs.size(); i++)
        rests.push_back(sortedPairs[i].second);
    
    std::deque<size_t> jacob = jacobsthalOrderDeq(rests.size());

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t index = jacob[i];
        int value = rests[index];
        int bound = sortedPairs[index + 1].first;

        std::deque<int>::iterator high = std::upper_bound(chain.begin(), chain.end(), bound);
        std::deque<int>::iterator pos = std::lower_bound(chain.begin(), high, value);
        chain.insert(pos, value);
    }

    if (hasRest)
    {
        std::deque<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), rest);
        chain.insert(pos, rest);
    }

    deq = chain;
}

std::deque<size_t> PmergeMe::jacobsthalOrderDeq(size_t n) const {
    std::deque<size_t> res;
    if (n == 0)
        return res;
    
    std::deque<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    
    size_t prev = 0;
    for (size_t k = 1; k < jacob.size(); ++k)
    {
        size_t current = std::min(jacob[k], n);
        for (size_t i = current; i > prev; --i)
            res.push_back(i - 1);
        prev = current;
        if (prev >= n) break;
    }
    return res;
}
