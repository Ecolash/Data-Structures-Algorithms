#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *link;
};

int main()
{
    struct stack *top; // Top is similar to head of linked list
    top = NULL;
    return 0;
}