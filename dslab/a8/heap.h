#include<stdlib.h>
#define MAX_SIZE 100
typedef struct heap* heapptr;
typedef struct heap{
  float tree[MAX_SIZE];
  int last;
}heap;

float getroot(heapptr hp){
  return hp->tree[1];
}
int parent(int i){
  return i/2;
}
int left(int i){
  return 2*i;
}  
int right(int i){
  return 2*i+1;
}
heapptr createHeap(){
  heapptr temp=(heapptr)malloc(sizeof(heap));
  temp->last=1;
  return temp;
}

int isFull(heapptr hp){
  return hp->last==MAX_SIZE;
}

int isEmpty(heapptr hp){
  return hp->last==1;
}

void swap(float* a, float* b){
  float temp=*a;
      *a=*b;
      *b=temp;
}
void heapifyup(heapptr hp,float item){
  hp->tree[hp->last]=item;
  for(int i=hp->last; i>1; i/=2){
    if(hp->tree[i]<hp->tree[parent(i)]){
      swap(&hp->tree[i], &hp->tree[parent(i)]);
    }
  }
  hp->last++;
}
void insertHeap(heapptr hp, float item){

  if(isFull(hp)){
    return;
  }
  hp->tree[hp->last]=item;
  for(int i=hp->last; i>1; i/=2){
    if(hp->tree[i]<hp->tree[parent(i)]){
      swap(&hp->tree[i], &hp->tree[parent(i)]);
    }
  }
  hp->last++;
}

float deleteMin(heapptr hp){
  if(isEmpty(hp)){
    return 0;
  }
  float temp=hp->tree[1];
  hp->tree[1]=hp->tree[--hp->last];
  int i=1;
  while(left(i)<hp->last){
    if(hp->tree[i]>=hp->tree[left(i)] &&  (right(i)>=hp->last || hp->tree[left(i)]<=hp->tree[right(i)])){
      swap(&hp->tree[i], &hp->tree[left(i)]);
      i=2*i;
    }
    else if(right(i)<=hp->last && hp->tree[i]>=hp->tree[right(i)] && hp->tree[right(i)]<=hp->tree[left(i)]){
      swap(&hp->tree[i], &hp->tree[right(i)]);
      i=right(i);
    }
    else{
      break;
    }
  }
  return temp;
}

heapptr buildHeap(float arr[], int n){
  heapptr hp=createHeap();
  for(int i=0; i<n; i++){
    insertHeap(hp, arr[i]);
  }
  return hp;
}


void printHeap(heapptr hp){
  int maxdepth=0;
  for(int i=1 ;i<hp->last; i++){
    if((i&(i+1))==0){
      maxdepth++;
    }
  }
  int dep=0;

  for(int i=1; i<hp->last; i++){
    int spaces=(1<<(maxdepth-dep))-1;
    for(int space=0; space<spaces; space++){
      printf("    ");
    }

    printf("%.2f", hp->tree[i]);
    for(int space=0; space<spaces; space++){
      printf("    ");
    }
    printf("   ");
  
    if((i&(i+1))==0){
      dep++;
      printf("\n\n");
    }
  }
}