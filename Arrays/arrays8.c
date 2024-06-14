// ARRAYS
// Deletion ( Deleting an elements in array (ordered shift))

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

void delete (int arr[], int index, int size)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size = size - 1;
    display(arr, size);
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    delete (arr, 9, size);
    size -= 1;

    delete (arr, 0, size);
    size -= 1;

    delete (arr, 1, size);
    size -= 1;

    delete (arr, 3, size);
    size -= 1;

    delete (arr, 4, size);
    size -= 1;

    delete (arr, 4, size);
    size -= 1;

    delete (arr, 0, size);
    size -= 1;

    delete (arr, 0, size);
    size -= 1;
    return 0;
}