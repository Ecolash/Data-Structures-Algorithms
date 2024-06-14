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

int *countSort(int arr[], int size, int k)
{
    int count[k + 1] = {0};
    int *result = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; ++i)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i)
    {
        count[arr[i]]--;
        result[count[arr[i]]] = arr[i];
    }

    return result;
}

int main()
{
    int arr[] = {0, 1, 2, 5, 4, 3, 4, 2, 5, 1, 2, 2, 2, 6, 1, 1, 3, 5, 1, 5, 0, 0, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, size);

    int *res = countSort(arr, size, 6);
    cout << "Sorted array: ";

    printArray(res, size);
    return 0;
}
