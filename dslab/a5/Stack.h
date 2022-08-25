#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
struct expstack {
    int top;
    unsigned capacity;
    char* array;
};
struct expstack* createexpstack(unsigned capacity);
int isFullexpstack(struct expstack* expstack);
int isEmptyexpstack(struct expstack* expstack);
void pushexpstack(struct expstack* expstack, int item);
int popexpstack(struct expstack* expstack);
int getTopexpstack(struct expstack* expstack);
struct expstack* createexpstack(unsigned capacity)
{
    struct expstack* expstack = (struct expstack*)malloc(sizeof(struct expstack));
    expstack->capacity = capacity;
    expstack->top = -1;
    expstack->array = (char*)malloc(expstack->capacity * sizeof(char));
    return expstack;
}
 
int isFullexpstack(struct expstack* expstack)
{
    return expstack->top == expstack->capacity - 1;
}
 
int isEmptyexpstack(struct expstack* expstack)
{
    return expstack->top == -1;
}
 
void pushexpstack(struct expstack* expstack, int item)
{
    if (isFullexpstack(expstack))
        return;
    expstack->array[++expstack->top] = item;
    
}
 
int popexpstack(struct expstack* expstack)
{
    if (isEmptyexpstack(expstack))
        return INT_MIN;
    return expstack->array[expstack->top--];
}
 
int getTopexpstack(struct expstack* expstack)
{
    if (isEmptyexpstack(expstack))
        return '\0';
    return expstack->array[expstack->top];
}