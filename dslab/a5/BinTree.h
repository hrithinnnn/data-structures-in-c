typedef struct tree* tnode;
struct tree{
    char item;
    tnode left;
    tnode right;
} ;
typedef struct stackptr* tStack;
struct stackptr {
    tnode* nodes;
    int top;
    int size;
};

void push(tStack sttree, tnode item);
int isFull(tStack sttree);
int isEmpty(tStack sttree);
tnode getTop(tStack sttree);
tStack createStack(int size);
tnode pop(tStack sttree);


tStack createStack(int size) {
    tStack sttree = (tStack)malloc(sizeof(tStack));
    tnode* arr = malloc(sizeof(struct tree)*size);
    sttree->size = size;
    sttree->nodes = arr;
    sttree->top = -1;
    return sttree;
}


void push(tStack sttree, tnode item) {
    if(isFull(sttree) == 1) {
        return;
    }
    sttree->nodes[++sttree->top] = item;
}


int isFull(tStack sttree) {
    if(!sttree) {
        return -1;
    }
    return sttree->top == sttree->size - 1;
}

int isEmpty(tStack sttree) {
    if(!sttree) {
        return -1;
    }
    return sttree->top < 0;

}


tnode getTop(tStack sttree) {
    if(isEmpty(sttree) == 1) {
        return '\0';
    }
    return sttree->nodes[sttree->top];
}


tnode pop(tStack sttree) {
    if( isEmpty(sttree) == 1) {
        return '\0';
    }
    return sttree->nodes[sttree->top--];
}


tnode newNode(char c);
tnode constructTree(char postfix[]);
void inOrder(tnode t);
void postOrder(tnode t);
void preOrder(tnode t);


tnode newNode(char c) {
    tnode newNode = (tnode)malloc(sizeof(struct tree));
    if(!newNode) {
        return NULL;
    }
    newNode->item = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void inorder(tnode t) {
    if(t) {
        inorder(t->left);
        printf("%c ", t->item);
        inorder(t->right);
    }
}

void postorder(tnode t) {
    if(t) {
        postorder(t->left);
        postorder(t->right);
        printf("%c ", t->item);
    }
}

void preorder(tnode t) {
    if(t) {
        printf("%c ", t->item);
        preorder(t->left);
        preorder(t->right);
    }
}


tnode constructTree(char postfix[]) {
   
    tStack exp = createStack(strlen(postfix));
    for(int i = 0; i < strlen(postfix); i++) {
        if(!isOperator(postfix[i])) { 
            tnode temp = newNode(postfix[i]);
            push(exp, temp);
        } else { 
            tnode t = newNode(postfix[i]);
            tnode r = pop(exp);
            tnode l = pop(exp);
            t->left = l;
            t->right = r;
            push(exp, t); 
        }
    }
    return pop(exp);
}