// SKYLINE PROBLEM

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct building
{
    int l;
    int h;
    int r;
};

struct strip
{
    int l;
    int h;
};

struct strip *merge(struct strip *left, struct strip *right, int m, int n, int *merge_size)
{
    struct strip *merged = (struct strip *)malloc((m + n) * sizeof(struct strip));

    int i = 0, j = 0, k = 0;
    int h1 = 0, h2 = 0;

    while (i < m && j < n)
    {
        if (left[i].l < right[j].l)
        {
            merged[k].l = left[i].l;
            merged[k].h = fmax(left[i].h, h2);
            h1 = left[i].h;
            i++;
        }

        else if (left[i].l > right[j].l)
        {
            merged[k].l = right[j].l;
            merged[k].h = fmax(right[j].h, h1);
            h2 = right[j].h;
            j++;
        }

        else if (left[i].l == right[j].l)
        {
            merged[k].l = left[i - 1].l;
            merged[k].h = fmax(left[i].h, right[j].h);
            h1 = left[i].h;
            h2 = right[j].h;
            i++;
            j++;
        }
        k++;
    }

    while (i < m)
    {
        merged[k] = left[i];
        i++;
        k++;
    }

    while (j < n)
    {
        merged[k] = right[j];
        j++;
        k++;
    }

    *merge_size = k;
    return merged;
}

struct strip *divide(struct building *arr, int l, int r, int *size)
{
    if (l == r)
    {
        struct strip *ans = (struct strip *)malloc(2 * sizeof(struct strip));

        ans[0].h = arr[l].h;
        ans[0].l = arr[l].l;
        ans[1].h = 0;
        ans[1].l = arr[l].r;

        *size = 2;
        return ans;
    }

    int m = l + (r - l) / 2;
    int left_size;
    int right_size;

    struct strip *left = divide(arr, l, m, &left_size);
    struct strip *right = divide(arr, m + 1, r, &right_size);

    int merge_size;
    struct strip *ans = merge(left, right, left_size, right_size, &merge_size);
    free(left);
    free(right);

    *size = merge_size;
    return ans;
}

int main()
{
    printf("Enter no of buildings: ");
    int n;

    scanf("%d", &n);

    struct building B[n];
    for (int i = 0; i < n; i++)
    {
        printf("B[%d] L H R : ", i + 1);
        scanf("%d", &(B[i].l));
        scanf("%d", &(B[i].h));
        scanf("%d", &(B[i].r));
    }

    int size;
    struct strip *skyline = divide(B, 0, n - 1, &size);

    int h0 = -1;
    for (int i = 0; i < size; i++)
    {
        if (h0 != skyline[i].h)
        {
            printf(" (%d, %d)", skyline[i].l, skyline[i].h);
            h0 = skyline[i].h;
        }
    }
    free(skyline);
    return 0;
}