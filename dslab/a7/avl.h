#define MAX_SIZE 20
typedef struct node* anode;

typedef struct node{
  long int data;
  char name[MAX_SIZE];
  anode left;
  anode right;
  int height;
}node;

static int height(anode t){//Accessor fn for height
  if(t==NULL)
    return -1;
  return t->height;
}
static int max(int l,int r){
  return l>r?l:r;
}
void inorder(anode root){
  if (root != NULL) {
        inorder(root->left);
        printf("%s %ld \n", root->name,root->data);
        inorder(root->right);
    }
}
static anode LL(anode root){
  anode newroot=NULL;
  newroot=root->left;
  root->left=newroot->right;
  newroot->right=root;
  root->height=max(height(root->left),height(root->right))+1;
  newroot->height=max(height(newroot->left),root->height)+1;
  return newroot;
}
static anode RR(anode root){
  anode newroot=NULL;
  newroot=root->right;
  root->right=newroot->left;
  newroot->left=root;
  root->height=max(height(root->left),height(root->right))+1;
  newroot->height=max(height(newroot->right),root->height);
  return newroot;
}
static anode LR(anode root){
  root->left=RR(root->left);
  return LL(root);
}
static anode RL(anode root){
  root->right=LL(root->right);
  return RR(root);
}




anode insert(anode root,long int item,char n[]){
  if(root==NULL){
    root=(anode)malloc(sizeof(node));
    if(root!=NULL){
      root->data=item;
      strcpy(root->name,n);
      root->left=NULL;
      root->right=NULL;
    }
  }
    else if(strcmp(n,root->name)<0){
      root->left=insert(root->left,item,n);
      if(height(root->left)-height(root->right)==2)
      {
        if(strcmp(n,root->left->name)<0){
          root=LL(root);
        }
        else{
          root=LR(root);
        }
      }
    }
    else if(strcmp(n,root->name)>0){
      root->right=insert(root->right,item,n);
      if(height(root->right)-height(root->left)==2)
      {
        if(strcmp(n,root->right->name)>0){
          root=RR(root);
        }
        else{
          root=RL(root);
        }
      }
    }
    //IF not element already exists and so we dont need to do anything
    root->height=max(height(root->left),height(root->right))+1;
    return root;
}
anode search(anode root, char* key)
{

if (root == NULL || strcmp(root->name,key)==0)
return root;
if (strcmp(root->name,key)<0)
return search(root->right, key);

return search(root->left, key);
}