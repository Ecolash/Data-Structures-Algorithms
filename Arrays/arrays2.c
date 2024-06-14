// ARRAYS
// Printing an Array (using malloc)

// We will now create a show function to display all the elements of the struct myArray. Use ((*a).ptr)[i] to access each element.

#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr; // pointer for first data
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

void show(struct myArray *a)
{
    for (int i = 0; i < (*a).used_size; i++)
    {
        printf("%d\n", ((*a).ptr)[i]);
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 5);
    show(&marks);
    return 0;
}
