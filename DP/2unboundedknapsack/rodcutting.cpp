#include<bits/stdc++.h>
using namespace std;


int rodCuttingDP(int price[],int n){
    vector<int>length(n);
    for(int i=0;i<n;i++){
        length[i] = i+1;
    }

    int dp[n+1][n+1];
    
    //Basic Initialisation
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    //Real DP
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(length[i-1] <= j ){
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]]   , dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }

    }
    return dp[n][n];
}




int main(){
int N=8;
int Price[] = {3, 5, 8, 9, 10, 17, 17, 20};
int length[] = {1,2,3,4,5,6,7,8};
cout<<rodCuttingDP(Price,N);
}