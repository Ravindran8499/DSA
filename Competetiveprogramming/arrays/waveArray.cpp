#include<bits/stdc++.h>
using namespace std;

int swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y = temp;

}



int waveArray(int A[],int n){
  for(int i=1;i<n;i=i+2){
    if(A[i] > A[i-1]){
      swap(&A[i],&A[i-1]);
    }
    if(A[i] > A[i+1] && i<=n-2){
      swap(&A[i],&A[i+1]);
    }
  }
  cout<<"Array in Wave Form: ";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}


int main(){
  int A[] = {1 ,2, 3, 4, 5};
  waveArray(A,5);

}