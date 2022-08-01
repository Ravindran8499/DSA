#include<bits/stdc++.h>
using namespace std;
int sortedSquares(int A[],int n){
  int B[n];
  for(int i=0;i<n;i++){
    B[i] = A[i]*A[i];
  }
  

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(B[j] > B[j+1]){
        int temp = B[j];
        B[j] =B[j+1];
        B[j+1] = temp;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<B[i]<<"\t";
  }
  cout<<"\n";
  return 0;
}

int main(){
  int  v[] = {-4,-1,0,3,10};
  int n = sizeof(v)/sizeof(v[0]);
  sortedSquares(v,n);

}
