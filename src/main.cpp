#include "Graph.h"
#include "Sort.h"
#include "Array.h"
#include "List.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "KMP.h"
#include "DisjointSet.h"
#include <iostream>
#include <memory>

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

    // Stack
    // Stack<int> st;
    // if(st.isEmpty()) std::cout << "Empty" << std::endl;
    // else std::cout << "Not Empty" << std::endl;
    // st.push(1);
    // st.push(2);
    // st.push(5);
    // if(st.isEmpty()) std::cout << "Empty" << std::endl;
    // else std::cout << "Not Empty" << std::endl;
    // std::cout << st.top() << std::endl;
    // st.pop();
    // std::cout << st.top() << std::endl;
    // std::cout << "Stack size: " << st.size() << std::endl;
    // st.push(7);
    // st.push(8);
    // st.push(9);
    // st.push(10);
    // st.push(11);
    // std::cout << st << std::endl;

    // Deque
    // Deque<int> deque;
    // deque.push_front(1);
    // deque.push_front(2);
    // deque.push_front(3);
    // deque.push_front(4);
    // deque.push_front(5);
    // deque.push_front(6);
    // deque.push_front(7);
    // deque.push_back(9);
    // deque.push_back(0);
    // deque.push_front(8);
    // deque.pop_front();
    // deque.pop_front();
    // deque.pop_front();
    // deque.pop_back();
    // deque.pop_back();
    // std::cout << "front: " << deque.front() << std::endl;
    // std::cout << "back: " << deque.back() << std::endl;
    // std::cout << "size: " << deque.size() << std::endl;
    // std::cout << deque;

    // Queue
    // Queue<int> que;
    // que.push(1);
    // que.push(2);
    // que.push(3);
    // que.push(4);
    // que.push(5);
    // que.push(6);
    // que.push(7);
    // que.push(8);
    // que.pop();
    // que.pop();
    // que.pop();
    // que.pop();
    // std::cout << "front: " << que.front() << std::endl;
    // std::cout << "back: " << que.back() << std::endl;
    // std::cout << "size: " << que.size() << std::endl;
    // std::cout << que;

    // PriorityQueue
    // PriorityQueue<int> pq;
    // pq.push(18);
    // pq.push(2);
    // pq.push(1);
    // pq.push(3);
    // pq.push(5);
    // pq.push(15);
    // pq.push(25);
    // pq.push(7);
    // pq.push(9);
    // pq.push(6);
    // pq.push(11);
    // pq.push(18);
    // pq.push(13);
    // pq.push(0);
    // pq.pop();
    // pq.pop();
    // pq.pop();
    // pq.pop();
    // std::cout << "top: " << pq.top() << std::endl;
    // std::cout << "size: " << pq.size() << std::endl;
    // std::cout << pq << std::endl;
    
    // KMP
    // kmp("ABABABC", "ABA");

    // DisJoint Set
    // menu(); // 1 for join, 2 for inquire

    // Prim
    // prim();
    return 0;
}