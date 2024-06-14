// CYCLE DETECTION IN DIRECTED GRAPHS
// PRINCIPLE: Invalidity of Topological Sort

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

void isCyclic(Graph *g)
{
    int x = g->v;
    bool visited[x];
    int indegree[x];

    for (int i = 0; i < x; i++)
    {
        visited[i] = false;
        indegree[i] = 0;
    }

    int queue[x];
    int front = 0, rear = 0;

    for (int i = 0; i < x; i++)
    {
        struct Node *ptr = g->head[i];
        while (ptr != NULL)
        {
            int t = ptr->dest;
            indegree[t]++;
            ptr = ptr->next;
        }
    }

    for (int i = 0; i < x; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    int count = 0;
    while (front != rear)
    {
        int i = queue[front++];
        count++;

        struct Node *ptr = g->head[i];
        while (ptr != NULL)
        {
            int t = ptr->dest;
            indegree[t]--;

            if (indegree[t] == 0)
                queue[rear++] = t;

            ptr = ptr->next;
        }
    }

    if (count == x)
        printf("NO \n");
    else
        printf("YES \n");
}

int main()
{
    struct Edge edges[] = {{5, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}, {4, 0}, {6, 0}};
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph *graph = createGraph(edges, n, 7);

    printf("Cycle found in Directed Graph: ");
    isCyclic(graph);
    end(graph);
    return 0;
}