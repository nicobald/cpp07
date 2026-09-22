#pragma once

template <typename T>
Array<T>::Array() : _data(new T[0]), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array<T> &src) : _data(new T[src._size]()), _size(src._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = src._data[i];
}

template <typename T>
Array<T>::~Array()
{
    delete [] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (this != &rhs)
    {
        T *tmp = new T[rhs._size]();
        for (unsigned int i = 0; i < rhs._size; i++)
            tmp[i] = rhs._data[i];
        delete [] _data;
        _data = tmp;
        _size = rhs._size;
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfBoundsException();
    return (_data[i]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw OutOfBoundsException();
    return (_data[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Array: index out of bounds");
}
