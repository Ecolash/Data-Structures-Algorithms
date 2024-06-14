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

int *countSort(int arr[], int size)
{

    int *result = (int *)malloc(size * sizeof(int));

    int max_val = *max_element(arr, arr + size);
    int min_val = *min_element(arr, arr + size);
    int k = max_val - min_val;
    int count[k + 1] = {0};

    for (int i = 0; i < size; ++i)
    {
        count[arr[i] - min_val]++;
    }

    for (int i = 1; i <= k; ++i)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i)
    {
        count[arr[i] - min_val]--;
        result[count[arr[i] - min_val]] = arr[i];
    }

    return result;
}

int main()
{
    int arr[] = {0, -1, -2, -5, -2, 6, -1, -1, 3, -5, -4, -3, -4, -2, 5, 1, -2, 2, 2, 6, 1, 1, -3, -5, 1, 5, 0, 0, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, size);

    int *res = countSort(arr, size);
    cout << "Sorted array: ";

    printArray(res, size);
    return 0;
}
