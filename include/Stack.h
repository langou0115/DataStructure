#ifndef _STACK_H
#define _STACK_H

#include <ostream>
template <class T>
class Stack
{
public:
    Stack(): size_(0), capacity_(1), data_(new T[1]){}
    ~Stack() { delete []data_;}

    void push(const T& item);
    void pop();
    T& top();
    const T& top() const;
    bool is_empty() const { return size_ == 0; }
    int size() const { return size_; }

    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& st){
        os << "bottom <- top:" << std::endl;
        for(int i = 0; i < st.size_; i++){
            os << st.data_[i] << " ";
        }
        return os;
    }
private:
    void resize();
    int size_;
    int capacity_;
    T* data_;
};

#include "Stack.tpp"
#endif // !_STACK_H