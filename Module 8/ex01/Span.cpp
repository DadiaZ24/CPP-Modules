#include "Span.hpp"

Span::Span() : _max(0) {}
Span::~Span() {}
Span::Span(unsigned int max) : _max(max) {}
Span::Span(const Span &other) : _max(other._max), _numbers(other._max) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _max = other._max;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_numbers.size() >= _max)
        throw std::runtime_error("Span is full");
    _numbers.push_back(n);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int shortest = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest)
            shortest = diff;
    }

    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}
