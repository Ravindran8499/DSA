#include<bits/stdc++.h>
using namespace std;

int swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int selectionSort(int A[],int n){
  int j,k;
  for(int i=0;i<n-1;i++){ //for the number of passes

    for(j=k=i;j<n;j++){ /*for finding the smallest element for that position */
      if(A[j]<A[k]){
        k=j;
      }
    }
    swap(&A[i],&A[k]);  /*inside the outer for loop.
    If we want the eact iteration then we can print the array here*/
  }
  cout<<"Selection Sort: ";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}



int display(int A[],int n){
  cout<<"Original Array: ";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}

int main(){
  int A[10] = {10,9,8,7,6,5,4,3,2,1};
  display(A,10);
  selectionSort(A,10);


}