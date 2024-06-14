// LINKED LIST
// DELETION IN LINKED LIST

// Case 4: Deleting the element by value
// 4(b): Values in the list can be same (deleting all such values) (eg - age)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteByValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        if (q->data != value)
        {
            p = p->next;
            q = q->next;
        }
        if (q->data == value)
        {
            p->next = q->next;
            free(q);
            realloc(q, sizeof(struct Node));
            q = p->next;
        }
    }
    return head;
}

int main()
{
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));

    first->data = 7;
    first->next = second;

    second->data = 11;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 54;
    fourth->next = fifth;

    fifth->data = 19;
    fifth->next = sixth;

    sixth->data = 19;
    sixth->next = seventh;

    seventh->data = 14;
    seventh->next = NULL;

    printf("Linked list before deletion\n");
    traversal(first);

    printf("\nLinked list after deletion\n");
    first = deleteByValue(first, 19);
    traversal(first);

    printf("\nLinked list after deletion\n");
    first = deleteByValue(first, 11);
    traversal(first);

    return 0;
}