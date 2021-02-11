#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& f, T& s)
{
    T temp = f;
    f = s;
    s = temp;
}

template <typename T>
T &min(T& f, T& s)
{
    return f > s ? s : f;
}

template <typename T>
T &max(T& f, T& s)
{
    return f < s ? s : f;
}

#endif