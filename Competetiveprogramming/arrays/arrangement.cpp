#include<bits/stdc++.h>
using namespace std;

int arrange(int A[],int n){
  int i;
  int C[n];
  for(i=0;i<n;i++){
    C[i] = A[i];
  }
  for(i=0;i<n;i++){
    A[i] =C[C[i]];
  }
  for(i=0;i<n;i++){
    cout<<A[i]<<"\t";
  }
  cout<<"\n";
}

int swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y = temp;

}

int arrangement(int A[],int n){
  for(int i=0;i<n;i++){
            int x = A[i];
            int y = A[x];
            A[i] = x + (y%n)*n;
        }
        for(int i=0;i<n;i++){
            A[i] = A[i]/n;
        }

        for(int i=0;i<n;i++){
          cout<<A[i]<<"\t";
        }
        cout<<"\n";
  }



int main(){
  int A[] = {4,0,2,1,3};
  int n = sizeof(A)/sizeof(A[0]);
  //arrange(A, n);
  arrangement(A,n);
}