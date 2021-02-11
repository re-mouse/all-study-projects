#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span
{
    private:
        size_t _N;
        std::vector<int> *ar;
    public:
        Span(unsigned int N);
        void addNumber(int);
        void fillNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        Span(Span const &);
        Span &operator=(Span const &);
        ~Span();
};

#endif