// Fractional Knapsack Problem

// Weights and profits of N items, in the form of {profit, weight}
// Put these items in a knapsack of capacity W to get the max total profit in the knapsack.

#include <stdio.h>

struct Item
{
    int value;
    int weight;
};

void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortByRatio(struct Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            double ratio1 = (double)items[j].value / items[j].weight;
            double ratio2 = (double)items[maxIndex].value / items[maxIndex].weight;
            if (ratio1 > ratio2)
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            swap(&items[i], &items[maxIndex]);
        }
    }
}

double fractionalKnapsack(struct Item items[], int n, int capacity)
{
    sortByRatio(items, n);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
        {
            break;
        }
        if (items[i].weight <= capacity)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            totalValue += (double)items[i].value * capacity / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in the knapsack = %.2lf\n", maxValue);

    return 0;
}
