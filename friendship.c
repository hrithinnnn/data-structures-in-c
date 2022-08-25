#include<stdio.h>
#include<string.h>
#include "Graph.h"

void friends(graph *G, int friend1,int friend2) {
    memset(G->visited, 0, sizeof(G->visited));
	memset(G->parent, -1, sizeof(G->parent));
    bfs(G, friend2, 0);
//     if(G->parent[friend1] == -1) {
//         printf("There is no way to introduce x to y\n");
//     }
//     else {
//         int temp = friend1;
//         while(temp != friend2) {
//             printf("Person %d -> ", temp);
//             temp = G->parent[temp];
//         }
//         printf("Person %d\n\n", friend2);
//     }
}

int main() {
    int noOfNodes;
    int noOfEdges; 
    printf("Enter the number of friends: ");
    scanf("%d", &noOfNodes);
    graph G;
    createGraph(&G, noOfNodes);
    printf("Enter the number of friendship relations: ");
    scanf("%d", &noOfEdges);
    printf("Enter relations:\n");
    for (int i = 0; i < noOfEdges; i ++) {
        int u, v; 
        scanf("%d %d", &u, &v);
        insertEdge(&G, u, v, 1);
        insertEdge(&G, v, u, 1);
    }
    char c[MAX_SIZE];
    printf("Enter pair of friends to intorduce: (introduce x y or exit to end)\n");
    do{
        scanf("%s", c);
        if (!strcmp(c, "introduce")) {
            int x, y; 
            scanf("%d %d", &x, &y);
            friends(&G, x, y);          
            // memset(G.visited, 0, sizeof(G.visited));
            // memset(G.parent, -1, sizeof(G.parent));
            // bfs(&G, y, 0);
            if(G.parent[x] == -1) {
                printf("There is no way to introduce %d to %d\n", x, y);
            }
            else {
                int temp = x;
                while(temp != y) {
                    printf("Person %d -> ", temp);
                    temp = G.parent[temp];
                }
                printf("Person %d\n\n", y);
            }
        }
        else if(!strcmp(c, "exit")) {
            continue;
        }
        else {
            printf("Wrong choice\n");
        }
    }while(strcmp(c, "exit"));
    printf("\n");
    return 0;
} 
