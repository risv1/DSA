#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;


typedef struct {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int inMST[MAX_VERTICES];
} MST;

Graph createGraph(int numVertices) {
    Graph graph;
    graph.numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph.adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph *graph, int u, int v, int weight) {
    graph->adjacencyMatrix[u][v] = graph->adjacencyMatrix[v][u] = weight;
}

int findMinKeyVertex(MST *mst, int numVertices) {
    int minKey = INT_MAX;
    int minVertex;

    for (int v = 0; v < numVertices; v++) {
        if (!mst->inMST[v] && mst->key[v] < minKey) {
            minKey = mst->key[v];
            minVertex = v;
        }
    }

    return minVertex;
}

void printMST(MST *mst, int numVertices) {
    printf("Edge    Weight\n");
    for (int v = 1; v < numVertices; v++) {
        printf("%d - %d    %d\n", mst->parent[v], v, mst->key[v]);
    }
}

void primMST(Graph *graph) {
    int numVertices = graph->numVertices;
    MST mst;
    mst.key[0] = 0;
    mst.parent[0] = -1;
    mst.inMST[0] = 0;

    for (int v = 1; v < numVertices; v++) {
        mst.key[v] = INT_MAX;
        mst.inMST[v] = 0;
    }

    for (int count = 0; count < numVertices - 1; count++) {
        int u = findMinKeyVertex(&mst, numVertices);
        mst.inMST[u] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (graph->adjacencyMatrix[u][v] && !mst.inMST[v] && graph->adjacencyMatrix[u][v] < mst.key[v]) {
                mst.parent[v] = u;
                mst.key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    printMST(&mst, numVertices);
}

int main() {
    Graph graph;
    int choice;
    int numVertices, u, v, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    graph = createGraph(numVertices);

    do {
        printf("\nMenu:\n");
        printf("1. Add an edge\n");
        printf("2. Find Minimum Spanning Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter edge (u v weight): ");
                scanf("%d %d %d", &u, &v, &weight);
                addEdge(&graph, u, v, weight);
                break;
            case 2:
                printf("Minimum Spanning Tree:\n");
                primMST(&graph);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
