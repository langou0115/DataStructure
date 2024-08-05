#include "Deque.h"
#include <stdexcept>


template <class T>
void Deque<T>::resize() {
    int new_capacity = 2 * capacity_;  // 新容量是当前容量的两倍
    T* new_data = new T[new_capacity]; // 分配新的数组空间

    // 将旧数据复制到新数组中
    for (int i = 0; i < capacity_ - 1; ++i) {
            new_data[i] = data_[(front_ + i) % capacity_];
    }

    // 释放旧的数组空间
    delete[] data_;

    // 更新指针和容量
    back_ = size();
    front_ = 0;

    data_ = new_data;
    capacity_ = new_capacity;
}


template <class T>
void Deque<T>::push_front(T item)
{
    if((front_ - 1 + capacity_) % capacity_ == back_){
        resize();
    }
    if(is_empty()){
        front_ = 0;
        back_ = 1;
    }else{
        front_ = (front_ - 1 + capacity_) % capacity_;
    }

    data_[front_] = item;
}

template <class T>
void Deque<T>::pop_front()
{
    if(front_ == back_){
        throw std::out_of_range("pop front out of range");
    }

    front_ = (front_ + 1) % capacity_;
}

template <class T>
void Deque<T>::push_back(T item)
{
    if((back_ + 1) % capacity_ == front_){
        resize();
    }
    data_[back_] = item;
    back_ = (back_ + 1) % capacity_;
}

template <class T>
void Deque<T>::pop_back()
{
    if(front_ == back_){
        throw std::out_of_range("pop front out of range");
    }

    back_ = (back_ - 1) % capacity_;
}