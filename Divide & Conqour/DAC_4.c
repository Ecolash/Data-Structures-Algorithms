// Kth ELEMENT IN TWO ARRAY

#include <stdio.h>
#include <math.h>

int findK(int *nums1, int m, int *nums2, int n, int k)
{
    if (k > m + n)
    {
        printf("Out of Bounds \n");
        return 0;
    }

    if (m > n)
        return findK(nums2, n, nums1, m, k);

    int l = 0;
    int r = fmin(k, m);

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int mid2 = k - mid;

        int left1 = ((mid <= 0) ? -10000 : nums1[mid - 1]);
        int left2 = ((mid2 <= 0) ? -10000 : nums2[mid2 - 1]);

        int right1 = ((mid >= m) ? +10000 : nums1[mid]);
        int right2 = ((mid2 >= n) ? +10000 : nums2[mid2]);

        if (left2 <= right1 && left1 <= right2)
            return fmax(left1, left2);

        else if (left1 > right2)
            r = mid - 1;

        else if (left2 > right1)
            l = mid + 1;
    }
    return 0;
}

int main()
{
    int m, n;
    printf("Enter size of first array: ");
    scanf("%d", &m);

    printf("Enter size of second array: ");
    scanf("%d", &n);

    int arr1[m];
    int arr2[n];

    int x, k;

    printf("Enter elements of first array: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        arr1[i] = x;
    }

    printf("Enter elements of second array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        arr2[i] = x;
    }

    printf("Enter element to find: ");
    scanf("%d", &k);

    printf(" \nKth element of two arrays: %d", findK(arr1, m, arr2, n, k));
    return 0;
}