// ARRAYS
// Traversal ( visiting the elements in array (and do something))

#include <stdio.h>

void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        printf("\t");
    }
    printf("\n");
}

int main()
{
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(arr, 10);
    display(arr, 5);
    return 0;
}