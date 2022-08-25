#include<stdio.h>
#include<stdlib.h>
typedef struct node* pnode;
typedef struct node{
	int data;
	pnode next;
	pnode prev;
}node;
void insertFirst(pnode dll,int item){
	pnode temp=(pnode)malloc(sizeof(node));
	if(!temp){
		printf("Overflow");
	}
	temp->data=item;
	if(dll->next==NULL){
		
		temp->next=NULL;
		temp->prev=NULL;
		dll->next=temp;
	}
	else{
		pnode first=dll->next;
		
		temp->next=first;
		temp->prev=NULL;
		first->prev=temp;
		dll->next=temp;
	}
	
}
void insertLast(pnode  dll,int item){
	pnode temp=(pnode)malloc(sizeof(node));
	temp->data=item;
	if(dll->next==NULL){
		dll->next=temp;
		temp->next=NULL;
		temp->prev=NULL;
	}
	else{
		pnode i;
		i=dll->next;
		while(i->next!=NULL){
			i=i->next;
		}
		i->next=temp;
		temp->next=NULL;
		temp->prev=i;
	}
}
void deleteFirst(pnode dll){
	if(dll->next){
	pnode temp;
	temp=dll->next;
	pnode newfirst=temp->next;
	free(temp);
	newfirst->prev=NULL;
	dll->next=newfirst;
	}
}
void deleteLast(pnode dll){
	if(dll->next){
	pnode i;
	i=dll->next;
	while(i->next!=NULL){
		i=i->next;
	}
	pnode newlast=i->prev;
	newlast->next=NULL;
	free(i);
	}
}
	