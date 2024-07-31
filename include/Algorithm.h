#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

template<typename T>
void my_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

#endif // !_ALGORITHM_H_