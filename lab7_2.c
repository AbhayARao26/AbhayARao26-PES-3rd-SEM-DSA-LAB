/*
 Number of components
 
 Given a graph , find the number of components in them.

 Input Format:
    The first line has number of nodes ‘n’ , and number of edges ‘e’ The next e lines has the src and dest of edges , the graph is directed

 Constraints:
    The graph is assumed to be finite and simple, with no self-loops or multiple edges between the same pair of nodes.

 Output Format:
    The number of components of the graph

 Sample Input:
     5 4
     0 1
     1 2
     2 0
     3 4
 
 Sample Output:
    2
 */

#include <stdio.h>
#include <stdlib.h>

// Function to perform Depth-First Search (DFS) on the graph
void DFS(int current, int *visited, int *adjacency[], int n) {
    visited[current] = 1;

    for (int i = 0; i < n; i++) {
        if (adjacency[current][i] && !visited[i]) {
            DFS(i, visited, adjacency, n);
        }
    }
}

// Function to find the number of components in the graph
int findComponents(int *adjacency[], int n) {
    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        visited[i] = 0;  // Initialize all nodes as not visited
    }

    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, visited, adjacency, n);
            components++;
        }
    }

    free(visited);
    return components;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    // Allocating memory for adjacency matrix
    int **adjacency = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adjacency[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            adjacency[i][j] = 0;  // Initializing the adjacency matrix
        }
    }

    // Reading edges and building the adjacency matrix
    for (int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adjacency[src][dest] = 1;
    }

    int components = findComponents(adjacency, n);
    printf("%d\n", components);

    // Freeing allocated memory
    for (int i = 0; i < n; i++) {
        free(adjacency[i]);
    }
    free(adjacency);

    return 0;
}

