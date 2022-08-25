#include "string.h"
#include<ctype.h>
#include<string.h>
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
 

int bal(struct Stack* stack,char exp[])
{
    int i = 0;
    
    while (exp[i]!='\0')
    {
        
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(stack, exp[i]);
 
        if (exp[i] == '}' || exp[i] == ')'|| exp[i] == ']') {
            
            if (stack == NULL)
                return 0;
           
            else if (!(match(pop(stack), exp[i])))
                return 0;
        }
       // printf("%d",i);
        i++;
   // printf("%d",i);
    }
 
   
    if (isEmpty(stack))
        return 1; 
    else
        return 0; 
}

void main() {
    int cap = 100;
    Stack* x = createStack(cap);
    char exp[100];
    char inf[100];
    int p=0;
    printf("enter expression to convert from infix to postfix(only alphabets or signle digit numbers)");
    scanf("%s",&exp);
    int i=0;
    while(exp[i] != '\0') {
        if(isalnum(exp[i])){ 
            inf[p]=exp[i];
            p++;
        }
        else if(is_operator(exp[i])) {
            if(x->top==-1) {
            push(x,exp[i]);
            }
            else {
            while(precedence(x->array[x->top])>=precedence(exp[i])) {
                inf[p]=pop(x);
                p++;
            }
            push(x,exp[i]);
            }
        }
        else if(exp[i]=='(') {
            push(x,exp[i]);
        }
        else if(exp[i]==')') {
            char c=pop(x);
            inf[p]=c;
            p++;

            while(c!='(') {
            c = pop(x);
            if(c!='('){
            inf[p]=c;
            p++;
            }
            }
        }
        i++;
    }
    while(x->top != -1) {
        inf[p]=pop(x);
        p++;
    }
printf("postfix expression: ");
//if(isalpha(inf[0])) {
for(int q=0;q<p;q++) {
printf("%c",inf[q]);
}
//}
/*else if(isdigit(inf[0])) {
Stack* y = createStack(cap);
for(int q=0;q<p;q++) {
printf("%c",inf[q]);
}

for(int q=0;q<p;q++) {
if(isdigit(inf[q])) { 
push(y,inf[q]);
}
else {
//printf("%s","helllo");
int a;
sscanf(pop(y), "%d", &a);
int b;
sscanf(pop(y), "%d", &b);
printf("%s","helllo");
char c=cal(a,b,exp[q]);
printf("%d%d",a,b);
push(y,c);
}
//printf("%c",getTop(y));
}
printf("%c",getTop(y));
}*/

Stack* y = createStack(cap);
char exp1[100];
printf("\n\nenter expression to check for balanced paranthesis: ");
scanf("%s",&exp1);
if (bal(y,exp1))
        printf("the expression is balanced \n");
else
        printf("the expression is not balanced \n");

}
