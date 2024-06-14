// MEDIAN OF ARRAY WITHOUT SORTING

#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int l, int r, int i)
{
    int pivot = arr[l];
    int start = l;
    int end = r;

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            int t = arr[start];
            arr[start] = arr[end];
            arr[end] = t;
        }
    }

    int a = arr[l];
    arr[l] = arr[end];
    arr[end] = a;

    return end;
}

int find_index(int arr[], int l, int r, int i)
{
    if (l == r)
        return arr[l];

    int x = partition(arr, l, r, i); // i is the index of pivot after partitioning

    if (i == x)
        return arr[i];

    if (x > i)
        find_index(arr, l, x - 1, i);

    else
        find_index(arr, x + 1, r, i);
}

int main()
{
    int arr[] = {1, 5, 4, 7, 8, 9, 4, 3, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    printf("Median of array: ");

    if (size % 2 == 1)
        printf("%d\n", find_index(arr, 0, size - 1, size / 2));

    else
        printf("%f\n", (float)((find_index(arr, 0, size - 1, size / 2) + find_index(arr, 0, size - 1, size / 2 - 1)) / 2.0));

    return 0;
}
