#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int A[],int n){
  int flag;
  for(int i=0;i<n-1;i++){  //For number of passes
    flag = 0;
    for(int j=0;j<n-1-i;j++){ // For number of Comparisons
      if(A[j] > A[j+1]){
       swap(&A[j],&A[j+1]);     
       flag =1;
      }
    }
    if(flag==0){
      break;
    }
  }
  cout<<"SortedArray : ";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}

int display(int A[],int n){
  cout<<"Given Array : ";
  for(int i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}
int main(){
  int A[10] = {1,2,3,4,5,6,7,8,9,90};
  display(A,10);
  bubbleSort(A,10);


}