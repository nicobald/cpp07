#pragma once

#include <iostream>
#include <string>

template <typename T, typename L, typename F>
void iter(T *a, const L b, F func)
{
    for (int i = 0; i < b; i++)
        func(a[i]);
}