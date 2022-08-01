#include<bits/stdc++.h>
using namespace std;


int UnionofTwoArrays(int A[],int B[],int m,int n){
  int i,j,k;
  i=j=k=0;
  int C[m+n];

  while(i<m && j<n){
    if(A[i] < B[j]){
      C[k++] = A[i++];
    }else if(B[j] < A[i]){
      C[k++] = B[j++];
    }else if(A[i] == B[j]){
      C[k++] = A[i++];
      j++;
    }
  }

  for(;i<m;i++){
    C[k++] = A[i];
  }
  for(;j<n;j++){
    C[k++] = B[j];
  }

  cout<<"Union of Two Arrays: :"<<"\t";
  for(i=0;i<k;i++){
    cout<<C[i]<<"\t";
  }
  cout<<"\n";
}


int intersectionOfTwoArrays(int A[],int B[],int m,int n){
  int i,j,k;
  i=k=j=0;
  int C[m+n];
  while(i<m && j<n){
    if(A[i] < B[j]){
      i++;
    }else if(B[j] < A[i]){
      j++;
    }else if(A[i] == B[j]){
      C[k++] = A[i++];
      j++;
    }
  }

  cout<<"Intersection: ";
  for(i=0;i<k;i++){
    cout<<C[i]<<"\t";
  }
  cout<<"\n";
}

int differenceofTwoArrays(int A[],int B[],int m,int n){
  int i,j,k;
  i=j=k=0;
  int C[m+n];
  while(i<m && j<n){
    if(A[i] < B[j]){
      C[k++] = A[i++];
    }else if(B[j] < A[i]){
      j++;
    }else if(A[i] == B[j]){
      i++;j++;
    }
  }
  for(;i<m;i++){
    C[k++] = A[i];
  }
  cout<<"Differrence: "<<"\t";
  for(i=0;i<k;i++){
    cout<<C[i]<<"\t";
  }
  cout<<"\n";

}

int insertAtGivenposition(int A[],int n,int x){
  int i=n-1;
  while(i>=0 && A[i] > x){
    A[i+1] = A[i];
    i--;
  }
  A[i+1] = x;
  n++;           //Because the sizeof the array increases after the insertion of the array

  cout<<"New Array : "<<"\t";
  for(i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}


int main(){
  int A[] = {1,3,5,6,9};
  int B[] = {2,4,5,6,8,10};
  int C[] = {2,1,3,6,4,9};
  int D[] = {9,0,3,6,7,4};
  UnionofTwoArrays(A,B,5,6);
  intersectionOfTwoArrays(A,B,5,6);
  differenceofTwoArrays(A, B, 5,6);
  differenceofTwoArrays(B,A,6,5);
  insertAtGivenposition(B,6,3);



}
