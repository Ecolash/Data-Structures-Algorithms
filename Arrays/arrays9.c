// ARRAYS
// Searching ( Searching an elements in array )
// Linear Search

// It works well both for sorted array and unsorted arrays.

#include <stdio.h>

void linear_search(int arr[], int element, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("The element %d is found at index %d.\n", element, i);
        }
    }
}

int main()
{
    // SORTED ARRAY!!
    int arr_1[] = {1, 2, 3, 4, 5, 6, 7, 7, 9, 10};
    int size = sizeof(arr_1) / sizeof(int);

    linear_search(arr_1, 5, size);
    linear_search(arr_1, 1, size);
    linear_search(arr_1, 10, size);
    linear_search(arr_1, 2, size);
    linear_search(arr_1, 4, size);
    linear_search(arr_1, 6, size);
    linear_search(arr_1, 7, size);
    linear_search(arr_1, 0, size);
    printf("\n");

    // UNSORRTED ARRAY!!
    int arr_2[] = {10, 2, 4, 3, 6, 7, 1, 9, 10, 2, 3, 5, 7, 9, 1, 0};
    size = sizeof(arr_2) / sizeof(int);

    linear_search(arr_2, 5, size);
    linear_search(arr_2, 1, size);
    linear_search(arr_2, 10, size);
    linear_search(arr_2, 2, size);
    linear_search(arr_2, 4, size);
    linear_search(arr_2, 6, size);
    linear_search(arr_2, 7, size);
    linear_search(arr_2, 0, size);
    printf("\n");
    return 0;
}