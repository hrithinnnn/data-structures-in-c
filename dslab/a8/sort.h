void selectionsort(int A[], int size){
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

}