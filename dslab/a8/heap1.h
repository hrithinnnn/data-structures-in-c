#include <stdlib.h>
#define MAX_SIZE 100

typedef struct heap * pheap;

typedef struct pair{
    int key, value;
}pair;

typedef struct heap
{
	pair priority[MAX_SIZE];
	int size;
}heap;

void swap (pair *a, pair *b)
{
	pair temp = *b;
	*b = *a;
	*a = temp;
}

pheap initHeap()
{
	pheap temp = (pheap) malloc(sizeof(heap));
	temp->size = 0;
}


void HeapifyUp(pheap H, int i)
{
	int p = i / 2;
	while (i > 1 && H->priority[p].value > H->priority[i].value)
	{
		swap(&H->priority[p], &H->priority[i]);
		i = p;
		p = i / 2;
	}
}

void HeapifyDown(pheap H, int i)
{
	int smallest = i;
	int left = 2*i;
	int right = 2*i+1;
	
	if (left <= H->size && H->priority[smallest].value > H->priority[left].value)
		smallest = left;
		
	if (right <= H->size && H->priority[smallest].value > H->priority[right].value)
		smallest = right;
		
	if (smallest != i)
	{
		swap(&H->priority[i], &H->priority[smallest]);
		HeapifyDown(H, smallest);
	}
	
}

//building min heap
void buildHeap(pheap H)
{
	int size = H->size;
	for (int i = size/2; i > 0 ; i--)
		HeapifyDown(H, i);
}

void insert (pheap H, pair newpriority)
{
	H->size += 1;
	H->priority[H->size] = newpriority;
	HeapifyUp(H, H->size);
}

pair deleteMin (pheap H)
{
	pair min = H->priority[1];
	H->priority[1] = H->priority[H->size--];
	HeapifyDown(H, 1);		
	return min;
}

pair getMin(pheap H)
{
	return H->priority[1];
}
