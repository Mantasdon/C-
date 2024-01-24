#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "nd3.h"
using namespace std;

template <typename T>
void bubble_sort(vector<T>& arr){
    T temp;
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr.at(i) > arr.at(j))
            {
                temp = arr.at(i);
                arr.at(i) = arr.at(j);
                arr.at(j) = temp;
            }
        }
    }
}
template <typename T>
T partition(vector<T> arr, int start, int end)
{

    T pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}
template <typename T>
void quickSort(vector<T> arr, int start, int end)
{

    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}
int main(){
    vector<int> myVector;
    srand((unsigned)time(NULL));
    int a = 10;
    cout<<"array before sorting"<<endl;
    for (int i =0; i < a; i++){
        int b = rand() % 20 + 1;
        myVector.push_back(b);
        cout << myVector[i] << endl;
    }

    cout<<"array after bubble sort"<<endl;
   // bubble_sort<int>(myVector);
    for (int i =0; i < a; i++){
        cout << myVector[i] << endl;
    }
    int n = 10;
    quickSort<int>(myVector, 0, n - 1);
    cout<<"array after quick sort"<<endl;
    for (int i = 0; i < n; i++) {
        cout << myVector[i] << " ";
    }

    return 0;
}
