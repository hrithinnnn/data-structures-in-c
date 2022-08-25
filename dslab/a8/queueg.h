#include<stdlib.h>
#define MAX_SIZE 100

typedef struct Queue* ptr;
typedef struct Queue{
  int queue[MAX_SIZE];
  int front;
  int rear;
}Queue;

int isFull(ptr q);
int isEmpty(ptr q);
void enqueue(ptr q, int item);
int dequeue(ptr q);
int getFront(ptr q);
int getRear(ptr q);

ptr createQueue(){
  ptr temp=(ptr)malloc(sizeof(Queue));
  temp->front=0;
  temp->rear=-1;
  return temp;
}

int isFull(ptr q){
  return (q->rear+2)%MAX_SIZE==q->front;
}

int isEmpty(ptr q){
  return (q->rear+2)%MAX_SIZE==q->front;
}
void enqueue(ptr q, int item){
  if(!isFull(q)){
    q->rear=(q->rear+1)%MAX_SIZE;
    q->queue[q->rear]=item;
  }
}
int dequeue(ptr q){
  int res=-1;
  if(!isEmpty(q)){
    res=q->queue[q->front];
    q->front=(q->front+1)%MAX_SIZE;
  }
  return res;
}
int getFront(ptr q){
  int res=1;
  if(!isEmpty(q)){
    res=q->queue[q->front];
  }
  return res;
}
int getRear(ptr q){
  int res=1;
  if(!isEmpty(q)){
    res=q->queue[q->rear];
  }
  return res;
}