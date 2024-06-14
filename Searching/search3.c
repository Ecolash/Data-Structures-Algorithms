// BINARY SEARCH IN SORTED CIRCULAR ARRAY

#include <stdio.h>

int circularbinarySearch(int *nums, int n, int t)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] == t)
            return m;

        if (nums[l] <= nums[m])
        {
            if (nums[l] <= t && t < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }

        else
        {
            if (nums[m] < t && t <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements in sorted order:", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = circularbinarySearch(arr, size, target);

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
