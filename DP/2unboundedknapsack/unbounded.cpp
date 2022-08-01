#include<bits/stdc++.h>
using namespace std;




int unboundedKnapsackRecursive(int wt[],int val[],int w,int n){
    if(w == 0 || n == 0){
        return 0;
    }

    if(wt[n-1] <= w){
        return max(val[n-1] +  unboundedKnapsackRecursive(wt,val,w-wt[n-1],n)
         ,
         unboundedKnapsackRecursive(wt,val,w,n-1));
    }else{
         return unboundedKnapsackRecursive(wt,val,w,n-1);
    }

}

int unboundedKnapsackDP(int wt[],int val[],int w,int n){
     int dp[n+1][w+1];
        
        //BAse condition
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]]    , dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
}

int main(){

int  N = 4;
int W = 8;
int val[] = {1,4,5,7};
int wt[] = {1,3,4,5};

cout<<unboundedKnapsackRecursive(wt,val,W,N);
cout<<"\n";
cout<<unboundedKnapsackDP(wt,val,W,N);
}