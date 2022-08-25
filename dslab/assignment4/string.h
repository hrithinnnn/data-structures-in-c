#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Stack { 
int top;
unsigned capacity;
char* array;
}Stack;

struct Stack* createStack(unsigned capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1; 
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1; 
}

void push(struct Stack* stack, char item) {
    if (isFull(stack)) return;

    stack->top++;
    stack->array[stack->top] = item; 
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) return 'x';
    return stack->array[(stack->top)--]; 
}

char getTop(struct Stack* stack) {
    if (isEmpty(stack)) return 'x';
    return stack->array[stack->top]; 
}

char cal(int a,int b, char sign) {
    if (sign=='+') {
        return ((a+b));
    } 
    else if (sign=='-') {
        return ((a-b)+'0');
    }
    else if (sign=='*') {
        return ((a*b)+'0');
    }
    else if(sign=='/') {
        return ((a/b)+'0');
    }
    else if(sign=='^') {
        return ((a^b)+'0');
    }
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

