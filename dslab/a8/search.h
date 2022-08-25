int getfirstOccur(int a[], int size , int target){
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
}