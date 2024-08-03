#include "Stack.h"
#include <stdexcept>

template <class T>
void Stack<T>::resize()
{
    capacity_ = static_cast<int>(1.5 * capacity_);
    T *new_data = new T[capacity_];
    for(int i = 0; i < size_; i++){
        new_data[i] = data_[i];
    }
    delete []data_;
    data_ = new_data;
}

template <class T>
void Stack<T>::push(const T& item)
{
    if(size_ + 1 > capacity_){
        resize();
    }
    data_[size_++] = item;
}

template <class T>
void Stack<T>::pop()
{
    if(size_ == 0){
        throw  std::out_of_range("pop out of range");
    }
    size_--;
}

template <class T>
const T& Stack<T>::top() const
{
    if(size_ == 0){
        throw  std::out_of_range("stack no data");
    }
    return data_[size_ - 1];
}

template <class T>
T& Stack<T>::top()
{
    if(size_ == 0){
        throw  std::out_of_range("stack no data");
    }
    return data_[size_ - 1];
}
