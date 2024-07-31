#ifndef _ARRARY_H
#define _ARRARY_H
#include <iostream>

template <class T>
class Array
{
public:
    Array(): size_(0), capacity_(1), data_(new T[1]){};
    ~Array(){
        delete[] data_;
    }

    void push_back(T item);
    void pop_back();
    void insert(int pos, T item);
    T erase(int pos);
    void resize();
    void resize(int size);

    T& operator[] (int idx);
    const T& operator[] (int idx) const;
    int size() const{
        return size_;
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& c);
private:
    int size_;
    int capacity_;
    T *data_;
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const Array<U>& arr)
{
    os << "[";
    for(int i = 0; i < arr.size_ - 1; i++){
        os << arr[i] << ", ";
    }
    os << arr[arr.size_ - 1] << "]";
    return os;
}

#include "Array.tpp"
#endif // !_ARRARY_H