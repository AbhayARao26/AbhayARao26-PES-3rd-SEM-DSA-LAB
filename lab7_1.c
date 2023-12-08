/*
 Is reachable?
 
 Given a graph, find if destination can be reached by the source

 Input Format:
    The first line has number of nodes ‘n’ , and number of edges ‘e’
    The next e lines has the src and dest of edges , the graph is directed
    Next line has value q, you need to answer q queries
    Next q lines has src and dest
 
 Constraints:
    None

 Output Format:
    For each query , print ‘yes’ if reachable , ‘no’ if not
 
 Sample Input:
     5 7
     0 1
     0 2
     1 2
     2 0
     2 3
     3 3
     1 3
     3
     0 1
     1 3
     3 0
 
 Sample Output:
    yes
    yes
    no
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct {
    int src, dest;
} Edge;

typedef struct Node {
    int node;
    struct Node* next;
} Node;

typedef struct {
    Node* graph[MAX_NODES];
} Graph;

void addEdge(Graph* g, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->node = dest;
    newNode->next = g->graph[src];
    g->graph[src] = newNode;
}

void dfs(int node, Node* graph[], int visited[]) {
    visited[node] = 1;

    Node* current = graph[node];
    while (current != NULL) {
        int neighbor = current->node;
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
        current = current->next;
    }
}

int isReachable(Graph* g, int n, int source, int destination) {
    int* visited = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(source, g->graph, visited);

    int result = visited[destination];

    free(visited);
    return result;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    Graph graph = { { NULL } };

    for (int i = 0; i < e; i++) {
        Edge edge;
        scanf("%d %d", &edge.src, &edge.dest);
        addEdge(&graph, edge.src, edge.dest);
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);

        int result = isReachable(&graph, n, source, destination);
        printf("%s\n", result ? "yes" : "no");
    }

    return 0;
}

