// KADANE'S ALGORITHM TO FIND MAX SUBARRAY SUM

#include <stdio.h>
#include <math.h>

int kadane(int arr[], int size)
{
    int curr = arr[0];
    int ans = arr[0];

    for (int i = 1; i < size; i++)
    {
        curr = fmax(arr[i], (curr + arr[i]));
        ans = fmax(ans, curr);
    }

    return ans;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max_sum = kadane(arr, size);
    printf("Maximum subarray sum is %d\n", max_sum);

    return 0;
}
