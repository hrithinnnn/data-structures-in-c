#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct queue{
  int z;
  struct queue *pnode;
}node;

int isEmpty(node* front, node* rear) {
  return (front==NULL) ? 1 :0;
}

void enQueue(node** front,node** rear, int j) {
  if(*rear==NULL)
  {
    node* x= (node*)malloc(sizeof(node));;
    x->z=j;
    x->pnode=NULL;
    *front=x;
    *rear=x;
  }
  else {
    node* x= (node*)malloc(sizeof(node));
    x->pnode=NULL;
    x->z=j;
    (*rear)->pnode=x;
    *rear=x;
  }
}

int deQueue(node** front, node** rear) {
  if(isEmpty(*front,*rear)) return -1;
  if(*front==*rear)
  {
    int j1=(*front)->z;
    *front=NULL;
    *rear=NULL;
    return j1;
  }
  else {
    int j1=(*front)->z;
    *front=(*front)->pnode;
    return j1;
  }
}


void main()
{
  int t,f,j;
  char temp;
 
  node* front1=NULL;
  node* rear1=NULL;
  printf("enqueue\n");
    do
        { 
            scanf("%d%c",&f,&temp); 
            enQueue(&front1, &rear1, f);
            
	  	} while(temp!='\n');
  
  printf("dequeue: ");
  while(!isEmpty(front1,rear1)) {
    printf("%d ",deQueue(&front1,&rear1));
  }
}


    
