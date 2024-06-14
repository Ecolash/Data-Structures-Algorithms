#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1; // (int i will store index of partition.. assuming partition to be before element at index l)

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }

    // Bringing pivot to index of partition ( pivot is same as arr[r] )

    i = i + 1;
    swap(arr[i], arr[r]);
    return i;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int i = partition(arr, l, r); // i is the index of pivot after partitioning
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
}

int main()
{
    int arr[] = {14, 25, 12, 22, 11, 32, 64, 41};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
