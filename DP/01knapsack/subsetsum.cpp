#include<bits/stdc++.h>
using namespace std;

int recursiveSubsetSubsetSum2(int A[],int n,int sum,vector <vector <int> > &dp){

    if(sum == 0){
        return dp[n][sum] = true;
    }
    if(n == 0){
        return dp[n][sum] = false;
    }

    if(dp[n][sum]!=-1){
        return true;
    }

    if(A[n-1] <= sum){
        return dp[n][sum]=recursiveSubsetSubsetSum2(A,n-1,sum-A[n-1],dp)
         || 
         recursiveSubsetSubsetSum2(A,n-1,sum,dp);
    }
    if(A[n-1] > sum){
        return dp[n][sum] = recursiveSubsetSubsetSum2(A,n-1,sum,dp);
    }

}




int recursiveSubsetSum(int A[],int n,int sum){
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            dp[i][j] = -1;
        }
    }
    return recursiveSubsetSubsetSum2(A,n,sum,dp);
}

int main(){
    int A[] = {3,34,4,12,5,2};
    int sum = 93;
    int n = 6;
    cout<<recursiveSubsetSum(A,n,sum);
}