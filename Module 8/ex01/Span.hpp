#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
    private:
        unsigned int _max;
        std::vector<int> _numbers;
    
    public:
        Span();
        Span(unsigned int max);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end) {
            unsigned int rangeSize = static_cast<unsigned int>(std::distance(begin, end));
            if (_numbers.size() + rangeSize > _max)
                throw std::runtime_error("The range you are adding reaches the maximum allowed");
            _numbers.insert(_numbers.end(), begin, end);
        }
};

#endif
