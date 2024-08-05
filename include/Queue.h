#ifndef _QUEUE_H
#define _QUEUE_H
#include "Deque.h"

template <class T>
class Queue: protected Deque<T>
{
public:
    Queue() = default;
    ~Queue() = default;
    void push(T item){
        Deque<T>::push_back(item);
    }

    void pop(){
        Deque<T>::pop_front();
    }
    
    T &front(){
        return Deque<T>::front();
    }

    const T &front() const{
        return Deque<T>::front();
    }

    T &back(){
        return Deque<T>::back();
    }

    const T &back() const{
        return Deque<T>::back();
    }

    int size(){
        return Deque<T>::size();
    }

    friend std::ostream& operator<<(std::ostream &os, const Queue<T> &queue)
    {
        os << "front -------- back" << std::endl;
        for(int i = queue.front_; i != queue.back_; i++){
            i %= queue.capacity_;
            os << queue.data_[i] << " ";
        }
        return os;
    }
};

#endif // !_QUEUE_H