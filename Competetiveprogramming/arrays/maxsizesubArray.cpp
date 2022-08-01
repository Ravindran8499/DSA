#include<bits/stdc++.h>
using namespace std;


int maxSumSubArray(int A[],int n,int k,int x){
  int sum=0;
  int ans=0;
  for(int i=0;i<k;i++){
    sum+=A[i];
  }
  if(sum < x){
    ans = sum;
  }

  for(int i=k;i<n;i++){
    sum = sum-A[i-k];
    sum = sum +A[i];
    if(sum < x){
      ans = max(sum,ans);
    }
  }
  cout<<"Max size: "<<ans;

}





int main(){
  int A[] = {7,5,4,6,8,9};
  maxSumSubArray(A,6,3,20);

}