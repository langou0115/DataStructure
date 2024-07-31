#include "Sort.h"
#include "Algorithm.h"

template <class T>
Sort<T>::Sort(T arr_[], int len_): len(len_) 
{
    arr = new T[len];
    for(int i = 0; i < len; i++){
        arr[i] = arr_[i];
    }
}

template <class T>
void InsertSort<T>::sort()
{
    std::cout << "This is InsertSort" << std::endl;
    int i, j;
    for(i = 1; i < len; i++){
        T tmp = arr[i];
        for(j = i - 1; arr[j] > tmp && j >= 0; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}

template <class T>
void ShellSort<T>::sort()
{
    std::cout << "This is ShellSort" << std::endl;
    int dk, i, j;
    for(dk = this->len / 2; dk >= 1; dk /= 2){
        for(i = dk; i < len; i++){
            if(arr[i] < arr[i - dk]){
                T tmp = arr[i];
                for(j = i - dk; j >= 0 && arr[j] > tmp; j -= dk){
                    arr[j + dk] = arr[j];
                }
                arr[j + dk] = tmp;
            }
        }
    }
}

template <class T>
void BubbleSort<T>::sort()
{
    int i, j;
    for(int i = 0; i < len; i++){
        bool flag = false;
        for(int j = len - 1; j > i; j--){
            if(arr[j] < arr[j - 1]){
                my_swap(arr[j], arr[j - 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

template <class T>
int QuickSort<T>::partition(int low, int high)
{
    T pivot = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= pivot) high--;
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot) low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

template <class T>
void QuickSort<T>::quickSort(int low, int high)
{
    if(low < high)
    {
        int pivotpos = partition(low, high);
        quickSort(low, pivotpos - 1);
        quickSort(pivotpos + 1, high);
    }
}


template <class T>
void QuickSort<T>::sort()
{
    int low = 0, high = len - 1;
    quickSort(low, high);
}

template <class T>
void SelectSort<T>::sort()
{
    for(int i = 0; i < len; i++){
        int min = i;
        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[min]) min = j;
        }
        if(min != i) my_swap(arr[min], arr[i]);
    }
}

template <class T>
void HeapSort<T>::buildHeap(int len_)
{
    for(int i = len_ / 2 - 1; i >= 0; i--){
        heapAdjust(i, len_);
    }
}

template <class T>
void HeapSort<T>::heapAdjust(int idx, int len_)
{
    T tmp = arr[idx];
    for(int i = 2 * idx; i < len_; i*=2){
        if(i < len_ && arr[i] < arr[i + 1]) i++;
        if(tmp > arr[i]) break;
        else{
            arr[idx] = arr[i];
            idx = i;
        }
    }
    arr[idx] = tmp;
}

template <class T>
void HeapSort<T>::sort()
{
    buildHeap(len);
    for(int i = len - 1; i > 0; i--){
        my_swap(arr[i], arr[0]);
        heapAdjust(0, i - 1);
    }
}

template <class T>
void MergeSort<T>::merge(int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    T larr[n1], rarr[n2];
    for(int i = 0; i < n1; i++) larr[i] = arr[l + i];
    for(int i = 0; i < n2; i++) rarr[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(rarr[j] > larr[i]) arr[k++] = larr[i++];
        else arr[k++] = rarr[j++];
    }
    while(i < n1) arr[k++] = larr[i++];
    while(j < n2) arr[k++] = rarr[j++];
}

template <class T>
void MergeSort<T>::mergeSort(int l, int r)
{
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, r);
    }
}

template <class T>
void MergeSort<T>::sort()
{
    mergeSort(0, len - 1);
}