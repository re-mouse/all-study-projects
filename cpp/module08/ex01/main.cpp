#include "span.hpp"

int main()
{
    Span spanTemp(100000);

    Span spanTest(spanTemp);
    std::vector<int> test;
    for (int i = 1; i < 25000; i++)
    {
        test.push_back(i * 5);
    }
    spanTest.fillNumbers(test.begin(), test.end());
    Span span = spanTest;
    std::cout << "shortest = " << span.shortestSpan() << "\n";
    std::cout << "longest = " << span.longestSpan() << "\n";
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
}