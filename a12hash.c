// C program for the above approach
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
#define MAX_SIZE 100

void calculateSum(hashTable *t, int sum, int ans[MAX_SIZE][2]) {
	int curr = 1;
	for (int i = 0; i <= (sum - 1) / 2; i ++) {
		if (search(t,i) && search(t, sum - i)) {
			ans[curr][0] = i;
			ans[curr][1] = sum - i;
			curr ++;
		}
		//printf("%d %d", search(t, i), search(t, sum - i));
	}
	ans[curr][0] = -1;
}
int main()
{
    hashTable t;
    t = createTable();
	char ch[50];
	int ans[MAX_SIZE][2];
	int sum;
	int key;
	int size; 
	printf("Enter the size: ");
	scanf("%d", &size);
	printf("Enter the array: ");
	for (int i = 0; i < size; i ++) {
		int x; 
		scanf("%d", &x);
		insert(&t, x);
	}
	for(int j=0;j<ARRAY_SIZE;j++){
	 	printf("%d ",t.table[j]);
	 }
	 printf("\n");
	do
	{
		scanf("%s", ch);
		if (!strcmp("Insert", ch))
		{
			scanf("%d", &key);
			insert(&t, key);
		}

		else if (!strcmp("Delete", ch))
		{
			scanf("%d", &key);
			delete(&t, key);
		}
		else if (!strcmp("Sum", ch)) {
			scanf("%d", &sum);
			calculateSum(&t, sum, ans);
			printf("Sum pairs: \n");
			if (ans[1][0] == -1) {
				printf("No pairs for given sum\n");
			}
			for (int i = 1; ans[i][0] != -1; i ++) {
				printf("%d %d\n", ans[i][0], ans[i][1]);
			}
		}
		else if (!strcmp("Search", ch))
		{
			scanf("%d", &key);
			if(search(&t, key)) printf("%d Found!\n", key);
			else printf("%d Not Found!\n", key);
		}
		
		else if (!strcmp("exit", ch)) {}
		else
		{
			printf("Wrong choice, try again!\n\n");
		}
		 for(int j=0;j<ARRAY_SIZE;j++){
		 	printf("%d ",t.table[j]);
		 }
		 printf("\n");
	}while (strcmp(ch, "exit"));
	return 0;	
}

