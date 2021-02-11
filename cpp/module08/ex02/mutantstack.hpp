#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>

template <typename T> 
class MutantStack : public std::stack<T>
{
    private:
        unsigned int typeByteSize;
        void *beginPointer;
        void *endPointer;
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(MutantStack const &);
        MutantStack &operator=(MutantStack const &);
        class iterator
        {
            private:
                T *currentPosition;
                T *lowLimit;
                T *highLimit;
            public:
                iterator(T *begin, T*low, T*high);
                iterator();
                ~iterator();
                iterator& operator=(const iterator&);
                T& operator*();
                iterator &operator--();
                iterator &operator++();
                bool operator!=(const iterator&);
                bool operator==(const iterator&);
        };
        iterator begin();
        iterator end();
        void push(T);
        void pop();
};

template <typename T>
MutantStack<T>::~MutantStack()
{
    
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &)
{
}

template <typename T>
MutantStack<T>::MutantStack()
{
    beginPointer = NULL;
    typeByteSize = sizeof(T);
}

template <typename T>
void MutantStack<T>::push(T t)
{
    std::stack<T>::push(t);
    if (beginPointer == NULL)
        beginPointer = &std::stack<T>::top();
    endPointer = static_cast<T*>(&std::stack<T>::top()) + 1;
}

template <typename T>
void MutantStack<T>::pop()
{
    std::stack<T>::pop();
    endPointer = static_cast<T*>(&std::stack<T>::top()) + 1;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return MutantStack<T>::iterator((T*)beginPointer, (T*)beginPointer, (T*)endPointer);
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return MutantStack<T>::iterator((T*)endPointer, (T*)beginPointer, (T*)endPointer);
}

template <typename T>
MutantStack<T>::iterator::iterator(T *begin, T*low, T*high)
{
    lowLimit = low;
    highLimit = high;
    this->currentPosition = begin;
}

template <typename T>
MutantStack<T>::iterator::iterator()
{
    this->currentPosition = NULL;
    lowLimit = NULL;
    highLimit = NULL;
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(const iterator&iter)
{
    this->highLimit = iter.highLimit;
    this->lowLimit = iter.lowLimit;
    this->currentPosition = iter.currentPosition;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++()
{
    if (currentPosition + 1 > highLimit || !highLimit || !lowLimit)
        throw std::exception();
    currentPosition++;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--()
{
    if (currentPosition - 1 < lowLimit|| !highLimit || !lowLimit)
        throw std::exception();
    currentPosition--;
    return *this;
}



template <typename T>
bool MutantStack<T>::iterator::operator==(const iterator &a)
{
    if (!highLimit || !lowLimit)
        throw std::exception();
    return this->currentPosition == a.currentPosition;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator &a)
{
    if (!highLimit || !lowLimit)
        throw std::exception();
    return this->currentPosition != a.currentPosition;
}

template <typename T>
T &MutantStack<T>::iterator::operator*()
{
    if (!highLimit || !lowLimit)
        throw std::exception();
    return *(static_cast<T*>(currentPosition));
}

#endif