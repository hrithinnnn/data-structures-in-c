#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinTree.h"
#include "Stack.h"
#define COUNT 10

int infixToPostfix(char* exp);
void print2DUtil(tnode root, int space);
int isOp(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
    }
    return -1;
}
int infixToPostfix(char* exp)
{
    int i, k;
    struct expstack* st = createexpstack(strlen(exp)+1);
    if(!st) 
        return -1 ;
 
    for (i = 0, k = -1; exp[i]; ++i)
    {
         
  
        if (isOp(exp[i])||isdigit(exp[i]))
            exp[++k] = exp[i];
         
      
        else if (exp[i] == '(')
            pushexpstack(st, exp[i]);
         

        else if (exp[i] == ')')
        {
            while (!isEmptyexpstack(st) && getTopexpstack(st) != '(')
                exp[++k] = popexpstack(st);
            if (!isEmptyexpstack(st) && getTopexpstack(st) != '(')
                return -1;            
            else
                popexpstack(st);
        }
        else
        {
            while (!isEmptyexpstack(st) &&
                 Prec(exp[i]) <= Prec(getTopexpstack(st)))
                exp[++k] = popexpstack(st);
            pushexpstack(st, exp[i]);
        }
 
    }
 
    
    while (!isEmptyexpstack(st))
        exp[++k] = popexpstack(st);
 
    exp[++k] = '\0';
    
}

void print2DUtil(tnode root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", root->item);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(tnode root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
int eval(tnode root) 
{ 
    int num;
    // empty tree 
    if (!root) 
        return 0; 
  
    // leaf node i.e, an integer 
    if (!root->left && !root->right) {
        printf("Enter value of %c: ",root->item);
        scanf("%d",&num);
        return num; 
    }
  
    // Evaluate left subtree 
    int l_val = eval(root->left); 
  
    // Evaluate right subtree 
    int r_val = eval(root->right); 
  
    // Check which operator to apply 
    if (root->item=='+') 
        return l_val+r_val; 
  
    if (root->item=='-') 
        return l_val-r_val; 
  
    if (root->item=='*') 
        return l_val*r_val; 
  
    return l_val/r_val; 
} 
int main(void) {
  
    char expr[] = "((A*(B/(D-E)))/F)";
    infixToPostfix(expr);
    printf("Postfix is: %s\n",expr);
    tnode tree = constructTree(expr);
    printf("inOrder: ");
    inorder(tree);
    printf("\npostOrder: ");
    postorder(tree);
    printf("\npreOrder: ");
    preorder(tree);
    print2D(tree);

    printf("%d",eval(tree));
}