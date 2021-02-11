#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T, typename F>
F easyfind(T &t, F v)
{  
    if (std::find(t.begin(), t.end(), v) != t.end())
        return *std::find(t.begin(), t.end(), v);
    else
        throw std::exception();
}

#endif