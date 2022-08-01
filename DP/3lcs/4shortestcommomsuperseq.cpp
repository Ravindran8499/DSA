#include<bits/stdc++.h>
using namespace std;


int shortestCommomSuperSequence(string x,string y,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j ==0){
                dp[i][j] = 0;
            }
        }
    }
    
    //Normal LCS
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
            }
        }
    }
    return m+n-dp[m][n];
}




int main(){
    string X = "abcd", Y = "xycd";
    cout<<shortestCommomSuperSequence(X,Y,X.size(),Y.size());

}