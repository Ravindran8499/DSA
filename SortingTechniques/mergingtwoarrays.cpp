#include<bits/stdc++.h>
using namespace std;


int merge(int A[],int B[],int m,int n){
  int i,j,k;
  i=j=k=0;
  int C[m+n];
  while(i<m && j<n){
    if(A[i] <B[j]){
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
  for(int q=0;q<k;q++){
    cout<<C[q]<<"\t";
  }
  cout<<"\n";
}


int main(){
  int A[5] = {2,4,6,8,10};
  int B[5] = {1,3,5,7,9};
  int m = 5;
  int n = 5;
  merge(A,B,5,5);
}