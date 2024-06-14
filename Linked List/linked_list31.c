// Count number of nodes in linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int count(struct Node *head)
{
    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
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

    printf("The number of nodes in linked list is %d", count(N1));
    return 0;
}