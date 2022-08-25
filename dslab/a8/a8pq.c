#include<stdio.h>
#include"heap.h"

int bpllimit(heapptr pq,float limit,float res[]){
  int i=0;
   while(getroot(pq)<=limit){
    res[i++]=deleteMin(pq);
  }
  return i;
}
int main(){
  float arr[MAX_SIZE];
  float res[MAX_SIZE];
  char ch;
  int n,i=0;
  float num,limit;
  printf("Enter number of families: ");
  scanf("%d",&n);
  do{
    scanf("%c",&ch);
    if(ch=='i'){
      scanf("%f",&num);
      arr[i++]=num;
    }
    heapptr pq=buildHeap(arr, i);
  }while(i<n);
  heapptr pq=buildHeap(arr, n);
  printHeap(pq);
  printf("\nEnter BPL limit: ");
  scanf("%f",&limit);
  int ct=bpllimit(pq,limit,res);
  for(int j=0;j<ct;j++){
    printf("%.2f ",res[j]);
  }
  printf("\n");
  printHeap(pq);

  return 0;
}

/*
i 1.7
i 4.3
i 7.8
i 1.5
i 5.6
i 2.5
i 8
i 1
i 0.7
i 1.5
*/