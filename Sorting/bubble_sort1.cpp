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

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        cout << "<< " << i << " >>  ";
        printArray(arr, size);
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 35, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);

    cout << endl;
    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
