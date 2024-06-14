// LINKED LIST
// TRAVERSAL OF A LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function for traversal from input node (pointer) to last node
void traversal(struct Node *pointer)
{
    while (pointer != NULL)
    {
        printf("%d\t", pointer->data);
        pointer = pointer->next;
    }
    printf("\n");
}

int main()
{
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    first->data = 7;
    first->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    // Traversal of linked lists
    traversal(first);
    traversal(second);
    traversal(third);
    traversal(fourth);

    return 0;
}
