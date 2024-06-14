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

struct Node *reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main()
{
    struct Node *N1;
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;
    struct Node *N5;
    struct Node *N6;
    struct Node *N7;
    struct Node *N8;

    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));
    N5 = (struct Node *)malloc(sizeof(struct Node));
    N6 = (struct Node *)malloc(sizeof(struct Node));
    N7 = (struct Node *)malloc(sizeof(struct Node));
    N8 = (struct Node *)malloc(sizeof(struct Node));

    N1->data = 7;
    N1->next = N2;

    N2->data = 11;
    N2->next = N3;

    N3->data = 41;
    N3->next = N4;

    N4->data = 66;
    N4->next = N5;

    N5->data = 7;
    N5->next = N6;

    N6->data = 11;
    N6->next = N7;

    N7->data = 41;
    N7->next = N8;

    N8->data = 66;
    N8->next = NULL;

    traversal(N1);
    N1 = reverse(N1);
    traversal(N1);

    return 0;
}