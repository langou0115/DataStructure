#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

#include "Array.h"
#include <ostream>

template <class T>
// 小根堆
class PriorityQueue{
public:
    PriorityQueue(){}
    ~PriorityQueue(){}

    void push(T item);
    void pop();
    
    T top() const {return arr[0];};
    int size() {return arr.size();}

    friend std::ostream & operator<<(std::ostream &os, const PriorityQueue<T>& heap)
    {
        os << "top --------------- bottom" << std::endl;
        for(int i = 0; i < heap.arr.size(); i++){
            os << heap.arr[i] << " ";
        }
        return os;
    }
private:
    Array<T> arr;
};

#include "PriorityQueue.tpp"
#endif // !_PRIORITYQUEUE_H