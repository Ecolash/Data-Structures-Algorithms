// ARRAYS
// Creating an Array (dynamic array)

// Define the structure elements, integer variables total_size and used_size, and an integer pointer to point at the address of the first element.

#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr; // points the first integer data in the array
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    (*a).total_size = tSize;
    (*a).used_size = uSize;
    (*a).ptr = (int *)malloc(tSize * sizeof(int));

    // Aliter:
    // a->total_size = tSize;
    // a->used_size = uSize;
    // a->ptr = (int *)malloc(tSize * sizeof(int));
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    // An array named marks is created with total size 10
    return 0;
}
