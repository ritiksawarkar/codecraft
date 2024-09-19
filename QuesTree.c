
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for an adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for the graph
typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src); // For undirected graph
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// DFS function
void DFS(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the vertex as visited
    printf("%d ", vertex); // Print the vertex

    Node* temp = graph->adjList[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Main function
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    // Add edges (example graph)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("Depth-First Search starting from vertex 0:\n");
    int visited[MAX_VERTICES] = {0}; // Array to track visited vertices
    DFS(graph, 0, visited);

    // Free memory (not shown for brevity)

    return 0;
}