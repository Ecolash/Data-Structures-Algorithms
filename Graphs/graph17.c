// SHORTEST PATH BETWEEN 2 NODES
// Shortest Path in Undirected Graphs

// BREADTH FIRST SEARCH
// Prints BFS traversal from a given source s for directed graph

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

typedef struct
{
    int v;
    struct Node *head[N];
} Graph;

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

        P1 = edges[i].P2;
        dest = edges[i].P1;
        struct Node *new1 = (struct Node *)malloc(sizeof(struct Node));
        new1->dest = dest;

        new1->next = graph->head[P1];
        graph->head[P1] = new1;
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

void Get_Shortest_Path(Graph *g, int s, int d)
{
    int x = g->v;
    bool visited[x];
    int parent[x];

    for (int i = 0; i < x; i++)
    {
        visited[i] = false;
    }

    int queue[x];
    int front = 0, rear = 0;

    visited[s] = true;
    parent[s] = -1;
    queue[rear++] = s;

    while (front != rear)
    {
        int v = queue[front++];
        struct Node *ptr = g->head[v];

        while (ptr != NULL)
        {
            int t = ptr->dest;
            if (!visited[t])
            {
                visited[t] = true;
                parent[t] = v;
                queue[rear++] = t;
            }
            ptr = ptr->next;
        }
    }

    int current = d;
    int ans[x];
    int k = 0;

    while (current != s)
    {
        ans[k++] = current;
        current = parent[current];
    }

    ans[k++] = s;
    for (int i = k - 1; i > 0; i--)
    {
        printf(" %d ->", ans[i]);
    }
    printf(" %d\n", ans[0]);
}

int main()
{
    struct Edge edges[] = {{0, 1}, {0, 2}, {3, 0}, {3, 6}, {1, 5}, {7, 4}, {7, 5}, {4, 6}};
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph *graph = createGraph(edges, n, 8);

    printf("Shortest Path: ");
    Get_Shortest_Path(graph, 0, 7);
    end(graph);
    return 0;
}