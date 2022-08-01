#include<bits/stdc++.h>
using namespace std;

   int knapSack2(int w, int wt[], int val[], int n,int dp[][w]){
        //base Condition
        if(n==0 || w==0){
            return dp[n][w] = 0;
        }
        
        //DP condition
        if(dp[n][w]!=-1){
            return dp[n][w];
        }
        
        if(wt[n-1] <= w){
            dp[n][w] = max(values[n-1]+knapSack2(w-wt[n-1],wt,val,n-1,dp),
            knapSack2(w,wt,val,n-1,dp));
            return dp[n][w];
        }
        if(wt[n-1] >w){
            dp[n][w] = knapSack2(w,wt,val,n-1,dp);
            return dp[n][w];
        }
        
        
    }
    
    
    int knapSack(int w, int wt[], int val[], int n) {
        //Base Condition
        // if(n==0 || w==0){
        //     return 0;
        // }
        // if(wt[n-1] <= w ){
        //     return max(val[n-1] + knapSack(w-wt[n-1],wt,val,n-1),knapSack(w,wt,val,n-1));
        // }
        // if(wt[n-1] > w){
        //     return knapSack(w,wt,val,n-1);
        // }
        int dp[n+1][w+1];
        memset(dp,-1,sizeof(dp));
        return knapSack2(w,wt,val,n,dp);
    }

int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    //cout<<knapsack(wt,val,W,n);
    cout<<knapSack(W,wt,val,n);

}