#include<bits/stdc++.h>
using namespace std;


/* This Sum is also called as perfect sum  */


//Memoised version
int countNoOfSubsetsWithEqualSum(int A[],int n,int sum,vector<vector<int>> &dp){
    //Base Condition
    if(sum == 0){
        return 1;
    }
    
    //Base Condition
    if(n==0){
        return 0;
    }

    //Dp Condition
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }

    //Choice Diagram
    if(A[n-1] <=sum){
        return dp[n][sum] = countNoOfSubsetsWithEqualSum(A,n-1,sum-A[n-1],dp) 
        +
        countNoOfSubsetsWithEqualSum(A,n-1,sum,dp); 
    }

    //Choice Diagram
    if(A[n-1] > sum){
        return dp[n][sum] = countNoOfSubsetsWithEqualSum(A,n-1,sum,dp);
    }
}

//Bottom up approach (Tabulation method)

int countNoOfSubsetsWithEqualSum2(int A[],int n,int sum){
    int dp[n+1][sum+1];
    
    //Base condition converted to initialisation
    for(int j=0;j<sum+1;j++){
        dp[0][j] = 0;
    }
    dp[0][0] = 1;

    //Bottom up approach
    /* In bottom up approach we donot need to pass the array as a paramater as we do in memoisation
       Just take the array and do the sum.
    */
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(A[i-1] <= j ){
            dp[i][j] = dp[i-1][j-A[i-1]] +  dp[i-1][j];
            }
            if(A[i-1] > j){
            dp[i][j] =  dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}





int main(){
   int n = 5;
   int A[] = {1,2, 3, 4,5};
   int sum = 10;
   vector<vector<int>> dp(n+1,vector<int>(sum+1));
   for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        dp[i][j] = -1;
    }
   }
   cout<<countNoOfSubsetsWithEqualSum(A,n,sum,dp);
   cout<<"\n";
   cout<<countNoOfSubsetsWithEqualSum2(A,n,sum);
}