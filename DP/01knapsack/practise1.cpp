#include<bits/stdc++.h>
using namespace std;
/* 

Everything relate to 0 / 1 knapsack is here

*/


/*
 0/1 Knapsack
 Q1) Problem statement:-You are given weights and values of N items, 
 put these items in a knapsack of capacity W to get the maximum total value in the 
 knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and 
weights associated with N items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum 
value subset of val[] such that sum of the weights of this subset 
is smaller than or equal to W. You cannot break an item, either pick the complete 
item or dont pick it (0-1 property).

*/

int knapSackRecursive(int wt[],int val[],int n,int w){
    //Base condition
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1]<=w){
        return max(val[n-1] + knapSackRecursive(wt,val,n-1,w-wt[n-1])
        ,
        knapSackRecursive(wt,val,n-1,w));
    }
    else{
        return knapSackRecursive(wt,val,n-1,w);
    }

}

int knapSackDp(int wt[],int val[],int n,int w){
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    /*
    Initialisation
    All the 'n' will be converted to 'i' and all the 'w'
    will be converted to 'j'

    */

    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1] <=j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}



/*
  Subset Sum:
   Q2)Problem Statement :- Given an array of non-negative integers, and a value sum, 
   determine if there is a subset of the given set with sum equal to given sum.  
   Return true if present else return false.
 */
int subsetSumRecursive(int A[],int n,int sum){
    //Base Condition
    if(sum == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }

    if(A[n-1] <= sum){
        return subsetSumRecursive(A,n-1,sum-A[n-1]) || subsetSumRecursive(A,n-1,sum) ;
    }
    if(A[n-1] > sum){
        return subsetSumRecursive(A,n-1,sum);
    }

}

int subsetSumDP(int A[],int n,int sum){
    //Recursion gets converted to Initialisation in bottom up
    int dp[n+1][sum+1];
    for(int j=0;j<sum+1;j++){
        dp[0][j] = 0;
    }
    dp[0][0] = 1;

    //Recursion gets converted to iteration in DP
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(A[i-1] <=j){
            dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];

}


/*
 Equal Sum partition
 Q3)Problem Statement:-Given an array arr[] of size N, 
 check if it can be partitioned into two parts such that the sum 
 of elements in both parts is the same.

*/
int EqualSumpartition(int A[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + A[i];
    }
    if(sum%2!= 0){
        return false;
    }
    else{
        subsetSumDP(A,n,sum/2);
    }

}


/*
 Count of subset Sum
 Q4)Problem Statement:-Count the number of subsets sum  equals to given sum:-
 Also called as perfect sum.
*/

int countOfSubsetsSum(int A[],int n,int sum){
    int dp[n+1][sum+1];
    
    //Base Condition
    for(int j=0;j<sum+1;j++){
        dp[0][j] = 0;
    }
    dp[0][0] = 1;

    //Recursive solution get converted to iterative
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(A[i-1]<=j){
                dp[i][j] = dp[i-1][j-A[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];

}

/*
 Minimum subset Sum difference
 Q5)Given an integer array arr of size N, the task is to divide it into two 
 sets S1 and S2 such that the absolute difference between their sums is minimum 
 and find the minimum difference
 Hint Take vector and store the last row of the matrix.
*/

int minimumDifference(int A[],int n){
    //Sum of the array
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum +A[i];
    }

    vector<vector<bool>> dp(n+1,vector<bool>(sum + 1));

    //Base condition changes to initialisation in Dp
    for(int j=0;j<sum+1;j++){
        dp[0][j] = false;
    }
    dp[0][0] = true;

    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(A[i-1] <= j){
                dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    vector<int>v;
    for(int j=0;j<sum+1;j++){
        if(dp[n][j]==true){
            v.push_back(j);
        }
    }

    int s = 1e9;
    for(int i=0;i<v.size();i++){
        s = min(s,abs(sum - 2*v[i]));
    }

    return s;

}


/*
Q6) Number of subsets with givben difference or Target sum.

*/

int targetSum(int A[],int n,int diff){
    int sumofArray = 0;
    for(int i=0;i<n;i++){
        sumofArray+=A[i];
    }

    int sum = (sumofArray + diff) /2;
    return subsetSumDP(A,n,sum);
}



int main(){ 

    int n = 4;
    int A[] = {1,1,2,3};
    int diff = 1;

    // n = 3;
    // int w = 4;
    // int values[] = {1,2,3};
    // int weight[] = {4,5,1};

    //cout<<subsetSumRecursive(A,n,sum);
    //cout<<"\n";
    //cout<<subsetSumDP(A,n,sum);
    // cout<<knapSackRecursive(weight,values,n,w);
    // cout<<"\n";
    // cout<<knapSackDp(weight,values,n,w);
    //cout<<EqualSumpartition(A,n);
    //cout<<countOfSubsetsSum(A,n,sum);
    //cout<<minimumDifference(A,n);
    cout<<targetSum(A,n,diff)<<endl;
}


