#include<limits.h>
#include<stdio.h>

#define MAX_SIZE 100
#define SENTINEL -1

int size(int a[]) {
	int i = 0;
	while (a[i] != SENTINEL) {
		i++;
	}
	return i; 
}

int insertAt(int a[], int size, int pos, int data) {
	if (size - pos>= 0 && pos >= 0) { 
		size++;
    	for (int i = size-1; i >= pos + 1; i--)
        	a[i] = a[i - 1];
		a[pos] = data;
		a[size] = -1;
	}
	return size;
}

int search(int a[], int sizeOfArr, int pos, int key) {
	if(pos < 0) { 
		return -2;
	}
	if(sizeOfArr - pos < 0) { 
		return -3;
	}
	for(int i = pos; i < sizeOfArr; i++) {
		if(a[i] == key) {
			return i;
		}
	}
	return -1; 
	
}

void printArray(int a[]) {
	int s = size(a);
	printf("a  ");
	for(int i = 0; i < s; i++) {
		printf("%6d", i);
	}
	printf("\n   ");
	for(int i = 0; i < s; i++) {
		printf("%6d", a[i]);
	}
	printf("\n");

}

int nums[MAX_SIZE];

