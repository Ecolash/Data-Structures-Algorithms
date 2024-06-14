// KADANE'S ALGORITHM TO CHECK IF THERE EXIST A SUBARRAY WITH SUM 0

#include <stdio.h>
#include <stdbool.h>

bool subarrayWithSumZero(int arr[], int size)
{
    int sum = 0;
    int prefix = 0;

    for (int i = 0; i < size; i++)
    {
        prefix += arr[i];
        if (prefix == 0 || sum == prefix)
        {
            return true;
        }
        sum = prefix;
    }

    return false;
}

int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (subarrayWithSumZero(arr, size))
    {
        printf("Subarray with sum 0 exists.\n");
    }
    else
    {
        printf("No subarray with sum 0 exists.\n");
    }

    return 0;
}
