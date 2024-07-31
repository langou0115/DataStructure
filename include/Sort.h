#ifndef _SORT_H
#define _SORT_H
#include <iostream>

template <class T>
class Sort
{
public:
    Sort(T arr_[], int len_);
    Sort(const Sort &) = delete;
    virtual ~Sort() { delete []arr; }
    virtual void sort() = 0;
    void print()
    {
        for(int i = 0; i < len; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
protected:
    T *arr;
    int len;
};

template <class T>
class InsertSort: public Sort<T>
{
public:
    InsertSort(T arr_[], int len_): Sort<T>(arr_, len_) {}
    virtual ~InsertSort() = default;

    void sort() override;
protected:
    using Sort<T>::arr;
    using Sort<T>::len;
};

template <class T>
class ShellSort: public Sort<T>
{
public:
    ShellSort(T arr_[], int len_): Sort<T>(arr_, len_) {}
    virtual ~ShellSort() = default;

    void sort() override;
protected:
    using Sort<T>::arr;
    using Sort<T>::len;
};

template <class T>
class BubbleSort: public Sort<T>
{
public:
    BubbleSort(T arr_[], int len_): Sort<T>(arr_, len_) {}
    virtual ~BubbleSort() = default;

    void sort() override;
protected:
    using Sort<T>::arr;
    using Sort<T>::len;
};

template <class T>
class QuickSort: public Sort<T>
{
public:
    QuickSort(T arr_[], int len_): Sort<T>(arr_, len_) {}
    virtual ~QuickSort() = default;

    void sort() override;
    int partition(int low, int high);
    void quickSort(int low, int high);
protected:
    using Sort<T>::arr;
    using Sort<T>::len;
};

template <typename T>
class SelectSort: public Sort<T>
{
public:
    SelectSort(T arr_[], int len_): Sort<T>(arr_, len_) {}
    virtual ~SelectSort() = default;

    void sort() override;
protected:
    using Sort<T>::arr;
    using Sort<T>::len;
};

template <typename T>
class HeapSort: public Sort<T>
{
public:
    HeapSort(T arr_[], int len_): Sort<T>(arr_, len_) {}
    virtual ~HeapSort() = default;

    void buildHeap(int len_);
    void heapAdjust(int idx, int len_);
    void sort() override;
protected:
    using Sort<T>::arr;
    using Sort<T>::len;
};

template <typename T>
class MergeSort: public Sort<T>
{
public:
    MergeSort(T arr_[], int len_): Sort<T>(arr_, len_) {}
    virtual ~MergeSort() = default;
    void merge(int l, int mid, int r);
    void mergeSort(int l, int r);
    void sort() override;

protected:
    using Sort<T>::arr;
    using Sort<T>::len;
};

#include "Sort.tpp"
#endif // !SORT_H
