#ifndef _LIST_H
#define _LIST_H

#include <ostream>
template <class T>
class List{
public:
    List(): size_(0), head_(nullptr), tail_(nullptr){}
    ~List(){
        if(head_) tail_->next_ = nullptr; // 打破循环
        while(head_){
            Node* tmp = head_;
            head_ = head_->next_;
            delete tmp; tmp = nullptr;
        }
        tail_ = nullptr;
        size_ = 0;
    }

    void push_back(const T& item);
    void pop_back();
    void push_front(const T& item);
    void pop_front();
    void insert(int pos, const T& item);
    T erase(int pos);

    int size() {return size_;}
    
    friend std::ostream& operator<<(std::ostream &os, const List<T>& list){
        auto cur = list.head_;
        os << '[';
        for(int i = 0; i < list.size_ - 1; i++){
            os << cur->data_ << " -> ";
            cur = cur->next_;
        }
        if(list.size_ - 1 >= 0) os << cur->data_;
        os << ']';
        return os;
    }
private:
    struct Node {
        T data_;
        Node *next_, *prev_;
        Node(const T& data) : data_(data), next_(this), prev_(this){}
    };

    Node* head_;
    Node* tail_;
    int size_;
};

#include "List.tpp"
#endif // !_LIST_H