#include<bits/stdc++.h>
using namespace std;



int climbingStairs(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    if(n>2){
        return climbingStairs(n-1) + climbingStairs(n-2);
     }

}

int x(int n){
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    
}


int main(){
    cout<<climbingStairs(3);
}