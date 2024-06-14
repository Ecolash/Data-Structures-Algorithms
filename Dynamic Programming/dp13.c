// LONGEST INCREASING SUBSEQUENCE

#include <stdio.h>
#include <math.h>

int lis(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    int maxi = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                lis[i] = fmax(lis[i], lis[j] + 1);
            }
        }
        maxi = fmax(lis[i], maxi);
    }
    return maxi;
}

int main()
{
    int arr[] = {1, 2, 6, 3, 4, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of LIS is %d\n", lis(arr, n));
    return 0;
}
