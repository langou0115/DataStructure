#include "Array.h"
#include <stdexcept>

template <class T>
void Array<T>::resize()
{
    capacity_ = static_cast<int>(capacity_ * 1.5);
    T *new_data = new T[capacity_];
    for(int i = 0; i < size_; i++){
        new_data[i] = data_[i];
    }
    delete []data_;
    data_ = new_data;
}

template <class T>
void Array<T>::resize(int size)
{
    capacity_ = size;
    T *new_data = new T[capacity_];
    for(int i = 0; i < capacity_ && i < size_; i++){
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;

}

template <class T>
void Array<T>::push_back(const T& item)
{
    if(size_ == capacity_){
        resize();
    }
    data_[size_++] = item;
}

template <class T>
void Array<T>::pop_back()
{
    if(size_ == 0){
        throw std::out_of_range("pop out of range");
    }
    size_--;
}

template <class T>
void Array<T>::insert(int pos, const T& item)
{
    if(pos < 0 || pos >= size_){
        throw std::out_of_range("insert out of range");
    }
    if(size_ + 1 == capacity_){
        resize();
    }
    size_++;
    for(int i = size_ - 1; i > pos; i--){
        data_[i] = data_[i - 1];
    }
    data_[pos] = item;
}

template <class T>
T Array<T>::erase(int pos)
{
    if (pos < 0 || pos >= size_) {
        throw std::out_of_range("erase position out of range");
    }
    T tmp = data_[pos];
    for(int i = pos; i < size_ - 1; i++) data_[i] = data_[i + 1];
    size_--;
    return tmp;
}

template <class T>
const T& Array<T>::operator[](int idx) const
{
    if(idx < 0 || idx >= size_){
        throw std::out_of_range("index out of range");
    }
    return data_[idx];
}

template <class T>
T& Array<T>::operator[](int idx)
{
    if(idx < 0 || idx >= size_){
        throw std::out_of_range("index out of range");
    }
    return data_[idx];
}