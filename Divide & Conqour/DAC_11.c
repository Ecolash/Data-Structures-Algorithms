// FIND K, cyclically right-shifting sorted array A by some k cells

#include <stdio.h>

int find_shift(int A[], int l, int r)
{
    while (1)
    {
        int m = (l + r) / 2;

        if ((A[m - 1] < A[m]) && (A[m] > A[m + 1]))
            return m + 1;

        if ((A[m - 1] > A[m]) && (A[m] < A[m + 1]))
            return m;

        if (A[m] > A[0])
            l = m + 1;

        else
            r = m - 1;
    }
}

int main()
{
    int arr[] = {7, 8, 9, 1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Circular shift of array: ");
    printf("%d\n", find_shift(arr, 0, size - 1));

    return 0;
}
