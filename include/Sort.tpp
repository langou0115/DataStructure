#include "Sort.h"
#include "Algorithm.h"

template <class T>
Sort<T>::Sort(T arr[], int len): len_(len) 
{
    arr_ = new T[len_];
    for(int i = 0; i < len_; i++){
        arr_[i] = arr[i];
    }
}

template <class T>
void InsertSort<T>::sort()
{
    std::cout << "This is InsertSort" << std::endl;
    int i, j;
    for(i = 1; i < len_; i++){
        T tmp = arr_[i];
        for(j = i - 1; arr_[j] > tmp && j >= 0; j--){
            arr_[j + 1] = arr_[j];
        }
        arr_[j + 1] = tmp;
    }
}

template <class T>
void ShellSort<T>::sort()
{
    std::cout << "This is ShellSort" << std::endl;
    int dk, i, j;
    for(dk = len_ / 2; dk >= 1; dk /= 2){
        for(i = dk; i < len_; i++){
            if(arr_[i] < arr_[i - dk]){
                T tmp = arr_[i];
                for(j = i - dk; j >= 0 && arr_[j] > tmp; j -= dk){
                    arr_[j + dk] = arr_[j];
                }
                arr_[j + dk] = tmp;
            }
        }
    }
}

template <class T>
void BubbleSort<T>::sort()
{
    std::cout << "This is BubbleSort" << std::endl;
    int i, j;
    for(int i = 0; i < len_; i++){
        bool flag = false;
        for(int j = len_ - 1; j > i; j--){
            if(arr_[j] < arr_[j - 1]){
                my_swap(arr_[j], arr_[j - 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

template <class T>
int QuickSort<T>::partition(int low, int high)
{
    T pivot = arr_[low];
    while(low < high)
    {
        while(low < high && arr_[high] >= pivot) high--;
        arr_[low] = arr_[high];
        while(low < high && arr_[low] <= pivot) low++;
        arr_[high] = arr_[low];
    }
    arr_[low] = pivot;
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
    std::cout << "This is QuickSort" << std::endl;
    int low = 0, high = len_ - 1;
    quickSort(low, high);
}

template <class T>
void SelectSort<T>::sort()
{
    std::cout << "This is SelectSort" << std::endl;
    for(int i = 0; i < len_; i++){
        int min = i;
        for(int j = i + 1; j < len_; j++){
            if(arr_[j] < arr_[min]) min = j;
        }
        if(min != i) my_swap(arr_[min], arr_[i]);
    }
}

template <class T>
void HeapSort<T>::buildHeap(int len)
{
    for(int i = len / 2 - 1; i >= 0; i--){
        heapAdjust(i, len);
    }
}

template <class T>
void HeapSort<T>::heapAdjust(int idx, int len)
{
    T tmp = arr_[idx];
    for(int i = 2 * idx; i < len; i*=2){
        if(i < len && arr_[i] < arr_[i + 1]) i++;
        if(tmp > arr_[i]) break;
        else{
            arr_[idx] = arr_[i];
            idx = i;
        }
    }
    arr_[idx] = tmp;
}

template <class T>
void HeapSort<T>::sort()
{
    std::cout << "This is HeapSort" << std::endl;
    buildHeap(len_);
    for(int i = len_ - 1; i > 0; i--){
        my_swap(arr_[i], arr_[0]);
        heapAdjust(0, i - 1);
    }
}

template <class T>
void MergeSort<T>::merge(int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    T larr[n1], rarr[n2];
    for(int i = 0; i < n1; i++) larr[i] = arr_[l + i];
    for(int i = 0; i < n2; i++) rarr[i] = arr_[mid + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(rarr[j] > larr[i]) arr_[k++] = larr[i++];
        else arr_[k++] = rarr[j++];
    }
    while(i < n1) arr_[k++] = larr[i++];
    while(j < n2) arr_[k++] = rarr[j++];
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
    std::cout << "This is MergeSort" << std::endl;
    mergeSort(0, len_ - 1);
}