// QUICK SORT

#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int l, int r)
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

    printf("Original array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
