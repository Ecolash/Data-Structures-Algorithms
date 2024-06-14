// Find out whether there is an index i for which A[i] = 2i
// A is sorted and contains distinct even numbers only

#include <stdio.h>

int find_index(int A[], int l, int r)
{
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (A[m] < 2 * m)
            l = m + 1;

        else if (A[m] > 2 * m)
            r = m - 1;

        else
            return m;
    }
    return -1;
}

int main()
{
    int arr[] = {-2, 2, 12, 14, 16, 20, 22};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Index: ");
    printf("%d\n", find_index(arr, 0, size - 1));

    return 0;
}
