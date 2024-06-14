// SHORTEST PATH IN DIRECTED ACYCLIC WEIGHTED GRAPH

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define N 100

typedef struct
{
    int v;
    struct Node *head[N];
} Graph;

struct Node
{
    int dest;
    int weight;
    struct Node *next;
};

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

struct Edge
{
    int src;
    int dest;
    int weight;
};

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
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new->dest = dest;
        new->weight = weight;
        new->next = graph->head[src];
        graph->head[src] = new;
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
            printf(" %d (%d)", ptr->dest, ptr->weight);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int ShortestPath(Graph *g, int src, int destn)
{
    struct stack *S;
    int x = g->v;

    S->size = x;
    S->top = -1;
    S->arr = (int *)malloc(x * sizeof(int));

    bool visited[x];
    int distance[x];

    for (int i = 0; i < x; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    for (int j = 0; j < x; j++)
    {
        if (!visited[j])
        {
            DFS(g, j, visited, S);
        }
    }

    distance[src] = 0;
    while (!isEmpty(S))
    {
        int top = pop(S);
        struct Node *ptr = g->head[top];
        if (distance[top] != INT_MAX)
        {
            while (ptr != NULL)
            {
                int d = ptr->dest;
                int curr = distance[top] + ptr->weight;
                distance[d] = fmin(distance[d], curr);
                ptr = ptr->next;
            }
        }
    }

    int ans = distance[destn];
    return ans;
}

int main()
{
    struct Edge edges[] = {{0, 1, 2}, {0, 2, 10}, {1, 2, 4}, {2, 3, 4}, {1, 3, 20}, {2, 4, 10}, {3, 5, 2}, {4, 5, 12}};
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph *graph = createGraph(edges, n, 6);

    printGraph(graph);

    printf("Shortest path between 0 and 5 is: %d \n", ShortestPath(graph, 0, 4));

    // printf("Shortest path between 3 and 1 is: %d \n", ShortestPath(graph, 3, 1));

    return 0;
}
