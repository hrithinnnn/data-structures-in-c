#include<stdlib.h>
#include<stdio.h>
struct node {
    char data;
    struct node* next;
};
 
void push(struct node** top, int new_data);

int pop(struct node** top);
 

int match(char Char1, char Char2) {

    if (Char1 == '(' && Char2 == ')')
        return 1;
    else if (Char1 == '{' && Char2 == '}')
        return 1;
    else if (Char1 == '[' && Char2 == ']')
        return 1;
    else
        return 0;
}
 

int bal(char exp[])
{
    int i = 0;
 
    
    struct node* stack = NULL;
 
    
    while (exp[i])
    {
        
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&stack, exp[i]);
 
        if (exp[i] == '}' || exp[i] == ')'|| exp[i] == ']') {
            
            if (stack == NULL)
                return 0;
 
           
            else if (!match(pop(&stack), exp[i]))
                return 0;
        }
        i++;
    }
 
   
    if (stack == NULL)
        return 1; 
    else
        return 0; 
}
 
void push(struct node** top, int new_data)
{
    
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
 
    if (new_node == NULL) {
        printf("overflow");
        getchar();
        exit(0);
    }
 
   
    new_node->data = new_data;
 
    
    new_node->next = (*top);
 
    
    (*top) = new_node;
}
 

int pop(struct node** top)
{
    char res;
    struct node* top;
 
    
    if (*top == NULL) {
        printf("underflow");
        getchar();
        exit(0);
    }
    else {
        top = *top;
        res = top->data;
        *top = top->next;
        free(top);
        return res;
    }
}

int main()
{
    char exp[100]; 
    scanf("%s",&exp[100]);
 
    
    if (bal(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}
 

