// ARRAYS
// Insertion ( inserting an elements in array (ordered shift))

#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        printf("\t");
    }
    printf("\n");
}

void insert(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        printf("Not enough capacity! \n");
    }
    else if (size < capacity)
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        size = size + 1;
        display(arr, size);
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    insert(arr, size, 0, 10, 1);
    size = size + 1;

    insert(arr, size, 5, 10, 0);
    size = size + 1;

    insert(arr, size, 2, 10, 5);
    size = size + 1;

    insert(arr, size, 9, 10, 4);
    size = size + 1;

    insert(arr, size, 6, 10, 6);
    size = size + 1;

    insert(arr, size, 7, 10, 7);
    size = size + 1;
    return 0;
}