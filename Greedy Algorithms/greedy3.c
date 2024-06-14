// Interval partitioning

// Find min number of classrooms to schedule all lectures so that no two occur at the same time in the same room.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Interval
{
    int start;
    int end;
};

void bubbleSort(struct Interval intervals[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (intervals[j].start > intervals[j + 1].start)
            {
                struct Interval temp = intervals[j];
                intervals[j] = intervals[j + 1];
                intervals[j + 1] = temp;
            }
        }
    }
}

int intervalPartitioning(struct Interval intervals[], int n)
{
    bubbleSort(intervals, n);

    int class = 0;
    int isOccupied[n];
    memset(isOccupied, 0, n);

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < class; j++)
        {
            if (isOccupied[j] <= intervals[i].start)
            {
                isOccupied[j] = intervals[i].end;
                break;
            }
        }

        if (j == class)
        {
            isOccupied[class] = intervals[i].end;
            class ++;
        }
    }
    return class;
}

int main()
{
    struct Interval intervals[] = {{1, 3}, {5, 9}, {2, 4}, {7, 11}, {2, 9}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    int minClass = intervalPartitioning(intervals, n);
    printf("%d\n", minClass);
    return 0;
}
