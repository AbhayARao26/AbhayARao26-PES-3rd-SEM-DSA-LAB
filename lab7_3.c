/*
 Tree or graph
 
 Given a graph as a form of edge list, determine if the graph is a tree or not

 Input Format:
    The first line has number of nodes ‘n’ , and number of edges ‘e’ The next e lines has the src and dest of edges , the graph is directed

 Constraints:
    The graph is assumed to be a finite and simple graph, which means no self-loops or multiple edges between the same pair of nodes.
    The algorithm doesn't need to consider performance optimizations for very large graphs, and it can work efficiently with graphs of moderate size.

 Output Format:
    Print ‘true’ if the graph is a tree, ‘false’ otherwise

 Sample Input:
     5 4
     0 1
     0 2
     1 3
     1 4
 
 Sample Output:
    true
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

// Function to check if the graph is a tree
int is_tree(int n, int e, int edges[][2]) {
    int adj_list[MAX_NODES][MAX_NODES] = {0};
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES];
    int top = -1;
    int edge_count = 0;

    // Create adjacency list representation of the graph
    for (int i = 0; i < e; ++i) {
        int src = edges[i][0];
        int dest = edges[i][1];
        adj_list[src][dest] = 1;
        edge_count++;
    }

    // Check if the graph has exactly n-1 edges
    if (edge_count != n - 1) {
        return 0; // Not a tree
    }

    // Initialize DFS
    stack[++top] = 0;
    visited[0] = 1;

    while (top != -1) {
        int node = stack[top--];

        // Visit unvisited neighbors
        for (int i = 0; i < n; ++i) {
            if (adj_list[node][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    // Check if all nodes are visited (connected graph)
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            return 0; // Not a tree
        }
    }

    return 1; // It's a tree
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int edges[MAX_NODES][2];
    for (int i = 0; i < e; ++i) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // Check if the graph is a tree and print the result
    int result = is_tree(n, e, edges);
    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
