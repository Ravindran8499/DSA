#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==1 || n==0){
        return n;
    }
    else return fib(n-1) + fib(n-2);
}



int fibMemo(int n){
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    else return  dp[n] = fib(n-1) + fib(n-2);

}

int main(){
    cout<<fib(5)<<endl;
    cout<<fibMemo(5);
}