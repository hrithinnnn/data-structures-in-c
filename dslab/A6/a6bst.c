#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bst.h"
#define COUNT 5

int isIdentical(struct node* root1, struct node* root2)
{
    
    if (root1 == NULL && root2 == NULL)
        return 1;
    else if (root1 != NULL && root2 == NULL)
        return 0;
    else if (root1 == NULL && root2 != NULL)
        return 0;
    else { 
      
        if (root1->key == root2->key && isIdentical(root1->left, root2->left)
            && isIdentical(root1->right, root2->right))
            return 1;
        else
            return 0;
    }
}
int getLeafCount(struct node* node)
{
  if(node == NULL)      
    return 0;
  if(node->left == NULL && node->right==NULL)     
    return 1;           
  else
    return getLeafCount(node->left)+
           getLeafCount(node->right);     
}
int getnonLeafCount(struct node* root){
   if (root == NULL || (root->left == NULL && root->right == NULL)){
      return 0;
   }
   return 1 + getnonLeafCount(root->left) + getnonLeafCount(root->right);
}
int gettotalLeafCount(struct node* node)
{
  if(node == NULL)      
    return 0;
            
  else
    return 1+gettotalLeafCount(node->left)+
           gettotalLeafCount(node->right);     
}
void print2DUtil(struct node* root, int space)
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
    printf("%d\n", root->key);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(struct node* root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
int stringtoint(char s[]){
  int no=0;
  for(int i=1;i<strlen(s);i++){
    no=no*10+(s[i]-'0');
  }
  return no;
}
int main(){
  struct node* root1 = NULL;
  struct node* root2 = NULL;
  /*root1 = insert(root1, 65);
  insert(root1, 34);
  insert(root1, 29);
  insert(root1, 65);
  insert(root1, 10);
  insert(root1, 7);
  insert(root1, 15);
  insert(root1, 1);
 
  root2 = insert(root2, 65);
  insert(root2, 34);
  insert(root2, 29);
  insert(root2, 65);
  insert(root2, 10);
  insert(root2, 7);
  insert(root2, 15);
  insert(root2, 1);*/
  int testcase;
  char s[10];
  int no;
  printf("Enter the number of testcases: ");
  scanf("%d",&testcase);
  printf("For Tree 1: ");
  for(int i=0;i<testcase;i++){
    scanf("%s",s);
    no=stringtoint(s);
    if(s[0]=='i'){
      if(i==0||(gettotalLeafCount(root1)==0)){
        
        root1=insert(root1,no);
        print2D(root1);
      }
      else{
        insert(root1,no);
        print2D(root1);
      }
    }
    else if(s[0]=='d'){
      if(gettotalLeafCount(root1)==1){
        root1=NULL;
      }
      deleteNode(root1,no);
      print2D(root1);
    }
    else if(s[0]=='s'){
      struct node* temp=search(root1, no);
	if(temp!=NULL){
		printf("Found");
	}
	else{
		printf("Not found");
	}
    }
    else if(s[0]=='t'){
      printf("Inorder traversal is: \n");
      inorder(root1);
      printf("Preorder traversal is: \n");
      preorder(root1);
      printf("postorder traversal is: \n");
      postorder(root1);
      printf("levelorder traversal is: \n");
      levelorder(root1);
    }
    else{
      printf("Wrong choice");
    }
    }
    printf("\nFor tree 2: ");
    for(int i=0;i<testcase;i++){
    scanf("%s",s);
    no=stringtoint(s);
    if(s[0]=='i'){
      if(i==0||(gettotalLeafCount(root2)==0)){
        root2=insert(root2,no);
        print2D(root2);
      }
      else{
        insert(root2,no);
        print2D(root2);
      }
    }
    else if(s[0]=='d'){
      if(gettotalLeafCount(root2)==1){
        root2=NULL;
      }
      else{
      deleteNode(root2,no);
      print2D(root2);
      }
    }
    else if(s[0]=='s'){
      search(root2, no);
    }
    else if(s[0]=='t'){
      printf("Inorder traversal is: \n");
      inorder(root2);
      printf("Preorder traversal is: \n");
      preorder(root2);
      printf("postorder traversal is: \n");
      postorder(root2);
      printf("Levelorder traversal is: \n");
      levelorder(root2);
    }
    else{
      printf("Wrong choice");
    }
    }
  
 
  printf("\nLeaf count of the tree 1 is %d\n", getLeafCount(root1));
  printf("\nNon-Leaf count of the tree 1 is %d\n", getnonLeafCount(root1));
  printf("\nTotal-Leaf count of the tree 1 is %d\n", gettotalLeafCount(root1));

  printf("\nLeaf count of the tree 2 is %d\n", getLeafCount(root2));
  printf("\nNon-Leaf count of the tree 1 is %d\n", getnonLeafCount(root2));
  printf("\nTotal-Leaf count of the tree 1 is %d\n", gettotalLeafCount(root2));
   if(isIdentical(root1, root2)){
    printf("Trees are identical\n");
  }
  else{
    printf("Trees are not identical\n");
  }
}