typedef struct listNode* pnode;
typedef struct listNode {
    char name[5];
    pnode next;
}node;

void insertFirst (pnode head, char* itemName);
void insertLast(pnode head, char* itemName);
void insertMiddle(pnode head, char* key, char* itemName);
char* deleteFirst(pnode head);
char* deleteLast(pnode head);
void deleteMiddle(pnode head, char* itemName);
int length(pnode head);
int search(pnode head, char* item);
char* getData(pnode dataNode);


void insertFirst (pnode head, char* itemName) {
    pnode newNode = (pnode)malloc(sizeof(node));
    newNode->next = head->next;
    strcpy(newNode->name, itemName);
    head->next = newNode;
}


void insertLast(pnode head, char* itemName) {
    pnode newNode = (pnode)malloc(sizeof(node));
    strcpy(newNode->name, itemName);
    if(!head->next) {
   	 insertFirst(head, itemName);
   	 return;
    }
    newNode->next = NULL;
    pnode current = head->next;
    while(current->next) {
   	 current = current->next;
    }
    current->next = newNode;
}


void insertMiddle(pnode head, char* key, char* itemName) {
    pnode current = head;
    pnode lastFound = NULL;
    while(current->next) {
   	 if(strcmp(current->next->name, key) == 0) {
   		 lastFound = current;
   	 }
   	 current = current->next;
    }
    if(lastFound) {
   	 pnode newNode = (pnode)malloc(sizeof(node));
   	 strcpy(newNode->name, itemName);
   	 newNode->next = current->next;
   	 current->next = newNode;
    }
}


char* deleteFirst(pnode head) {
    if(!head->next) {
   	 return "";
    }
    char* temp = head->next->name;
    pnode tempNext = head->next->next;
    free(head->next);
    head->next = tempNext;
    return temp;
}


char* deleteLast(pnode head) {
    pnode current = head;
    while(current->next && current->next->next) {
   	 current = current->next;
    }
    char* str = current->next->name;
    free(current->next);
    current->next = NULL;
    return str;
}


void deleteMiddle(pnode head, char* itemName) {
    pnode current = head;
    while(current->next) {
   	 if(strcmp(current->next->name, itemName) == 0) {
   		 pnode temp = current->next->next;
   		 free(current->next);
   		 current->next = temp;
   		 return;
   	 }
   	 current = current->next;
    }
}


int length(pnode head) {
    int size = 0;
    pnode current = head->next;
    while(current != NULL) {
   	 current = current->next;
   	 size++;
    }
    return size;
}


int search(pnode head, char* item) {
    pnode current = head->next;
    while(current != NULL) {
   	 if(strcmp(current->name, item) == 0) {
   		 return 1;
   	 }
   	 current = current->next;
    }
    return 0;
}


char* getData(pnode dataNode) {
    if(dataNode == NULL) {
   	 return "";
    }
    return dataNode -> name;
}
