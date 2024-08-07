#ifndef _DEQUE_H
#define _DEQUE_H

#include <ostream>
template <class T>
class Deque {
protected:
    T* data_;
    int capacity_;
    int front_; // 队列第一个元素位置
    int back_; // 队列最后一个可用位置

    // Utility function to resize the deque when full
    void resize();

public:
    // Constructor
    Deque(): capacity_(8), data_(new T[8]), front_(0), back_(0){}

    // Destructor
    virtual ~Deque() {delete []data_;}

    // Insert element at the front
    void push_front(T item);

    // Insert element at the back
    void push_back(T item);

    // Remove element from the front
    void pop_front();

    // Remove element from the back
    void pop_back();

    // Get the front element
    T& front() {return data_[front_];}
    const T& front() const{return data_[front_];}

    // Get the back element
    T& back() {return data_[(back_ - 1 + capacity_) % capacity_];}
    const T& back() const {return data_[(back_ - 1 + capacity_) % capacity_];};

    // Check if deque is empty
    bool empty() const{return front_ == back_;};

    // Get the size of the deque
    int size() const{return (back_ - front_ + capacity_) % capacity_;}

    friend std::ostream& operator<<(std::ostream &os, const Deque<T> &deque)
    {
        os << "front -------- back" << std::endl;
        for(int i = deque.front_; i != deque.back_; i++){
            i %= deque.capacity_;
            os << deque.data_[i] << " ";
        }
        return os;
    }
};

#include "Deque.tpp"
#endif // !_DEQUE_H