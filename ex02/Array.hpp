#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T               *_data;
        unsigned int    _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        ~Array();

        Array   &operator=(const Array &rhs);

        T       &operator[](unsigned int i);
        const T &operator[](unsigned int i) const;

        unsigned int    size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"
