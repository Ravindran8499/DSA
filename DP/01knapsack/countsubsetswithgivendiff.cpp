#include<bits/stdc++.h>
using namespace std;

//Recursive
int countSubsetSum(int A[],int n,int sum){
    if(sum == 0){
        return 1;
    }
    if(n==0){
        return 0;
    }

    if(A[n-1] <= sum){
        return countSubsetSum(A,n-1,sum-A[n-1]) 
        +
        countSubsetSum(A,n-1,sum);
    }
    if(A[n-1] > sum){
        return countSubsetSum(A,n-1,sum);
    }
}

//Bottom up method Tabulation
int countSubsetSumDp(int A[],int n,int sum){
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int j=0;j<sum+1;j++){
        dp[0][j] = 0;
    }
    dp[0][0] = 1;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(A[i-1] <= j){
            dp[i][j] = dp[i-1][j-A[i-1]] + dp[i-1][j];
          }
          else{
            dp[i][j] = dp[i-1][j];
          }

        }
    }
    return dp[n][sum];

}


int countNumberofSubsetsWithGivenDifference(int A[],int n,int diff){
    int sum;
    int sumofArr = 0;
    for(int i=0;i<n;i++){
        sumofArr = sumofArr + A[i];
    }
    sum = (diff + sumofArr)/2;
   //return countSubsetSum(A,n,sum);
   return countSubsetSumDp(A,n,sum);


}

int main(){
   int n = 6;
   int A[] = {2,3,5,6,8,10};
   int sum = 10;
   int diff = 1;

   cout<<countSubsetSum(A,n,sum);
   cout<<"\n";
   cout<<countSubsetSumDp(A,n,sum);


}