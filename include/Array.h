#ifndef _ARRARY_H
#define _ARRARY_H
#include <initializer_list>
#include <iostream>

template <class T>
class Array
{
public:
    Array(): size_(0), capacity_(1), data_(new T[1]){};
    Array(std::initializer_list<T> list): 
    size_(list.size()), capacity_(list.size()), data_(new T[list.size()]){
        int i = 0;
        for (const auto& item : list) {
            data_[i++] = item;
        }
    }
    Array(int size, T item = T()): size_(size), capacity_(size), data_(new T[size]){
        for(int i = 0; i < size; i++) data_[i] = item;
    }
    ~Array(){
        delete[] data_;
    }

    void push_back(const T& item);
    void pop_back();
    void insert(int pos, const T& item);
    T erase(int pos);
    void resize();
    void resize(int size);

    T& operator[] (int idx);
    const T& operator[] (int idx) const;
    int size() const{
        return size_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array<T>& arr){
        os << "[";
        for(int i = 0; i < arr.size_ - 1; i++){
            os << arr[i] << ", ";
        }
        if(arr.size_ - 1 >= 0) os << arr[arr.size_ - 1];
        os << "]";
        return os;
    }
private:
    int size_;
    int capacity_;
    T *data_;
};

#include "Array.tpp"
#endif // !_ARRARY_H