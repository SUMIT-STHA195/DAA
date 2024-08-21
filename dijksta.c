#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int dest;
    int weight;
    struct Edge* next;
};

// Structure to represent a graph
struct Graph {
    int V;
    struct Edge** adjList;
};

// Function to create a new edge
struct Edge* createEdge(int dest, int weight) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

// Function to create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Edge**)malloc(V * sizeof(struct Edge*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Edge* newEdge = createEdge(dest, weight);
    newEdge->next = graph->adjList[src];
    graph->adjList[src] = newEdge;
}

// Function to find the vertex with the minimum distance
int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(struct Graph* graph, int startVertex) {
    int V = graph->V;
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[startVertex] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;

        struct Edge* temp = graph->adjList[u];
        while (temp) {
            int v = temp->dest;
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
            }
            temp = temp->next;
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d        %d\n", i + 1, dist[i]);
    }
}

int main() {
    int V, E, src, dest, weight, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src - 1, dest - 1, weight);
        addEdge(graph, dest - 1, src - 1, weight); // Since the graph is undirected
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dijkstra(graph, startVertex - 1);

    // Free allocated memory
    for (int i = 0; i < V; i++) {
        struct Edge* temp = graph->adjList[i];
        while (temp) {
            struct Edge* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}