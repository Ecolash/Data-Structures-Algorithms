// CIRCULAR LINKED LIST
// INSERTION OF ELEMENT IN A CIRCULAR LINKED LIST
// Inserting after a given node

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *p = head;
    while (p->next != head)
    {
        printf("Element: %d \n", p->data);
        p = p->next;
    }
    printf("Element: %d \n", p->data);
}

struct Node *insertAfterNode(struct Node *head, struct Node *node_name, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = node_name->next;
    node_name->next = ptr;
    return head;
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
    fourth->next = first;

    printf("Circular Linked list before insertion\n");
    traversal(first);

    first = insertAfterNode(first, first, 54);
    first = insertAfterNode(first, second, 58);
    first = insertAfterNode(first, third, 59);

    printf("\nCircular Linked list after insertion\n");
    traversal(first);
    return 0;
}