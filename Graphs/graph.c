#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

int isVertexInGraph(int vertex, int vertices) {
    return (vertex >= 0 && vertex < vertices);
}

void depthFirstSearch(int startVertex, int vertices) {
    visited[startVertex] = 1;
    printf("Visited vertex: %d\n", startVertex);

    for (int i = 0; i < vertices; i++) {
        if (graph[startVertex][i] == 1 && !visited[i]) {
            depthFirstSearch(i, vertices);
        }
    }
}

void breadthFirstSearch(int startVertex, int vertices) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;
    int currentVertex;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("Breadth-First Search (BFS) Traversal:\n");

    while (front != rear) {
        currentVertex = queue[++front];
        printf("Visited vertex: %d\n", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

void addEdge(int from, int to, int vertices) {
    if (isVertexInGraph(from, vertices) && isVertexInGraph(to, vertices)) {
        graph[from][to] = 1;
        graph[to][from] = 1; // For an undirected graph
    } else {
        printf("Invalid vertices. Edge not added.\n");
    }
}

int main() {
    int vertices, edges, choice, startVertex, endVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edge connections (from to): \n");
    for (int i = 0; i < edges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        addEdge(from, to, vertices);
    }

    while (1) {
        printf("\nGraph Operations:\n");
        printf("1. Check if a vertex is in the graph\n");
        printf("2. Depth-First Search (DFS) Traversal\n");
        printf("3. Breadth-First Search (BFS) Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the vertex to check: ");
                scanf("%d", &startVertex);
                if (isVertexInGraph(startVertex, vertices)) {
                    printf("Vertex %d is in the graph.\n", startVertex);
                } else {
                    printf("Vertex %d is not in the graph.\n", startVertex);
                }
                break;
            case 2:
                for (int i = 0; i < vertices; i++) {
                    visited[i] = 0; // Reset visited array
                }
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &startVertex);
                if (isVertexInGraph(startVertex, vertices)) {
                    printf("DFS Traversal:\n");
                    depthFirstSearch(startVertex, vertices);
                } else {
                    printf("Invalid starting vertex for DFS.\n");
                }
                break;
            case 3:
                for (int i = 0; i < vertices; i++) {
                    visited[i] = 0; // Reset visited array
                }
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &startVertex);
                if (isVertexInGraph(startVertex, vertices)) {
                    printf("BFS Traversal:\n");
                    breadthFirstSearch(startVertex, vertices);
                } else {
                    printf("Invalid starting vertex for BFS.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
