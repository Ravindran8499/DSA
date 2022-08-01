#include<bits/stdc++.h>
using namespace std;


int insertionSort(int A[],int n){
  for(int i=1;i<n;i++){
    int j = i-1;
    int x = A[i];
    while(j>=0 && A[j]>x){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = x;
  }
  cout<<"Insertion Sort: ";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}

int display(int A[],int n){
  cout<<"Original Array : ";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}

int main(){
  int A[10] = {56,98,74,10,23,20,75,95,35,15};
  display(A,10);
  insertionSort(A, 10);

}