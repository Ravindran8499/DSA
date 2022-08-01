#include<bits/stdc++.h>
using namespace std;


int longestCommonSubstringDp(string x , string y,int n,int m){
    int dp[n+1][m+1];
    int count = 0;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                count = max(count,dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return count;
}



int main(){
string x = "ABCDGH";
string y = "ACDGHR" ;
int n = x.length();
int m = y.length();
cout<<longestCommonSubstringDp(x,y,n,m);
}