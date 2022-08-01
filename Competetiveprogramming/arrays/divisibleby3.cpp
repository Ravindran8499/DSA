#include<bits/stdc++.h>
using namespace std;

int dividible(int A[],int n){
  int i,r;
  int s=0;
  for(i=0;i<n;i++){
    while(A[i] > 0){
      r = A[i]%10;
      s = s+r;
      A[i] = A[i]/10;
    }
  }
  if(s%3==0){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  int A[] = {40,50,90};
  cout<<dividible(A,3);

}