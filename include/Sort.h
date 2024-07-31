#ifndef _SORT_H
#define _SORT_H
#include <iostream>

template <class T>
class Sort
{
public:
    Sort(T arr_[], int len_);
    Sort(const Sort &) = delete;
    virtual ~Sort() { delete []arr_; }
    virtual void sort() = 0;
    void print()
    {
        for(int i = 0; i < len_; i++){
            std::cout << arr_[i] << " ";
        }
        std::cout << std::endl;
    }
protected:
    T *arr_;
    int len_;
};

template <class T>
class InsertSort: public Sort<T>
{
public:
    InsertSort(T arr[], int len): Sort<T>(arr, len) {}
    virtual ~InsertSort() = default;

    void sort() override;
protected:
    using Sort<T>::arr_;
    using Sort<T>::len_;
};

template <class T>
class ShellSort: public Sort<T>
{
public:
    ShellSort(T arr[], int len): Sort<T>(arr, len) {}
    virtual ~ShellSort() = default;

    void sort() override;
protected:
    using Sort<T>::arr_;
    using Sort<T>::len_;
};

template <class T>
class BubbleSort: public Sort<T>
{
public:
    BubbleSort(T arr[], int len): Sort<T>(arr, len) {}
    virtual ~BubbleSort() = default;

    void sort() override;
protected:
    using Sort<T>::arr_;
    using Sort<T>::len_;
};

template <class T>
class QuickSort: public Sort<T>
{
public:
    QuickSort(T arr[], int len): Sort<T>(arr, len) {}
    virtual ~QuickSort() = default;

    void sort() override;
    int partition(int low, int high);
    void quickSort(int low, int high);
protected:
    using Sort<T>::arr_;
    using Sort<T>::len_;
};

template <typename T>
class SelectSort: public Sort<T>
{
public:
    SelectSort(T arr[], int len): Sort<T>(arr, len) {}
    virtual ~SelectSort() = default;

    void sort() override;
protected:
    using Sort<T>::arr_;
    using Sort<T>::len_;
};

template <typename T>
class HeapSort: public Sort<T>
{
public:
    HeapSort(T arr[], int len): Sort<T>(arr, len) {}
    virtual ~HeapSort() = default;

    void buildHeap(int len);
    void heapAdjust(int idx, int len);
    void sort() override;
protected:
    using Sort<T>::arr_;
    using Sort<T>::len_;
};

template <typename T>
class MergeSort: public Sort<T>
{
public:
    MergeSort(T arr[], int len): Sort<T>(arr, len) {}
    virtual ~MergeSort() = default;
    void merge(int l, int mid, int r);
    void mergeSort(int l, int r);
    void sort() override;

protected:
    using Sort<T>::arr_;
    using Sort<T>::len_;
};

#include "Sort.tpp"
#endif // !SORT_H
