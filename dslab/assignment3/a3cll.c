#include<stdio.h>
#include<stdlib.h>
#include "cll.h"
void rotate(pnode cll,int dir,int count);
void display(pnode cll);
int main()
{
	pnode cll=(pnode)malloc(sizeof(node));
	cll->next=NULL;
	printf("insertFirst(cll,1): \n");
	insertFirst(cll,1);
	display(cll);
	printf("insertLast(cll,2): \n");
	insertLast(cll,2);
	display(cll);
	printf("insertLast(cll,3): \n");
	insertLast(cll,3);
	display(cll);
	printf("insertLast(cll,4): \n");
	insertLast(cll,4);
	display(cll);
	printf("deleteLast(cll): \n");
	deleteLast(cll);
	display(cll);
	printf("deleteFirst(cll): \n");
	deleteFirst(cll);
	display(cll);
	printf("deleteLast(cll): \n");
	deleteLast(cll);
	display(cll);
	printf("deleteLast(cll): \n");
	deleteLast(cll);
	display(cll);
	printf("rotate(cll,1,1): \n");
	rotate(cll,1,1);
	display(cll);
	printf("insertFirst(cll,1): \n");
	insertFirst(cll,1);
	display(cll);
	printf("insertLast(cll,2): \n");
	insertLast(cll,2);
	display(cll);
	printf("insertLast(cll,3): \n");
	insertLast(cll,3);
	display(cll);
	printf("insertLast(cll,4): \n");
	insertLast(cll,4);
	display(cll);
	printf("rotate(cll,1,1): \n");
	rotate(cll,1,1);
	display(cll);
	printf("rotate(cll,-1,2): \n");
	rotate(cll,-1,2);
	display(cll);
	printf("rotate(cll,1,6): \n");
	rotate(cll,1,6);
	display(cll);
	printf("rotate(cll,-1,6): \n");
	rotate(cll,-1,6);
	display(cll);

}
void rotate(pnode cll,int dir,int count){
	if(cll->next){
		while(count>0){
			if(dir==-1){
				insertLast(cll,deleteFirst(cll));
			}
			else {
				insertFirst(cll,deleteLast(cll));
			}
count--;
}
}
}
void display(pnode cll){
	pnode temp,start;
	temp=cll->next;
	if(temp){
		pnode curr=temp->next;
		do{
			printf("%d",curr->data);
			curr=curr->next;
		}while(curr!=temp->next);
}
printf("\n");
	
}