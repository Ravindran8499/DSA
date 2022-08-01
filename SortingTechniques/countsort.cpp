#include<bits/stdc++.h>
using namespace std;

int findMax(int A[],int n){
  int max = A[0];
  for(int i=0;i<n;i++){
    if(A[i] > max){
      max = A[i];
    }
  }
  return max;
}


int countSort(int A[],int n){
  int max,i,j;
  max = findMax(A,n);
  int C[max+1];
  for(i=0;i<max+1;i++){
    C[i] =0;
  }

  for(i=0;i<n;i++){
    C[A[i]]++;
  }

  i=0,j=0;
  while(i<max+1){
    if(C[i] > 0){
      A[j++] = i;
      C[i]--;
    }else{
      i++;
    }
  }
  cout<<"Count sort: "<<"\t";
  for(i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}


int main(){
  int A[10] = {10,9,8,7,6,5,4,3,2,1};
  countSort(A,10);

}