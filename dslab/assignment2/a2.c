#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"

void reverse(pnode head);
void createSorted(pnode head, char* item);
void rotateLeft(pnode head);
void display(pnode head);

int main(void) {
    pnode head = NULL;
    head = (pnode)malloc(sizeof(node));
    strcpy(head->name, "");
    head->next = NULL;

    display(head);
    printf("%d\n",length(head));
    printf("%s","insertLast: ");
    insertLast(head, "cat");
    display(head);
    printf("%s","insertLast: ");
    insertLast(head, "mat");
    display(head);
    printf("%s","insertFirst: ");
    insertFirst(head,"rat");
    display(head);
    printf("%s","insertLast: ");
    insertLast(head, "cat");
    display(head);
    printf("%s","insertMiddle: ");
    insertMiddle(head, "cat", "bat");
    display(head);
    printf("%s\n", (search(head, "mat")==1)?"found":"not found");
    printf("%s\n", (search(head, "sat")==1)?"found":"not found");
    printf("%s\n", getData(head->next));
    printf("%d\n",length(head));
    printf("%-15s","BeforeReverse: ");
    display(head);
    printf("%s","AfterReverse: ");
    reverse(head);
    display(head);
    reverse(head);
    printf("%s","deleteMiddle: ");
    deleteMiddle(head, "cat");
    display(head);
    printf("%s","deleteFirst: ");
    deleteFirst(head);
    display(head);
    printf("%s","deleteLast: ");
    deleteLast(head);
    display(head);
    printf("%s","createSorted: ");
    createSorted(head, "pat");
    display(head);
    printf("%s","createSorted: ");
    createSorted(head, "eat");
    display(head);
    printf("%s","createSorted: ");
    createSorted(head, "ant");
    display(head);
    printf("%s","rotateLeft: ");
    rotateLeft(head);
    display(head);
}


void reverse(pnode head) {
    pnode current = head->next;
    pnode previous = NULL;
    while(current) {
   	 pnode tempNext = current->next;
   	 current->next = previous;
   	 previous = current;
   	 current = tempNext;
    }
    head->next = previous;
}

    
void createSorted(pnode head, char* item) {
    pnode current = head->next;
    pnode previous = NULL;
    while(current) {
   	 if(strcmp(getData(current), item) > 0) {
   		 if(!previous) {
   			 insertFirst(head, item);
   		 } else {
   			 insertMiddle(head, getData(previous), item);
   		 }
   		 return;
   	 }
   	 previous = current;
   	 current = current->next;
    }
    insertLast(head, item);
}


void rotateLeft(pnode head) {
    pnode firstNode = head->next;
    pnode temp;
    if(firstNode) {
   	 insertLast(head, getData(firstNode));
   	 temp = firstNode->next;
   	 deleteFirst(head);
   	 head->next = temp;
    }
}


void display(pnode head) {
    pnode current = head->next;
    while(current != NULL) {
   	 printf("%s ", current->name);
   	 current = current->next;
    }
    printf("\n");
}
