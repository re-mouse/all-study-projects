#include "span.hpp"

Span::Span(unsigned int N) : _N(N)
{
    this->ar = new std::vector<int>;
    if (N < 0)
        throw std::exception();
}

Span::~Span(){ delete ar; }

Span::Span(Span const &span) : _N(span._N)
{
    this->ar = new std::vector<int>;
    for (unsigned int i = 0; i < span.ar->size(); i++)
        addNumber((*span.ar)[i]);
}

Span &Span::operator=(Span const &span)
{
    delete ar;
    _N = span._N;
    this->ar = new std::vector<int>;
    for (unsigned int i = 0; i < span.ar->size(); i++)
        addNumber((*span.ar)[i]);
    return *this;
}

void Span::fillNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->ar->size() + (&(*end) - &(*end)) / sizeof(int) > _N)
        throw std::exception();
    ar->assign(begin, end);
    std::sort(ar->begin(), ar->end());
}

void Span::addNumber(int number)
{
    if (this->ar->size() >= _N)
        throw std::exception();
    ar->push_back(number);
    std::sort(ar->begin(), ar->end());
}

int Span::longestSpan()
{
    if (this->ar->size() < 2)
        throw std::exception();
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> temp = std::minmax_element(ar->begin(), ar->end());
    return *(temp.second) - *(temp.first);
}

int Span::shortestSpan()
{
    if (this->ar->size() < 2)
        throw std::exception();
    int minDiff = (*ar)[1] - (*ar)[0];
    for (unsigned int i = 0; i < ar->size() - 1; i++)
    {
        if ((*ar)[i + 1] - (*ar)[i] < minDiff)
            minDiff = (*ar)[i + 1] - (*ar)[i];
    }
    return minDiff;
}