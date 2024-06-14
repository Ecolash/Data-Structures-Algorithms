// GRAPH CONSTRUCTION FROM USER INPUT (ADJACENCY LIST VERSION)

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
    int src;
    int dest;
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
        int src = edges[i].src;
        int dest = edges[i].dest;
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new->dest = dest;

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
            printf(" %d", ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Edge edges[] = {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}};
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph *graph = createGraph(edges, n, 7);
    printGraph(graph);
    end(graph);
    return 0;
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
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

void DFS(Graph *g, int s, bool *visited)
{

    visited[s] = true;
    printf("%d ", s);

    struct Node *ptr = g->head[s];
    while (ptr != NULL)
    {
        int t = ptr->dest;
        if (!visited[t])
        {
            DFS(g, t, visited);
        }
        ptr = ptr->next;
    }
}

void Graph_DFS(Graph *g)
{
    int x = g->v;
    bool visited[x];
    for (int i = 0; i < x; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < x; i++)
    {
        if (!visited[i])
        {
            DFS(g, i, visited);
            printf("\n");
        }
    }
}

//-------------------------------------------------------------------

bool DFS(Graph *g, int node, int parent, bool *visited)
{
    visited[node] = true;

    struct Node *ptr = g->head[node];
    while (ptr != NULL)
    {
        int t = ptr->dest;
        if (!visited[t])
        {
            if (DFS(g, t, node, visited))
                return true;
        }

        else if (t != parent)
        {
            return true;
        }

        ptr = ptr->next;
    }
    return false;
}

bool isCyclic(Graph *g)
{
    int x = g->v;
    bool visited[x];
    for (int i = 0; i < x; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < x; i++)
    {
        if (!visited[i])
        {
            if (DFS(g, i, -1, visited))
            {
                printf("YES \n");
                return true;
            }
        }
    }
    printf("NO \n");
    return false;
}

//---------------------------------------------------

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
//---------------------------------------------------

void topological_sort(Graph *g)
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

    while (front != rear)
    {
        int i = queue[front++];
        printf("%d ", i);

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
}

//----------------------------------------------------------------------

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

//-------------------------------------------------------------------

#include <limits.h>
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

int printSolution(int dist[], int n)
{
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
    return 0;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, V);
}
int main()
{
    int graph[V][V] = {{0, 6, 0, 0, 0, 0, 0, 8, 0},
                       {6, 0, 8, 0, 0, 0, 0, 13, 0},
                       {0, 8, 0, 7, 0, 6, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 6, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 13, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(graph, 0);
    return 0;
}