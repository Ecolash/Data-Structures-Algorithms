// KADANE'S ALGORITHM TO CHECK IF THERE EXIST A SUBARRAY WITH FLIPPING SUM 0

/*
   Find out if there exists two indices l, r such that 1≤l≤r≤n
   and al+al+2+al+4+⋯+ar=al+1+al+3+⋯+ar−1
   if l and r have the same parity and al+al+2+al+4+⋯+ar−1=al+1+al+3+⋯+ar otherwise.

   Hint : Just flip all even element such that a[i] = -a[i]
   Then it is same as finding a subarray with sum 0
*/

#include <stdio.h>
#include <stdbool.h>

bool subarrayWithSumZero(int arr[], int size)
{
    int sum = 0;
    int prefix = 0;

    for (int i = 0; i < size; i++)
        if (i % 2 == 1)
            arr[i] = -1 * arr[i];

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
    int arr[] = {2, 5, 10, 4, 4, 9, 6, 7, 8};
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
