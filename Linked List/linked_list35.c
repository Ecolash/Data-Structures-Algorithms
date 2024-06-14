// DELETE NTH NODE FROM LAST

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertNode(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void traverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

struct Node *deleteNthFromEnd(struct Node *head, int n)
{
    struct Node *p = head, *q = head;
    for (int i = 0; i < n; i++)
        p = p->next;
    if (p == NULL)
        return head->next;

    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    q->next = q->next->next;
    return head;
}

int main()
{
    struct Node *head1 = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the data for each node:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        head1 = insertNode(head1, data);
    }

    printf("Linked list: ");
    traverse(head1);

    int cont = 1;

    while (cont == 1)
    {
        printf("Enter the value of n to delete nth node from last: ");
        scanf("%d", &n);

        head1 = deleteNthFromEnd(head1, n);
        traverse(head1);

        printf("1 to continue , 0 to stop: ");
        scanf("%d", &cont);
    }

    return 0;
}
