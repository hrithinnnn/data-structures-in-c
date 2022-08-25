#include<stdio.h>
#include"Graph9.h" 
#include<string.h>


void input_graph( int *size, char* nodes, char* edges);
void friendship(int n);
void add(char source[], char dest[], char cities[][MAX_SIZE], int *size, int flight_no);
void flight(int n);


void input_graph( int *size, char* nodes, char* edges){
  int n, m;
  printf("Number of %s: ", nodes);
  scanf("%d", &n);
  *size=n;
  init(n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      G[i][j]=0;
    }
  }
  
  printf("Number of %s: ", edges);
  scanf("%d", &m);
  printf("%s: (0-%d)\n", edges,  n-1);
  for(int i=0; i<m; i++){
    int a, b;
    //printf("%d: ", i+1);
    scanf("%d%d", &a, &b);
    G[a][b]=G[b][a]=1;
  }
}



void friendship(int n){

  input_graph(&n, "people", "relations");
  
  int source=0, dest;
  printf("Enter test Relations (-1 to stop) \n");
  while(source !=-1 ){

    printf("\nEnter relation: ");
    scanf("%d", &source);
    if(source==-1){
      break;
    }
    printf("Relation is: ");
    scanf("%d", &dest);
    init(n);
    dfs(source, n, 0); 

    int path[MAX_SIZE];
    int ind=0;
    int cur=dest;

    while(par[cur]!=-1){
      path[ind++]=cur;
      cur=par[cur];
    }

    if(cur==source){//there is a path
      path[ind]=source;
      printf("%d ", source);
      for(int i=ind-1; i>=0; i--){
        printf("- %d ", path[i]);
      }
      printf("\n");
    }
    else{
      printf("%d and %d cannot be introduced\n", source, dest);
    }
  }
  
  printf("\n");
}


void add(char source[], char dest[], char cities[][MAX_SIZE], int *size, int flight_no){
  int n=*size;
  int a=-1, b=-1;
  for(int i=0; i<n; i++){
    if(strcmp(source, cities[i])==0){
      a=i;
    }
    if(strcmp(dest, cities[i])==0){
      b=i;
    }
  }
  if(a==-1){
    strcpy(cities[n], source);
    a=n++;
  }
  if(b==-1){
    strcpy(cities[n], dest);
    b=n++;
  }
  G[a][b]=flight_no;
  *size=n;
}

void flight(int n){

  int m;
  n=0;
  

  char cities[MAX_SIZE][MAX_SIZE], source[MAX_SIZE], to[MAX_SIZE], dest[MAX_SIZE];
  for(int i=0; i<MAX_SIZE; i++){
    for(int j=0; j<MAX_SIZE; j++){
      G[i][j]=0;
    }
  }

  printf("no. of flights: ");
  scanf("%d", &m);
  printf("enter %d flights(eg: Chennai Delhi):\n", m);

  strcpy(to, "to");
  for(int i=1; i<=m; i++){
    scanf("%s", source);
    scanf("%s", dest);
    if(strcmp(to, "to")==0){
      add(source, dest, cities, &n, i);
    }
  }

/*
  for(int i=0; i<n; i++){
    printf("%d: %s\n", i, cities[i]);
  }
*/

  printf("\nenter queries(eg: Chennai to Delhi) (done to exit): \n");
  
  strcpy(source, " ");
  while(strcmp(source, "done")!=0){
    scanf("%s", source);
    if(strcmp(source, "done")==0){
      break;
    }
    scanf("%s", to);
    if(strcmp(to, "done")==0){
      break;
    }
    else if(strcmp(to, "to")){
      continue;
    }
    
    scanf("%s", dest);
    if(strcmp(dest, "done")==0){
      break;
    }

    int a=-1, b=-1;
    for(int i=0; i<n; i++){
      if(strcmp(cities[i], source)==0){
        a=i;
      }
      if(strcmp(cities[i], dest)==0){
        b=i;
      }
    }

    if(a==-1 || b==-1){
      printf("city not found\n");
    }
    else if(G[a][b]){
      printf("direct flight available - flight no: %d\n", G[a][b]);
    }
    else{
      printf("no direct flights\n");
      init(n);
      dfs(a, n, 0);
      int path[MAX_SIZE], flight_path[MAX_SIZE], city_ind=0,flight_ind=0, cur=b;
      while(par[cur]!=-1){
        path[city_ind++]=cur;
        flight_path[flight_ind++]=G[par[cur]][cur];
        cur=par[cur];
      }
      if(cur==a){//there is a path
        path[city_ind]=a;
        printf("connecting flights: ");
        printf("%s ", cities[a]);
        for(int i=city_ind-1; i>=0; i--){
          printf("- %s ", cities[path[i]]);
        }
        printf("\nflight no: ");
        printf("%d ", flight_path[--flight_ind]);
        for(int i=flight_ind-1; i>=0; i--){
          printf("- %d ", flight_path[i]);
        }
        printf("\n");
      }
      else{
        printf("no connecting flights\n");
      }    
    }
    printf("\n");
  }

}
int main(){
  int n, G[MAX_SIZE][MAX_SIZE], vis[MAX_SIZE], par[MAX_SIZE];

      // 0-1
      // 0-3
      // 1-3
      // 2-3
  // 0 to 5

  char choice[MAX_SIZE];
  strcpy(choice, " ");
  while(strcmp(choice, "done")!=0){
    scanf("%s", choice);
    if(strcmp(choice, "traverse")==0){
      input_graph(&n, "nodes", "edges");
      init(n);
      printf("\ndfs(0): ");
      dfs(0, n, 1);
      printf("\n");
      init(n);
      printf("\nbfs(0): ");
      bfs(0, n);
      printf("\n\n");
    }

    else if(strcmp(choice, "disconnected")==0){                
      input_graph(&n, "nodes", "edges");
      printf("\nbfs on disconnected graph: ");
      for(int i=0; i<n; i++){
        if(!vis[i]){
          printf("\nbfs(%d): ", i);
          bfs(i, n);
          printf("\n");
        }
      }
      printf("\n");
    }


    else if(strcmp(choice, "friendship")==0){
      friendship(n);
    }


    else if(strcmp(choice, "flight")==0){
      flight(n);
    }


  }
  return 0;
}

/*
Chennai Delhi
Chennai Bangalore
Chennai Hyderabad
Hyderabad Vizag
Hyderabad Chennai
Madurai Delhi
Chennai Trichy
Trichy Chennai
Vizag Delhi
Bangalore Trichy
Delhi Bangalore
*/
/*
0 1
0 2
1 3
2 3
2 4
2 5
*/
