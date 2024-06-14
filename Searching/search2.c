// BINARY SEARCH

#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int size;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements in sorted order:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found.\n");
    }

    return 0;
}
