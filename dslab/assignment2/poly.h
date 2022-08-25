#include <stdlib.h>
typedef struct poly{
	int exponent;
	int coefficient;
	struct poly *next;
}node;


void insertOrder(node *head,int exp,int coeff){
	node *first=head->next;
	node *temp=(node*)malloc(sizeof(node));
	temp->coefficient=coeff;
	temp->exponent=exp;
	temp->next=NULL;

	if(first==NULL){
    	head->next=temp;
    	return;
	}

	if(first->exponent<temp->exponent){
    	temp->next=first;
    	head->next=temp;
    	return;
	}

	node *prev=NULL;
	node *curr=first;
	while(curr&&curr->exponent>=temp->exponent){
    	prev=curr;
    	curr=curr->next;
	}

	if(prev->exponent==temp->exponent){
    	prev->coefficient+=temp->coefficient;
    	return;
	}

	prev->next=temp;
	temp->next=curr;
}

void addNode(node *poly,int exp,int coeff){
	node *temp=(node*)malloc(sizeof(node));
	temp->coefficient=coeff;
	temp->exponent=exp;
	temp->next=NULL;
	poly->next=temp;
}

node *sumPoly(node *h1,node *h2){
	node *f1=h1->next;
	node *f2=h2->next;

	node *h3=(node*)malloc(sizeof(node));
	h3->next=NULL;
	node *ptr3=h3;

	node *ptr1,*ptr2;

	if(f2==NULL&&f1==NULL){
    	return h3;
	}

	if(f1==NULL)
    	return h2;

	if(f2==NULL)
    	return h1;

	ptr1=f1;
	ptr2=f2;

	node *temp=(node*)malloc(sizeof(node));

	while(ptr1&&ptr2){
    	if(ptr1->exponent>ptr2->exponent){
        	addNode(ptr3,ptr1->exponent,ptr1->coefficient);
        	ptr3=ptr3->next;
        	ptr1=ptr1->next;
    	}
    	else if(ptr2->exponent>ptr1->exponent){
        	addNode(ptr3,ptr2->exponent,ptr2->coefficient);
        	ptr3=ptr3->next;
        	ptr2=ptr2->next;
    	}
    	else{
        	addNode(ptr3,ptr1->exponent,ptr1->coefficient+ptr2->coefficient);
        	ptr3=ptr3->next;
        	ptr2=ptr2->next;
        	ptr1=ptr1->next;
    	}
	}
	while(ptr1){
    	addNode(ptr3,ptr1->exponent,ptr1->coefficient);
    	ptr3=ptr3->next;
    	ptr1=ptr1->next;
	}
	while(ptr2){
    	addNode(ptr3,ptr2->exponent,ptr2->coefficient);
    	ptr3=ptr3->next;
    	ptr2=ptr2->next;
	}

	return h3;
}

int coeff(node *head,int exp){
	node *first=head->next;
	node *ptr=first;
	if(ptr==NULL)
    	return 0;

	while(ptr){
    	if(ptr->exponent==exp)
        	return ptr->coefficient;
   	 
    	ptr=ptr->next;
	}
	return 0;
}
