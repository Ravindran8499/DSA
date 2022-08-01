#include<bits/stdc++.h>
using namespace std;


//Knapsack recursive solition
int knapsackRecursive(vector<vector<int>> &dp, int wt[],int val[],int n,int w){

    //Base condition
    if(n == 0 || w == 0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    //Choice diagram
    if(wt[n-1] <= w){
        return  dp[n][w] = max(val[n-1] +  knapsackRecursive(dp,wt,val,n-1,w-wt[n-1]) , 
                   knapsackRecursive(dp,wt,val,n-1,w));
    }else{
        return dp[n][w] = knapsackRecursive(dp,wt,val,n-1,w);
    }
}

int knapsackDp(int wt[],int val[],int n,int w){
    vector<vector<int>>dp(n+1,vector<int>(w+1));
    
    //initialisation
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;   //1st row and 1st col
            }
        }
    }
    //real Dp
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]]      ,dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int subsetSumRecursive(vector<vector<int>> &dp ,int A[],int n,int sum){
    if(sum == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }

    if(A[n-1] <= sum){
        return dp[n][sum] = subsetSumRecursive(dp,A,n-1,sum-A[n-1]) || subsetSumRecursive(dp,A,n-1,sum);
    }else{
        return dp[n][sum] = subsetSumRecursive(dp,A,n-1,sum);
    }

}

int subsetSumDp(int A[],int n,int sum){
    int dp[n+1][sum+1];

    //Initialisation

    for(int j=0;j<sum+1;j++){
        dp[0][j] = 0;
    }
    dp[0][0] = 1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(A[i-1] <=j){
                dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];

}
int equalSumPartition(int A[],int n){
    int sumofArray = 0;
    for(int i=0;i<n;i++){
        sumofArray+=A[i];
    }
    if(sumofArray%2 == 0){
        return subsetSumDp(A,n,sumofArray/2);
    }else{
        return false;
    }
}

int countofSubsetSum(int A[],int n,int sum){
    
    //Initialisation
    int dp[n+1][sum+1];
    for(int j=0;j<sum+1;j++){
        dp[0][j] = 0;
    }
    dp[0][0] = 1;

    //Real Dp
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(A[i-1] <=j){
                dp[i][j] = dp[i-1][j-A[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];

}

//Using extra vector
int minimumSubsetSumDifference(int A[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=A[i];
    }
    bool dp[n+1][sum+1];

    //initialisation
    for(int j=0;j<sum+1;j++){
        dp[0][j] = false;
    }
    dp[0][0] = true;

    //Real Dp
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(A[i-1] <= j){
                dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> v;
    for(int j=0;j<sum+1;j++){
        if(dp[n][j] == true){
            v.push_back(j);
        }
    }

    int s1 = 1e9;
    for(int i=0;i<sum/2;i++){
        s1 = min(s1,abs(sum - 2*v[i]));
    }
    return s1;
}


int main(){
int n = 2;
int w = 4;
int A[] = {1,4};
int sum = 10;
int values[] = {1,2,3};
int weight[] = {4,5,1};
vector<vector<int>>dp(n+1 , vector<int>(sum+1));
for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        dp[i][j] = -1;
    }
}

// cout<<knapsackRecursive(dp,weight,values,n,w);
// cout<<"\n";
// cout<<knapsackDp(weight,values,n,w);
// cout<<subsetSumRecursive(dp,A,n,sum);
// cout<<"\n";
// cout<<subsetSumDp(A,n,sum);
// cout<<"\n";
// cout<<equalSumPartition(A,n);
//cout<<countofSubsetSum(A,n,sum);
cout<<minimumSubsetSumDifference(A,n);

}
