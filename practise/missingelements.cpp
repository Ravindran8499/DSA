#include<bits/stdc++.h>
using namespace std;

int maximum(int A[],int n){
  int max = A[0];
  for(int i=0;i<n;i++){
    if(A[i] > max){
      max = A[i];
  }
  }
  return max;
}

int minimum(int A[],int n){
  int min = A[0];
  for(int i=0;i<n;i++){
    if(A[i] < min){
      min = A[i];
    }

  }
  return min;
}
int findDuplicates(int A[],int n,int l,int h){
  int C[h];
  for(int i=0;i<h;i++){
    C[i] = 0;
  }
  for(int i=0;i<n;i++){
    C[A[i]]++;
  }

  for(int i=l;i<h;i++){
    if(C[i] > 1){
      cout<<i<<"-------"<<C[i]<<" times"<<"\n";
    }
  }
}


int main(){
  int A[] = {10,15,15,16,17,17,20,20,21,21,22,23,23,24,24,24,24};
  int n = sizeof(A)/sizeof(A[0]);
  //findMissingusingHash(A, n,10, maximum(A,n));
  findDuplicates(A, n, minimum(A,n), maximum(A,n));
  


}