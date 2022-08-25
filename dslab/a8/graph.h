#include<string.h>
#include<stdio.h>
#include "Queue.h"
#include "heap1.h"
#define MAX_SIZE 100
#define INF 1e6

typedef struct Graph
{
	long adj[MAX_SIZE][MAX_SIZE];
	int size;
	int visited[MAX_SIZE];
	int parent[MAX_SIZE];
    int dist[MAX_SIZE];
}graph;

void insertEdge(graph *G, int v1, int v2, int wt);
void insertVertex(graph *G);
void createGraph(graph *G, int size);
void dfs(graph *G, int node, int to_print);
void bfs(graph *G, int node, int to_print);
void visit_dfs_connected(graph *G, int node);
void visit_dfs_disconnected(graph *G);
void visit_bfs_connected(graph *G, int node);
void visit_bfs_disconnected(graph *G);
void dfs_all_paths(graph *G,int node, int seen_nodes, int dest, int seen[MAX_SIZE], int path[MAX_SIZE][MAX_SIZE], int noOfPaths);
void all_path_dfs(graph *G, int source, int destination, int paths[MAX_SIZE][MAX_SIZE]);
void dijkstra(graph *G, int source);
	
void createGraph(graph *G, int size) {
    G->size = size;
    memset(G->visited, 0, sizeof(G->visited));
    memset(G->adj, 0, sizeof(G->adj));
    memset(G->parent, -1, sizeof(G->parent));
}
void visit_dfs_connected(graph *G, int node) {
    memset(G->visited, 0, sizeof(G->visited));
	memset(G->parent, -1, sizeof(G->parent));
    dfs(G, node, 1);
}

void visit_dfs_disconnected(graph *G) {
    memset(G->visited, 0, sizeof(G->visited));
	memset(G->parent, -1, sizeof(G->parent));
    for (int i = 1; i <= G->size; i ++)
        if (!G->visited[i]){
            dfs(G, i, 1);
            printf("\n");
        }
}
void visit_bfs_connected(graph *G, int node) {
    memset(G->visited, 0, sizeof(G->visited));
	memset(G->parent, -1, sizeof(G->parent));
    bfs(G, node, 1);
}

void visit_bfs_disconnected(graph *G) {
    memset(G->visited, 0, sizeof(G->visited));
	memset(G->parent, -1, sizeof(G->parent));
    for (int i = 1; i <= G->size; i ++)
        if (!G->visited[i]){
            bfs(G, i, 1);
            printf("\n");
        }
}
void dfs(graph *G, int node, int to_print)
{
	G->visited[node] = 1;
	if(to_print){
        printf("%d ", node);
    }
	for (int i = 1; i <= G->size; i ++) 
	{
        if (G->adj[node][i] && !G->visited[i]) {
            dfs(G, i, to_print);
            G->parent[i] = node;            
        }
    }
}

	
void bfs(graph *G, int node, int to_print)
{
	Queue * q = createQueue(MAX_SIZE);
	enqueue(q, node);
	G->visited[node] = 1;
	while (!isEmpty(q))
	{
		int u = dequeue(q);
		if (to_print)
		printf("%d ", u);
		for (int i = 1; i <= G->size; i++)
		{
			if (G->adj[u][i] && !G->visited[i])
			{
				G->visited[i] = 1;
				G->parent[i] = u;
				enqueue(q, i);
			}
		}
	}
}

void dfs_all_paths(graph *G,int node, int seen_nodes, int dest, int seen[MAX_SIZE], int path[MAX_SIZE][MAX_SIZE], int noOfPaths) {
    G->visited[node] = 1;
    seen[seen_nodes] = node; 
    for (int i = 1; i <= G->size; i ++) {
        int found = 0;
        for (int j = 0; j <= seen_nodes; j ++) {
            if (seen[j] == i) {
                found = 1;
            }
        }
        if (!found && G->adj[node][i] && !G->visited[i]) {
            if (i == dest) {
                for (int j = 0; j <= seen_nodes; j ++) {
                    path[noOfPaths][j] = seen[j];
                }
				path[noOfPaths][seen_nodes + 1] = dest;

				path[noOfPaths][seen_nodes + 2] = '\0';
				noOfPaths ++;
            }
            else {
                dfs_all_paths(G, i, seen_nodes + 1, dest, seen, path, noOfPaths);
            }
        }
    }
}   

void all_path_dfs(graph *G, int source, int destination, int paths[MAX_SIZE][MAX_SIZE]) {
	int seen_nodes = 0, seen[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i ++) {
		paths[i][0] = '\0';
	}
	memset(G->visited, 0, sizeof(G->visited));
	dfs_all_paths(G, source, seen_nodes, destination, seen, paths, 0);
}
void insertVertex(graph *G)
{
	G->size ++;
}


void insertEdge(graph *G, int v1, int v2, int wt)
{
	G->adj[v1][v2] = wt;
}

void dijkstra(graph *G, int source)
{
	
    memset(G->parent, -1, sizeof(G->parent));
    for (int i = 1; i <= G->size; i++) G->dist[i] = INF;

    G->dist[source] = 0;
    pheap PQ = initHeap();
    pair s = {source, 0};
    insert(PQ, s);
    while(PQ->size) {
        pair minDistNode = deleteMin(PQ);
        for (int i = 1; i <= G->size; i++) {
            if (G->adj[minDistNode.key][i] && minDistNode.value + G->adj[minDistNode.key][i] < G->dist[i]) {
                G->dist[i] = minDistNode.value + G->adj[minDistNode.key][i];
                G->parent[i] = minDistNode.key;
                pair p = {i, G->dist[i]};
                insert(PQ, p);
            }
        }
	for (int i = 1; i <= G->size; i++) printf("%d ", G->dist[i]);
	printf("\n");
    }
}
