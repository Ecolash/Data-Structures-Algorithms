#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i) // Last element will be automatically sorted
    {
        int maxIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }

        swap(arr[maxIndex], arr[i]);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 10, 2, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    selectionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}