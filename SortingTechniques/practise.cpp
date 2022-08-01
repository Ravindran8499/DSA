#include<bits/stdc++.h>
using namespace std;


int mergeTwoArrays(int A[],int B[],int m,int n){
  int i,j,k;
  i=j=k=0;
  int C[m+n];
  while(i<m && j<n){
    if(A[i] <A[j]){
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
  cout<<"Merged Array: "<<"\t";
  for(i=0;i<k;i++){
    cout<<C[i]<<"\t";
  }
  cout<<"\n";
}


int main(){
  int A[5] = {2,4,6,8,10};
  int m = sizeof(A)/sizeof(A[0]);
  int B[5] = {1,3,5,7,9};
  int n = sizeof(B)/sizeof(B[0]);
  mergeTwoArrays(A, B, m, n);

}