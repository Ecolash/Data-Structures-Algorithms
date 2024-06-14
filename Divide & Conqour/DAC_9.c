// Ith PSOITION ELEMENT IF ARRAY WAS SORTED

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
    int arr[] = {
        1,
        3,
        5,
        4,
        2,
        6,
        7,
    };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    int i = 2;
    int x = find_index(arr, 0, size - 1, i);

    printf("Ith PSOITION ELEMENT IF ARRAY WAS SORTED: %d \n", x);
    return 0;
}
