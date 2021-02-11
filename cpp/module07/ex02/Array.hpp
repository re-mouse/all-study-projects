#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T, int SIZE>
class Array
{
    private:
        T *array;
        const unsigned int _size;
    public:
        Array() : _size(SIZE)
        {
            array = new T[SIZE];
        }
        Array(unsigned int N) : _size(SIZE)
        {
            array = new T[SIZE];
            T *defaultValue = new T;
            for (unsigned int i = 0; i < N; i++)
                array[i] = *defaultValue;
            delete defaultValue;
        }
        T &operator[](int N)
        {
            if (N < 0 || N >= (int)_size)
                throw std::exception();
            else
                return array[N];
        }
        unsigned int size()
        {
            return _size;
        }
};

#endif
