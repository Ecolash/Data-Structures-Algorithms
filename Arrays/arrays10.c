// ARRAYS
// Searching ( Searching an elements in array )
// Binary Search

// It works well only for sorted arrays.

#include <stdio.h>

int binary_search(int arr[], int element, int size)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            printf("The element %d is found at index %d.\n", element, mid);
            return mid;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    // SORTED ARRAY!!
    int arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr_1) / sizeof(int);

    int x;
    binary_search(arr_1, 5, size);
    binary_search(arr_1, 1, size);
    binary_search(arr_1, 10, size);
    binary_search(arr_1, 2, size);
    binary_search(arr_1, 4, size);
    binary_search(arr_1, 6, size);
    binary_search(arr_1, 7, size);
    binary_search(arr_1, 0, size);
    return 0;
}