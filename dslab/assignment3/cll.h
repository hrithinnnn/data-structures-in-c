typedef struct node* pnode;
typedef struct node{
	int data;
	pnode next;
}node;
void insertFirst(pnode cll,int item);
void insertLast(pnode cll,int item);
int deleteLast(pnode cll);
int deleteFirst(pnode cll);
void insertFirst(pnode cll,int item){
	pnode temp=(pnode)malloc(sizeof(node));
	
	temp->data=item;
	if(cll->next==NULL){
		
		temp->next=temp;
		cll->next=temp;
	}
	else{
		temp->next=cll->next->next;
		cll->next->next=temp;
	}
}
void insertLast(pnode cll,int item){
	pnode temp=(pnode)malloc(sizeof(node));
	
	temp->data=item;
	if(cll->next==NULL){
		
		temp->next=temp;
		cll->next=temp;
	}
	else{
		temp->next=cll->next->next;
		cll->next->next=temp;
	}
	cll->next=temp;
}
int deleteLast(pnode cll){
	pnode temp,last;
	int data;
	temp=cll->next;
	last=cll->next;
	if(last){
	if(last->next==last){
		cll->next=NULL;
	}
	else{
	
		while(last->next!=temp){
			last=last->next;
		}
		last->next=temp->next;
		cll->next=last;
		}
	}
	data=temp->data;
	free(temp);
	return data;
}
int deleteFirst(pnode cll){
	/*pnode temp,tofree;
	int data;
	tofree=cll->next->next;
	temp=cll->next;
	
	cll->next->next=temp->next->next;
	data=tofree->data;
	free(tofree);
	return data;*/
	if(cll->next){
	cll->next=cll->next->next;
	}
	return deleteLast(cll);
}
	