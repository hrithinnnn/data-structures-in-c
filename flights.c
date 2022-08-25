#include<stdio.h>
#include "Graph.h"





int getIndex(char city[MAX_SIZE], int *no_city_number, char cities[MAX_SIZE][MAX_SIZE]) {
    for (int i = 1; i <= *no_city_number; i ++) {
        if (!strcmp(cities[i], city)) return i;
    }
    strcpy(cities[++*no_city_number],city);
    return *no_city_number;
}

// void flights(graph *G, int c1, int c2, char cities[MAX_SIZE][MAX_SIZE])
// {
//     if (G->adj[c1][c2])
//     {
//         printf("Direct flight available - Flight number %d\n\n", G->adj[c1][c2]);
//     }
//     else {
//         printf("\nNo direct flight\n");   
//         memset(G->visited, 0, sizeof(G->visited));    
//         memset(G->parent, -1, sizeof(G->parent));
//         bfs(G, c1, 0);
//         if(G->parent[c2] == -1) {
//             printf("No connecting flights too\n\n");
//         }
//         else {
//             printf("Connecting flights\n");
//             int path[MAX_SIZE][MAX_SIZE];

//             all_path_dfs(G, c1, c2, path);

//             for (int i = 0; i < MAX_SIZE; i ++) {
//                 if (path[i][0] == '\0') break;
//                 for (int j = 0; j < MAX_SIZE && path[i][j + 1] != '\0'; j ++) {
//                     if (path[i][j] == '\0') break;
//                     printf("%s - ", cities[path[i][j]]);                
//                 }
//                 printf("%s\n", cities[c2]);
//                 printf("Flight number ");
//                 int j; 
//                 for (j = 0; j < MAX_SIZE && path[i][j + 2] != '\0'; j ++) {
//                     if (path[i][j] == '\0') break;
//                     printf("%d - ", G->adj[path[i][j]][path[i][j + 1]]);
//                 }
//                 printf("%d\n", G->adj[path[i][j]][c2]);
//             }
//             printf("\n");
//         }
//     }
// }
int main() {
    int noOfNodes;
    char cities[MAX_SIZE][MAX_SIZE];
    int no_city_number = 0;
    
    int noOfEdges; 
    printf("Enter the number of cities: ");
    scanf("%d", &noOfNodes);
    graph G;
    createGraph(&G, noOfNodes);
    printf("Enter the number of direct flight: ");
    scanf("%d", &noOfEdges);
    printf("Enter direct flights:\n");
    char u[MAX_SIZE], v[MAX_SIZE]; 
    for (int i = 0; i < noOfEdges; i ++) {
        scanf("%s %s", u, v);
        int c1 = getIndex(u, &no_city_number, cities), c2 = getIndex(v, &no_city_number, cities);
        insertEdge(&G, c1, c2, i + 1);
    }
    char t[10];
    printf("\nEnter pair of cities: (city1 to city2 or exit to end)\n\n");
    do{
        scanf("%s", u);
        if(!strcmp(u, "exit")) {
            continue;
        }
        else{
            scanf("%s %s", t, v);
            if (getIndex(u, &no_city_number, cities) <= noOfNodes && getIndex(v, &no_city_number, cities) <= noOfNodes) {
                int c1 = getIndex(u, &no_city_number, cities), c2 = getIndex(v, &no_city_number, cities);
                //flights(&G, c1, c2, cities);
                if (G.adj[c1][c2])
                {
                    printf("Direct flight available - Flight number %li\n\n", G.adj[c1][c2]);
                }
                else {
                    printf("\nNo direct flight\n");   
                    memset(G.visited, 0, sizeof(G.visited));    
                    memset(G.parent, -1, sizeof(G.parent));
                    bfs(&G, c1, 0);
                    if(G.parent[c2] == -1) {
                        printf("No connecting flights too\n\n");
                    }
                    else {
                        printf("Connecting flights\n");
                        int path[MAX_SIZE][MAX_SIZE];

                        all_path_dfs(&G, c1, c2, path);

                        for (int i = 0; i < MAX_SIZE; i ++) {
                            if (path[i][0] == '\0') break;
                            for (int j = 0; j < MAX_SIZE && path[i][j + 1] != '\0'; j ++) {
                                if (path[i][j] == '\0') break;
                                printf("%s - ", cities[path[i][j]]);                
                            }
                            printf("%s\n", cities[c2]);
                            printf("Flight number ");
                            int j; 
                            for (j = 0; j < MAX_SIZE && path[i][j + 2] != '\0'; j ++) {
                                if (path[i][j] == '\0') break;
                                printf("%li - ", G.adj[path[i][j]][path[i][j + 1]]);
                            }
                            printf("%li\n", G.adj[path[i][j]][c2]);
                        }
                        printf("\n");
                    }
                }
            }
            else {
                printf("City name not found\n");
            }
            no_city_number = noOfNodes;
        }
    }while(strcmp(u, "exit"));
    printf("\n");
    return 0;
} 