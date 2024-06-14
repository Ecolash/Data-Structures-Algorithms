#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(int arr[], int size, int pos)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; ++i)
    {
        count[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; ++i)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i)
    {
        count[(arr[i] / pos) % 10]--;
        output[count[(arr[i] / pos) % 10]] = arr[i];
    }

    for (int i = 0; i < size; ++i)
        arr[i] = output[i];
}

void radixSort(int arr[], int size)
{
    int i = 1;
    int max = *max_element(arr, arr + size);

    cout << "----------------------------------------------------------------------------" << endl;
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        countSort(arr, size, pos);
        cout << "Pass " << i << ": ";
        printArray(arr, size);
        i++;
    }
    cout << "----------------------------------------------------------------------------" << endl;
}

int main()
{
    int arr[] = {170, 415, 7005, 900, 802, 24, 2, 66, 1000, 9841, 625, 33, 44, 999, 2465};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, size);

    radixSort(arr, size);
    cout << "Sorted array: ";

    printArray(arr, size);
    return 0;
}
