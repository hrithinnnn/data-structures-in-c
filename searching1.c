#include<stdio.h>
int getfirstOccur(int a[], int size, int key);
int getlastOccur(int a[], int size, int key);

int getfirstOccur(int a[], int size, int key) {
    int l = 0, r = size - 1; 
    int mid;
    while (l < r) {
        mid = l + (r - l)/2;
        if (a[mid] >= key){ 
            if (a[mid] == key && (!mid || a[mid - 1] != key)) 
                return mid;
            r = mid;
        } 
        else l = mid + 1;   
    }
    if (a[l] == key) return l;
    return -1;
}
int getlastOccur(int a[], int size, int key) {
    int l = 0, r = size - 1; 
    int mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (a[mid] <= key){ 
            if (a[mid] == key && (mid == (size - 1) || a[mid + 1] != key)) 
                return mid;
            l = mid;
        } 
        else r = mid - 1;
    }
    if (a[l] == key) return l;
    return -1;
}
int main() {
    int n; 
    printf("\nEnter the size of the sorted array: ");
    scanf("%d", &n);

    printf("\nEnter the sorted array elements: ");
    int a[n];
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    int element;
    printf("Enter element to search: ");
    scanf("%d", &element);

    int index = getfirstOccur(a, n, element);
    if (index != -1) {
        printf("\nFirst Occurance of %d: %d", element, index);
        index = getlastOccur(a, n, element);
        printf("\nLast Occurance of %d: %d\n", element, index);
    }
    else {
        printf("\nElement not found\n");
    }
    return 0;
}
