// LINKED LIST
// INSERTION OF ELEMENT IN A LINKED LIST
// Inserting at the beginning

// Before we code, let’s recall all the cases :

// Inserting at the beginning -> Time complexity : O(1)
// Inserting in between -> Time complexity : O(n)
// Inserting at the end -> Time complexity : O(n)
// Inserting after a given Node -> Time complexity : O(1)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *pointer)
{
    while (pointer != NULL)
    {
        printf("%d\t", pointer->data);
        pointer = pointer->next;
    }
    printf("\n");
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

int main()
{
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    first->data = 7;
    first->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    traversal(first);

    printf("\nLinked list after insertion\n");
    first = insertAtFirst(first, 56);
    traversal(first);

    printf("\nLinked list after insertion\n");
    first = insertAtFirst(first, 60);
    traversal(first);

    return 0;
}
