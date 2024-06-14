// MEDIAN OF TWO SORTED ARRAYS

#include <stdio.h>
#include <math.h>
#include <limits.h>

double findMedianSortedArrays(int *nums1, int m, int *nums2, int n)
{
    if (m > n)
        return findMedianSortedArrays(nums2, n, nums1, m);

    int l = 0;
    int r = m;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int mid2 = (m + n + 1) / 2 - mid;

        int left1 = ((mid <= 0) ? INT_MIN : nums1[mid - 1]);
        int left2 = ((mid2 <= 0) ? INT_MIN : nums2[mid2 - 1]);

        int right1 = ((mid >= m) ? INT_MAX : nums1[mid]);
        int right2 = ((mid2 >= n) ? INT_MAX : nums2[mid2]);

        if (left2 <= right1 && left1 <= right2)
        {
            if ((m + n) % 2 == 0)
            {
                double x = (double)fmax(left1, left2);
                double y = (double)fmin(right1, right2);
                return (x + y) / 2;
            }

            else
            {
                double x = (double)fmax(left1, left2);
                return x;
            }
        }
        else if (left1 > right2)
            r = mid - 1;

        else if (left2 > right1)
            l = mid + 1;
    }
    return 0.0;
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

    int x;

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

    printf(" \nMedian of two arrays: %0.1f", findMedianSortedArrays(arr1, m, arr2, n));
    return 0;
}