#include <stdio.h>
#include "search.h"
#include "sort.h"
#define MAX_SIZE 20

/*int getfirstOccur(int a[], int size , int target){
  int low=0, high=size-1, mid , ans =-1;
  while(low<=high){
      mid = (low + high) / 2;
      if(a[mid]>= target)
      {
        if ( a[mid] == target)
          ans = mid;
        high = mid - 1;
      }
      else 
        low = mid + 1;
     
  }

  return ans;
}

int getlastOccur(int a[], int size , int target){
  int low=0, high=size-1, mid , ans =-1;
  while(low<=high){
      mid = (low + high) / 2;
      if(a[mid]> target)
      
        high = mid - 1;
      
      else 
      {
        
        if ( a[mid] == target)
          ans = mid;
        
        low = mid + 1;
      }
  }

  return ans;
}*/

int CountOnes(int a[], int size){
  int ans = getfirstOccur(a,size,1);
  if(ans == -1)
    return 0;
  return size - getfirstOccur(a,size,1); 
}

/*void selectionsort(int A[], int size){
    int temp,j;
    for(int i=0;i<size;i++){
      temp = i;
        for(j=i+1;j<size;j++){
          if(A[j]<A[temp])
            temp = j;

        }
        int temp1 = A[temp];
        A[temp]=A[i];
        A[i]= temp1;
        for(int k=0; k < size ; k++)
        printf("%d ",A[k]);
        printf("\n");

    }

}*/

int main(){
  int n;
  int num;
  int A[MAX_SIZE];
  int B[MAX_SIZE];
  int C[MAX_SIZE];
  printf("Enter number of elements for the array: ");
  scanf("%d",&n);
  int i=0;
  printf("---------Testing Binary Search---------\n");
  while(i<n){
    scanf("%d",&num);
    B[i]=num;
    i++;
  }
  char ch;
  printf("Choice: \n");
  do{
    scanf("%c",&ch);
    if(ch=='f'){
      scanf("%d",&num);
      printf("%d",getfirstOccur(B,n,num));
      printf("\n");
    }
    else if(ch=='l'){
      scanf("%d",&num);
      printf("%d",getlastOccur(B,13,53));
      printf("\n");
    }
  }while(ch!='e');
  
  printf("\nEnter number of elements for the array: ");
  scanf("%d",&n);
  int j=0;
  printf("---------Testing to count number of Occurences---------\n");
  while(j<n){
    scanf("%d",&num);
    A[j]=num;
    j++;
  }
  printf("%d",CountOnes(A,n));
  printf("\n");
  //printf("%d",getfirstOccur(B,13,18));
  //printf("\n");
  int ctrl=0;
  int k=0;
  printf("---------Testing Selection Sort---------");
  do{
    printf("\nEnter number of elements for the array: ");
    scanf("%d",&n);
    k=0;
  while(k<n){
    scanf("%d",&num);
    C[k]=num;
    k++;
  }
  selectionsort(C,n);
  ctrl++;
  }while(ctrl<3);
 return 0;
  
}
//2 34 45 47 53 53 53 53 64 64 76 89 97
//0 0 0 0 0 0 0 0 1 1 1 1 1 1
