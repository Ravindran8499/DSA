#include<bits/stdc++.h>
using namespace std;


int lcs(vector<vector<int>> &dp,string x,string y,int n,int m){
    if(n==0 || m == 0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(x[n-1] == y[m-1]){
        return dp[n][m] =  1+lcs(dp,x,y,n-1,m-1);
    }else{
        return dp[n][m] =  max(lcs(dp,x,y,n-1,m) , lcs(dp,x,y,n,m-1));
    }

}

int lcsDP(string x,string y,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    //Real dp
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1]; 
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
} 

int main(){
    string x = "AGGTAB";
    int n = x.length();
    string y = "GXTXAYB";
    int m = y.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            dp[i][j] = -1;
        }
    }

    cout<<lcs(dp,x,y,n,m);
    cout<<"\n";
    cout<<lcsDP(x,y,n,m);
}