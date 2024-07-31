#include <iostream>
using namespace std;

void InsertSort(int arr[], int len)
{
    int i, j;
    for(i = 1; i < len; i++){
        int tmp = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > tmp; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}

void ShellSort(int arr[], int len)
{
    int i, j;
    for(int dk = len / 2; dk >= 1; dk /= 2){
        for(i = dk; i < len; i++){
            int tmp = arr[i];
            for(j = i - dk; j >= 0 && arr[j] > tmp; j -= dk){
                arr[j + dk] = arr[j];
            }
            arr[j + dk] = tmp;
        }
    }
}

int main()
{
    int arr[] = {1, 21, 13, 6, 9, 25, 3, 17, 10, 28};

    // InsertSort(arr, 10);
    ShellSort(arr, 10);
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}