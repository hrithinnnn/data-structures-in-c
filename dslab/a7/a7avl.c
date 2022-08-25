#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "avl.h"
#define COUNT 10
void print_dir(anode root){
  inorder(root);
}
anode add_phone(anode root,char *name,long int no){
      scanf("%s",name);
      scanf("%ld",&no);
      root=insert(root,no,name);
      return root;
}
void print2DUtil(anode root, int space)
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
    printf("%s %ld\n", root->name,root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(anode root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
void stringtoname(char s[],char name[]){
  int i=1;
  int k=0;
  while(s[i]!='\0'){
    if(s[i]!=' '){
      name[k++]=s[i];
    }
  }
}
long int stringtoint(char *s){
  long int no=0;
  int i;
  while(!isdigit(s[i])){
    i++;
  }
  while(i<strlen(s)){
    no=no*10+(s[i]-'0');
  }
  return no;
}
int main(){
  anode root=NULL;
  int testcase;
  char s;
  char name[20];
  long int no;
   
  
  
  do{
    scanf("%c",&s);
    
    if(s=='i'){
      root=add_phone(root,name,no);
      print2D(root);
    }
    else if(s=='p'){
      print_dir(root);
    }
    else if(s=='s'){
		scanf("%s",name);
		anode temp=search(root,name);
		if(temp!=NULL){
			printf("Found!\n");
		}
		else{
			printf("Not found\n");
		}
    }
    }while(s!='e');
  
  return 0;
  
}