#include<bits/stdc++.h>
using namespace std;


int swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}



int bubbleSort(int A[],int n){
  int flag;
  for(int i=0;i<n-1;i++){
    flag=0;
    for(int j=0;j<n-1-i;j++){
      if(A[j] > A[j+1]){
        swap(&A[j],&A[j+1]);
        flag=1;
      }
    }
    if(flag == 0){
      break;
    }
  }
  cout<<"Bubble Sort: "<<"\t";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";

}

int insertionSort(int A[],int n){
  for(int i=1;i<n;i++){
    int x = A[i];
    int j=i-1;

    while( j>0 && A[j] > x){
      A[j+1] = A[j];
      j--;
    }
    A[j+1]=x;
  }
  cout<<"Insertion Sort: ";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";

}

int findMax(int A[],int n){
  int max = A[0];
  for(int i=0;i<n;i++){
    if(A[i] > max){
      max = A[i];
    }
  }
  return max;
}

int selectionSort(int A[],int n){
  int j,k;
  for(int i=0;i<n-1;i++){
    for(j=k=i;j<n;j++){
      if(A[j]<A[k]){
        k=j;
      }
    }
    swap(&A[k],&A[i]);
  }
  cout<<"Selection Sort"<<"\t";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}




int countSort(int A[],int n){
  int max,i,j;
  max = findMax(A,n);
  int C[max+1];
  for(i=0;i<max+1;i++){
    C[i] = 0;
  }
  for(i=0;i<n;i++){
    C[A[i]]++;
  }

  i=0,j=0;
  while(i<max+1){
    if(C[i] > 0){
      A[j++]=i;
      C[i]--;
    }else{
      i++;
    }
  }
  cout<<"Count Sort: "<<"\t";
  for(i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}


int partition(int A[],int low,int high){
  int pivot = A[low];
  int i=low,j=high;
  do{
    do{
      i++;
    }while(A[i]<=pivot);
    do{
      j--;

    }while(A[j]>pivot);
    
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
    j = partition(A, low,high);
    quickSort(A,low,j-1);
    quickSort(A,j+1,high);
  }
}


int mergeTwoArrays(int A[],int B[],int m,int n){
  int i,j,k;
  i=j=k=0;

  int C[m+n];
  while(i<m && j<n){
    if(A[i] < B[j]){
      C[k++] = A[i++];
    }else{
      C[k++] = B[j++];
    }
  }
  for(;i<m;i++){
    C[k++] = A[i];
  }

  for(;j<n;j++){
    C[k++] = B[j];
  }
  cout<<"Merged Two Arrays : ";
  for(int q=0;q<k;q++){
    cout<<C[q]<<"\t";
  }
  cout<<"\n";

}

int mergeInSingleArray(int A[],int low,int mid,int high){
  int i=low;
  int j = mid+1;
  int k=low;
  int C[high+1];

  while(i<=mid && j<=high){
    if(A[i] < A[j]){
      C[k++] = A[i++];
    }else{
      C[k++] = A[j++];
    }
  }
  for(;i<=mid;i++){
    C[k++] = A[i];
  }
  for(;j<=high;j++){
    C[k++] = A[j];
  }
  cout<<"Merged In Single Array: ";

  for(i=low;i<high;i++){
    cout<<C[i]<<"\t";
  }
  cout<<"\n";
}




int display(int A[],int n){
  cout<<"Original Array:"<<"\t";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}

int main(){
  int A[10] = {1,3,5,7,9,2,4,6,8,10};
  int B[5] = {2,4,6,8,10};
  
  
  // display(A,10);
  // bubbleSort(A, 10);
  // insertionSort(A,10);
  // selectionSort(A,10);
  // countSort(A,10);
  
  
  
  /*cout<<"Quick Sort: "<<"\t";  
   uncomment for QuickSort
   quickSort(A, 0, n-1);
   display(A,n);
   */


   //mergeTwoArrays(A,B,5,5);
   mergeInSingleArray(A, 0, 4, 9);



}