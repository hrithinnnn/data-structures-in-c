#include <stdio.h>
#include "Graph.h"

#define MAXSIZE 100
#define INF 1e6



/*
A B 3   
A C 1
B C 7
D B 5
D C 2
E B 1
E D 7
*/
int main()
{
    int n, m;
	printf("Enter the number of vertices in the graph : ");
    scanf("%d", &n);
    printf("Enter the number of edges : ");
    scanf("%d", &m);
    printf("Enter the source : ");
    char source;
    scanf(" %c", &source);
    graph G;
    createGraph(&G, n);
    memset(G.adj, INF, sizeof(G.adj));
    for (int i = 1; i <= m; i++) {
        char a, b;
        int w;
        scanf(" %c", &a);
        scanf(" %c", &b);
        scanf(" %d", &w);
        insertEdge(&G, a - 'A' + 1, b - 'A' + 1, w);
        insertEdge(&G, b - 'A' + 1, a - 'A' + 1, w);
    }

    printf("The distance array in intermediate steps\n");
    dijkstra(&G, source - 'A' + 1);
    for (int destination = 1; destination <= G.size; destination++) {
        printf("Destination : %c\n", destination + 'A' - 1);
        printf("Distance : %d\n", G.dist[destination]);
        printf("Path : ");
        int path[MAXSIZE], count = 0, cur = destination;
        while (cur != -1) {
            path[++count] = cur;
            cur = G.parent[cur];
        }
        for (int i = count; i; i--) printf("%c ", path[i] + 'A' - 1);
        printf("\n\n");
    }
}
