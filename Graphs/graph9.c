// BREADTH FIRST SEARCH
// Prints BFS traversal from a given source s for undirected graph

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

void Graph_BFS(Graph *g, int s)
{
    int x = g->v;
    bool visited[x];
    for (int i = 0; i < x; i++)
    {
        visited[i] = false;
    }

    int queue[x];
    int front = 0, rear = 0;

    // Mark the source node as visited and enqueue it
    visited[s] = true;
    queue[rear++] = s;

    while (front != rear)
    {
        s = queue[front++];
        printf("%d ", s);

        struct Node *ptr = g->head[s];
        while (ptr != NULL)
        {
            int t = ptr->dest;
            if (!visited[t])
            {
                visited[t] = true;
                queue[rear++] = t;
            }
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int main()
{
    struct Edge edges[] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 6}, {4, 5}, {5, 6}};
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph *graph = createGraph(edges, n, 7);

    printf("BFS starting from vertex 0: ");
    Graph_BFS(graph, 0);

    printf("BFS starting from vertex 2: ");
    Graph_BFS(graph, 2);
    end(graph);
    return 0;
}