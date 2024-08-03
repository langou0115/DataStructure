#include "Sort.h"
#include "Array.h"
#include "List.h"
#include <iostream>

int main()
{
    // Sort
    // double arr[10] = {1.5, 12.3, 3.9, 5.4, 18.1, 3.3, 7.1, 8.2, 21.3, 19.2};
    // std::unique_ptr<Sort<double>> s(new InsertSort<double>(arr, 10)); // 插入排序
    // std::unique_ptr<Sort<double>> s(new ShellSort<double>(arr, 10)); // 希尔排序
    // std::unique_ptr<Sort<double>> s(new BubbleSort<double>(arr, 10)); // 冒泡排序
    // std::unique_ptr<Sort<double>> s(new QuickSort<double>(arr, 10)); // 快速排序
    // std::unique_ptr<Sort<double>> s(new SelectSort<double>(arr, 10)); // 选择排序
    // std::unique_ptr<Sort<double>> s(new HeapSort<double>(arr, 10)); // 堆排序
    // std::unique_ptr<Sort<double>> s(new MergeSort<double>(arr, 10)); // 归并排序
    // s->sort();
    // s->print();

    // Array
    // Array<int> arr(10);
    // Array<double> arr{1.5, 12.3, 3.9, 5.4, 18.1, 3.3, 7.1, 8.2, 21.3, 19.2};
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.pop_back();
    // arr.insert(0, 3);
    // int tmp = arr.erase(0);
    // arr[0] = 5;
    // std::cout << arr << std::endl;
    // std::cout << "erase: " << tmp << std::endl;
    // std::cout << arr.size();
    
    // List
    // List<int> list;
    // list.push_back(1);
    // list.push_back(2);
    // list.push_front(0);
    // list.push_front(-1);
    // list.pop_front();
    // list.pop_back();
    // list.insert(2, 27);
    // list.insert(2, 14);
    // int tmp = list.erase(3);
    // std::cout << "Erase: " << tmp << std::endl;
    // std::cout << list << std::endl;
    // std::cout << "List Size: "<< list.size() << std::endl;
    return 0;
}