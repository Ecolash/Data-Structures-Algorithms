// STACK
// Creating A stack

// This is a static stack

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int main()
{
    struct stack S;
    S.size = 80;
    S.top = -1;
    S.arr = (int *)malloc(S.size * sizeof(int));
    return 0;
}