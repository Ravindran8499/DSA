#include<bits/stdc++.h>
using namespace std;

int display(int A[],int n){
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}

int mergeWithSameArray(int A[],int mid,int low,int high){
  int i,j,k;
  i=low;
  j=mid+1;
  k=low;
  int C[high+1];
  while(i<=mid && j<=high){
    if(A[i] <A[j]){
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

  for(int i=low;i<=high;i++){
    cout<<C[i]<<"\t";
  }
  cout<<"\t";

}

int main(){
  int A[10] = {2,4,6,8,10,1,3,5,7,9};
  mergeWithSameArray(A, 4, 0, 9);
}
