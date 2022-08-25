#include<stdio.h>
#include<stdlib.h>
#include "dll.h"
void shift(pnode dll,int dir,int ct)
{
	if(dll->next){
		while(ct>0){
			if(dir==-1){
				deleteFirst(dll);
			}
			else {
				deleteLast(dll);
			}
ct--;
}
}
}
void display(pnode dll){
	pnode temp=dll->next;
	printf("%d ",temp->data);
	temp=temp->next;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	pnode dll=(pnode)malloc(sizeof(node));
	dll->next=NULL;
	dll->prev=NULL;
	printf("insertFirst(dll,1): \n");
	insertFirst(dll,1);
	display(dll);
	printf("insertLast(dll,2): \n");
	insertLast(dll,2);
	display(dll);
	printf("insertLast(dll,3): \n");
	insertLast(dll,3);
	display(dll);
	printf("insertFirst(dll,4): \n");
	insertFirst(dll,4);
	display(dll);
	printf("deleteFirst(dll): \n");
	deleteFirst(dll);
	display(dll);
	printf("deleteLast(dll): \n");
	deleteLast(dll);
	display(dll);
	printf("deleteLast(dll): \n");
	deleteLast(dll);
	display(dll);
	printf("deleteLast(dll): \n");
	deleteLast(dll);
	display(dll);
	printf("insertFirst(dll,1): \n");
	insertFirst(dll,1);
	display(dll);
	printf("insertLast(dll,2): \n");
	insertLast(dll,2);
	display(dll);
	printf("shift(dll,1,1): \n");
	shift(dll,1,1);
	display(dll);
	return 0;

}
		 