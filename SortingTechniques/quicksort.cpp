#include<bits/stdc++.h>
using namespace std;

int display(int A[],int n){
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}

int swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int A[],int low,int high){
  int i=low,j=high;
  int pivot = A[low];
  do{
    do{
      i++;
    }while(A[i]<=pivot);

    do{
      j--;

    }while(A[j] > pivot);
    if(i<j){
      swap(&A[i],&A[j]);
    }

  }while(i<j);
  swap(&A[low],&A[j]);
  return j;

}

int quickSort(int A[],int low,int high){
  int j;
  if(low<high){
    j = partition(A,low,high);
    quickSort(A,  low, j);
    quickSort(A,  j+1, high);
  }
}




int main(){
  int A[] = {10,9,8,7,6,5,4,3,2,1};
  int n = 10;
  display(A,10);
  quickSort(A, 0, n-1);
  display(A,10);

}
