// TOPOLOGICAL SORT (Using DFS)
// For DAG (Directed Acyclic Graphs)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

typedef struct
{
    int v;
    struct Node *head[N];
} Graph;

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    int x = (ptr->top == -1) ? 1 : 0;
    return x;
};

void push(struct stack *ptr, int val)
{
    ptr->top++;
    ptr->arr[ptr->top] = val;
}

int pop(struct stack *ptr)
{
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

struct Node
{
    int dest;
    struct Node *next;
};

struct Edge
{
    int P1;
    int P2;
};

void end(Graph *g) { free(g); }

Graph *createGraph(struct Edge edges[], int n, int v)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->v = v;

    for (int i = 0; i < v; i++)
    {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        int P1 = edges[i].P1;
        int dest = edges[i].P2;
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new->dest = dest;

        new->next = graph->head[P1];
        graph->head[P1] = new;
    }

    return graph;
}

void printGraph(Graph *graph)
{
    int v = graph->v;
    for (int i = 0; i < v; i++)
    {
        struct Node *ptr = graph->head[i];
        printf("%d ->", i);
        while (ptr != NULL)
        {
            printf(" %d", ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void DFS(Graph *g, int s, bool *visited, struct stack *S)
{
    visited[s] = true;

    struct Node *ptr = g->head[s];
    while (ptr != NULL)
    {
        int t = ptr->dest;
        if (!visited[t])
        {
            DFS(g, t, visited, S);
        }
        ptr = ptr->next;
    }

    push(S, s);
}

void topological_sort(Graph *g)
{
    int x = g->v;
    bool visited[x];

    for (int i = 0; i < x; i++)
    {
        visited[i] = false;
    }

    struct stack *S;
    S->size = x;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));

    for (int i = 0; i < x; i++)
    {
        if (!visited[i])
        {
            DFS(g, i, visited, S);
        }
    }

    while (!isEmpty(S))
    {
        int x = pop(S);
        printf("%d ", x);
    }
}

int main()
{
    struct Edge edges[] = {{5, 1}, {4, 6}, {1, 2}, {1, 3}, {3, 4}, {2, 6}, {4, 0}, {6, 0}};
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph *graph = createGraph(edges, n, 7);

    printf("\nTopological Sort of Directed Acyclic Graph: ");
    topological_sort(graph);
    end(graph);
    return 0;
}