#include "List.h"
#include <stdexcept>

template <class T>
void List<T>::push_back(const T& item)
{
    Node *node = new Node(item);
    if(size_ == 0){
        head_ = node;
        tail_ = node;
    }else{
        node->next_ = head_;
        node->prev_ = tail_;
        head_->prev_ = node;
        tail_->next_ = node;
        tail_ = tail_->next_;
    }
    size_++;
}

template <class T>
void List<T>::pop_back()
{
    if(size_ == 0) throw std::out_of_range("pop_back from empty list");
    Node *tmp = tail_;
    if(tail_ == head_){
        head_ = tail_ = nullptr;
    }else{
        tail_ = tail_->prev_;
        tail_->next_ = head_;
        head_->prev_ = tail_;
    }
    delete tmp; tmp = nullptr;
    size_--;
}

template <class T>
void List<T>::push_front(const T& item)
{
    Node *node = new Node(item);
    if(size_ == 0){
        head_ = tail_ = node;
    }else{
        node->next_ = head_;
        node->prev_ = tail_;
        tail_->next_ = node;
        head_->prev_ = node;
        head_ = node;
    }
    size_++;
}

template <class T>
void List<T>::pop_front()
{
    if(size_ == 0) throw std::out_of_range("pop_front from empty list");
    Node *tmp = head_;
    if(size_ == 1){
        head_ = tail_ = nullptr;
    }else{
        head_ = head_->next_;
        head_->prev_ = tail_;
        tail_->next_ = head_;
    }
    delete tmp; tmp = nullptr;
    size_--;
}

template <class T>
void List<T>::insert(int pos, const T& item)
{
    if(pos <= 0 || pos > size_){
        throw std::out_of_range("Insert out of index");
    }
    if(pos == 1){
        push_front(item);
        return;
    } 
    Node *node = new Node(item);
    Node *tmp = head_;
    for(int i = 1; i < pos - 1; i++) tmp = tmp->next_;
    tmp->next_->prev_ = node;
    node->next_ = tmp->next_;
    node->prev_ = tmp;
    tmp->next_ = node; 
    size_++;
}

template <class T>
T List<T>::erase(int pos)
{
    if(pos <= 0 || pos > size_){
        throw std::out_of_range("Erase out of index");
    }
    T val;
    if(size_ == 1){
        val = head_->data_;
        delete head_;
        head_ = tail_ = nullptr;
    }else if(pos == 1){
        Node *tmp = head_;
        val = tmp->data_;
        head_ = head_->next_;
        head_->prev_ = tail_;
        tail_->next_ = head_;
        delete tmp; tmp = nullptr;
    }else{
        Node *tmp = head_;
        for(int i = 1; i < pos; i++){
            tmp = tmp->next_;
        }
        if(tmp == tail_) tail_ = tmp->prev_;
        val = tmp->data_;
        tmp->prev_->next_ = tmp->next_;
        tmp->next_->prev_ = tmp->prev_;
        delete tmp; tmp = nullptr;
    }
    size_--;
    return val;
}