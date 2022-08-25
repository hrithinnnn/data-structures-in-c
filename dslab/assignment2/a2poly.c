#include <stdio.h>
#include "poly.h"
void display(node *head){
	node *first=head->next;
	if(first==NULL)
    	return;
	node *ptr=first;
	while(ptr){
    	printf("%dX^%d",ptr->coefficient,ptr->exponent);
    	if(ptr->next)
        	printf(" + ");
    	ptr=ptr->next;
	}
}

void main(){
	//poly1 and poly2 are head nodes that polyoint to the first node of the polyolynomial
	node *poly1=(node*)malloc(sizeof(node));
	poly1->next=NULL;
	insertOrder(poly1,11,1);
	insertOrder(poly1,0,1);
	insertOrder(poly1,12,1);
	//display(poly1);

	printf("\n");

	node *poly2=(node*)malloc(sizeof(node));
	poly2->next=NULL;
	insertOrder(poly2,1,2);
	insertOrder(poly2,2,2);
   // display(poly2);

	printf("\n");

	node *poly3= sumPoly(poly1,poly2);

	printf("polynomial a: ");
	display(poly1);
	printf("\n");
	printf("polynomial b: ");
	display(poly2);
	printf("\n");
	printf("sum: ");
	display(poly3);
    
}
