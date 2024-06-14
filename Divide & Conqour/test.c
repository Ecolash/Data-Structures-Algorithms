#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int h;
} Point;

Point *merge(Point *left, int leftSize, Point *right, int rightSize, int *mergedSize)
{
    int mergedCapacity = leftSize + rightSize;
    Point *merged = (Point *)malloc(mergedCapacity * sizeof(Point));

    int l = 0, r = 0, m = 0;
    int lh = 0, rh = 0, ch = 0;

    while (l < leftSize && r < rightSize)
    {
        if (left[l].x < right[r].x)
        {
            ch = lh = left[l].h;
            merged[m++] = left[l++];
        }
        else
        {
            ch = rh = right[r].h;
            merged[m++] = right[r++];
        }

        if (ch != merged[m - 1].h)
        {
            merged[m].x = left[l - 1].x;
            merged[m].h = ch;
            m++;
        }
    }

    while (l < leftSize)
    {
        merged[m++] = left[l++];
    }

    while (r < rightSize)
    {
        merged[m++] = right[r++];
    }

    *mergedSize = m;
    return merged;
}

Point *skyline(int **buildings, int left, int right, int *size)
{
    if (left == right)
    {
        Point *result = (Point *)malloc(2 * sizeof(Point));
        result[0].x = buildings[left][0];
        result[0].h = buildings[left][1];
        result[1].x = buildings[left][2];
        result[1].h = 0;
        *size = 2;
        return result;
    }

    int mid = left + (right - left) / 2;
    int leftSize, rightSize;
    Point *leftSkyline = skyline(buildings, left, mid, &leftSize);
    Point *rightSkyline = skyline(buildings, mid + 1, right, &rightSize);

    int mergedSize;
    Point *mergedSkyline = merge(leftSkyline, leftSize, rightSkyline, rightSize, &mergedSize);

    free(leftSkyline);
    free(rightSkyline);

    *size = mergedSize;
    return mergedSkyline;
}

void print(Point *skyline, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("(%d, %d) ", skyline[i].x, skyline[i].h);
    }
    printf("\n");
}

int main()
{
    int num = 5;
    int b[][3] = {
        {2, 9, 10},
        {3, 7, 15},
        {5, 12, 12},
        {15, 20, 10},
        {19, 24, 8}};

    int **bPtrs = (int **)malloc(num * sizeof(int *));
    for (int i = 0; i < num; i++)
    {
        bPtrs[i] = b[i];
    }

    int size;
    Point *skylinePoints = skyline(bPtrs, 0, num - 1, &size);

    print(skylinePoints, size);

    free(bPtrs);
    free(skylinePoints);

    return 0;
}
