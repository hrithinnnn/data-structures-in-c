
#include<stdlib.h>
#include"queueg.h"

int G[MAX_SIZE][MAX_SIZE], vis[MAX_SIZE], par[MAX_SIZE];


void init(int n);
void dfs(int node, int n, int to_print);
void bfs(int node, int n);

void init(int n){
  for(int i=0; i<n; i++){
    vis[i]=0;
    par[i]=-1;
  }
}

void dfs(int node, int n, int to_print){
  vis[node]=1;
  if(to_print){
    printf("%d ", node);
  }
  for(int i=0; i<n; i++){
    if(G[node][i] && !vis[i]){
      par[i]=node;
      dfs(i,n,to_print);
    }
  }
}

void bfs(int node, int n){
  ptr q=createQueue();
  enqueue(q, node);
  vis[node]=1;
  printf("%d ", node);
  while(!isEmpty(q)){
    int cur=dequeue(q);
    for(int i=1; i<=n; i++){
      if(G[cur][i]==1 && !vis[i]){
        vis[i]=1;
        printf("%d ", i);
        enqueue(q, i);
      }
    }
  }
}