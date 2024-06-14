// MERGE TWO SORTED LIST

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
    printf("NULL\n");
}

struct Node *mergeTwoLists(struct Node *list1, struct Node *list2)
{
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    struct Node *list = NULL;

    if (list1->data <= list2->data)
    {
        list = list1;
        list->next = mergeTwoLists(list1->next, list2);
    }
    else
    {
        list = list2;
        list->next = mergeTwoLists(list1, list2->next);
    }

    return list;
}

struct Node *sortList(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *temp = NULL;
    struct Node *slow = head;
    struct Node *fast = head;

    // (Finding the middle element)
    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;

    struct Node *l1 = sortList(head);
    struct Node *l2 = sortList(slow);
    return mergeTwoLists(l1, l2);
}

int main()
{
    struct Node *head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the data for each node:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        head = insertNode(head, data);
    }

    printf("Linked list (before sort): ");
    traverse(head);

    head = sortList(head);
    printf("Linked list (after sort): ");
    traverse(head);

    return 0;
}
