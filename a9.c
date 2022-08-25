#include<stdio.h>
#include "Graph.h"

int main() {
    graph G;
    int noOfNodes;
    int noOfEdges; 
/*
1 4
4 2
1 3
3 2
*/
    printf("Connected graph\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &noOfNodes);
    createGraph(&G, noOfNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &noOfEdges);
    printf("Enter edges:\n");
    for (int i = 0; i < noOfEdges; i ++) {
        int u, v; 
        scanf("%d %d", &u, &v);
        insertEdge(&G, u, v, 1);
    }
    printf("Dfs traversal:\n");
    visit_dfs_connected(&G, 1);
    printf("\n");
    printf("Bfs traversal:\n");
    visit_bfs_connected(&G, 1);
    printf("\n");
    
    printf("Disconnected graph\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &noOfNodes);
    createGraph(&G, noOfNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &noOfEdges);
    printf("Enter edges:\n");
    for (int i = 0; i < noOfEdges; i ++) {
        int u, v; 
        scanf("%d %d", &u, &v);
        insertEdge(&G, u, v, 1);
    }
    printf("Bfs traversal:\n");
    visit_bfs_disconnected(&G);
    printf("\n");
    return 0;
} 
