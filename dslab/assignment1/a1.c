#include<stdio.h>
#include "array.h"

void insertAfterData(int a[], int key, int token);
void testSearch(int x);

int main(void) {
	int i = 0; 
	int nums[MAX_SIZE];
	char c;
	printf("enter elements separated by space, press enter to stop:");
while(i<MAX_SIZE) {
scanf("%d%c",&nums[i],&c);
if(c=='\n'){
break;
}
i++;
}
nums[++i]=SENTINEL;	
	int x;
	printf("Search test cases\n");
	printf("pos > len: ");
	x=search(nums, size(nums), 8, 10);
	testSearch(x);
	printf("pos is -ve: ");
    x=search(nums, size(nums), -2, 5);
	testSearch(x);
	printf("pos is found: ");
	x=search(nums, size(nums), 3, 15);
	testSearch(x);
    printf("pos is not found: ");
	x=search(nums, size(nums), 2, 12);
	testSearch(x);
	int key, token;
	printf("Enter the key value: ");
	scanf("%d", &key);
	printf("Enter the Token value that you want to add after every key value: ");
	scanf("%d", &token);
	insertAfterData(nums, key, token);
	printArray(nums);
	printf("Enter the key value: ");
	scanf("%d", &key);
	printf("Enter the Token value that you want to add after every key value: ");
	scanf("%d", &token);
	insertAfterData(nums, key, token);
	printArray(nums);


}
void testSearch(int x)
{
switch(x) {
		case -1:
			printf("Value not found in the array\n");
			break;
		case -2:
			printf("Starting position cannot be negative\n");
			break;		
		case -3:
			printf("Starting position must be in the bounds of the array\n");
			break;	
		default:
			printf("Value found at index %d\n", x);			
	}
}

void insertAfterData(int a[], int key, int token) {
	int length = size(a);
	int pos=0;
	do {
		int foundAt = search(a, length, pos, key);
		if(foundAt >= 0) {
			length = insertAt(a, length, foundAt+1, token);
			pos = foundAt;
			if(key==token) {
				pos++;	
			} 	
		} else {
			printf("value not found\n");
			break;
		}
	pos++;	
	}while(pos < length);
}





