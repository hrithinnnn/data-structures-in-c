#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100
    int capacity=3;
    int rear;
    int front;
    char job[MAX_QUEUE_SIZE];

 void createQueue(int capacity) {
     rear=-1;
     front=0;
}

int isEmpty(int front, int rear) {
   return (front==rear+1) ? 1 :0;
}

int isFull(int rear,int capacity) {
   return (rear==capacity-1) ? 1 :0;
}

void enQueue(int* rear, char j) {
   if(isFull(*rear,capacity)) return;
    *rear=*rear+1;
    job[*rear]=j;
}

char deQueue(int* front, int* rear) {
    if(isEmpty(*front,*rear)) return 'x';
     char c= job[*front];
    *front=*front+1;
    return c;
}


void main()
{
    createQueue(3);
    enQueue(&rear,'a');
    enQueue(&rear,'b');
    //printf("%s",job);
    //printf("%d",rear);
    enQueue(&rear,'c');
    enQueue(&rear,'d');
  //  printf("%s",job);
    char x;
     //printf("%s",job);
    x=deQueue(&front,&rear);
      printf("%c",x);
    x=deQueue(&front,&rear);
      printf("%c",x);
    x=deQueue(&front,&rear);
      printf("%c",x);
      x=deQueue(&front,&rear);
      printf("%c",x);

}

    
