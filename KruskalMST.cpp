#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edges;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edges = new Edge[E];
    return graph;
};

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

int Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge*)a;
    struct Edge *b1 = (struct Edge*)b;

    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge results[V];
    int e = 0;
    int i = 0;

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), myComp);
    struct subset *subsets = (struct subset*) malloc(V*sizeof(struct subset));
    for(int v=0; v<V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while(e<V-1)
    {
        struct Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if(x!=y)
        {
            results[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Followings are the edges in the constructed MST\n");
    for(i=0; i<e; i++)
    {
        printf("%d--%d == %d\n", results[i].src, results[i].dest, results[i].weight);
    }
    return;
}

int main()
{
    int V = 4; 
    int E = 5;
    struct Graph *graph = createGraph(V, E);

    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    KruskalMST(graph);
    
    return 0;
}