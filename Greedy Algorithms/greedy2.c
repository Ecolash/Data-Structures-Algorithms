// ACTIVITY SELECTION PROBLEM

#include <stdio.h>
#include <stdlib.h>

struct Activity
{
    int start;
    int finish;
};

void bubbleSort(struct Activity activities[], int n)
{
    int swap;
    for (int i = 0; i < n - 1; i++)
    {
        swap = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (activities[j].finish > activities[j + 1].finish)
            {
                // Swap activities[j] and activities[j + 1]
                struct Activity temp = activities[j];
                activities[j] = activities[j + 1];
                activities[j + 1] = temp;
                swap = 1;
            }
        }

        // If no two elements were swap in the inner loop, the array is already sorted
        if (swap == 0)
        {
            break;
        }
    }
}

void printSelectedActivities(struct Activity activities[], int n)
{
    bubbleSort(activities, n);
    printf("(%d, %d) ", activities[0].start, activities[0].finish);
    int i, j;
    int count = 1;
    for (i = 1, j = 0; i < n; i++)
    {
        if (activities[i].start >= activities[j].finish)
        {
            printf("(%d, %d) ", activities[i].start, activities[i].finish);
            count++;
            j = i;
        }
    }
    printf("Maximum activities that can be accomodated: %d", count);
}

int main()
{
    struct Activity activities[] = {{1, 3}, {2, 4}, {3, 5}, {5, 7}, {8, 9}, {9, 10}};
    int n = sizeof(activities) / sizeof(activities[0]);
    printSelectedActivities(activities, n);
    return 0;
}
