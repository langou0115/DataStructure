#include "Algorithm.h"
#include "PriorityQueue.h"

template <class T>
void PriorityQueue<T>::push(T item)
{
    arr.push_back(item);
    int idx = arr.size() - 1; // last item
    while(idx >= 0){
        int fa = (idx - 1) / 2;
        if(arr[idx] >= arr[fa]){
            break;
        }else{
            my_swap(arr[idx], arr[fa]);
            idx = fa;
        }
    }
}

template <class T>
void PriorityQueue<T>::pop()
{
    if (arr.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    my_swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    int idx = 0;
    while(idx < arr.size()){
        int child = 2 * idx + 1;
        if(child >= arr.size()) break;
        if(child + 1 < arr.size() && arr[child + 1] < arr[child]) child++;
        if(arr[idx] > arr[child]){
            my_swap(arr[idx], arr[child]);
            idx = child;
        }else{
            break;
        }
    }
}