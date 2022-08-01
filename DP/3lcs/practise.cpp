#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string x,string y){
    int m = x.length();
    int n = y.length();

    int dp[m+1][n+1];

    //Initialisation
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];

}

int longestCommomSubstring(string x, string y){
    int m  = x.length();
    int n = y.length();

    int count = 0;

    //Initialisation
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    //Real DP
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
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

string printLongestCommonSubsequence(string x,string y){
    int m = x.length();
    int n = y.length();

    //Initialsation
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    //Rel LCS
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
int i = m;
int j = n;
string s = "";
while(i>0 && j>0){
    if(x[i-1] == y[j-1]){
        s.push_back(x[i-1]);
        i--;
        j--;
    }else{
        if(dp[i][j-1] > dp[i-1][j]){
            j--;
        }else{
            i--;
        }
    }
}
    reverse(s.begin(),s.end());
    return s;


}

int shortestCommonSuperSequence(string x,string y){
    int m =x.length();
    int n = y.length();

    //Initialisation
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    //Real LCS
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return m+n-dp[m][n];

}


int minNumberOfOprationsToconvertStringAtoStringB(string x,string y){
    int m = x.length();
    int n = y.length();

    //Initialisation
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if( i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    //Real LCS
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    int insertions = n-dp[m][n];
    int deletions = m-dp[m][n];

   return insertions + deletions;

}

int longestPallindromicSubsequence(string x){
    string y = x;
    reverse(y.begin(),y.end());
    int n = x.length();

    int dp[n+1][n+1];
    //Initialisation
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    //REal LCS
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];

}

int minimumNumberofDeletionToMakeAPallindrome(string x){
    string y = x;
    reverse(y.begin(),y.end());
    int n = x.length();
    int dp[n+1][n+1];
    //Initialisation
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return n-dp[n][n];
}

string printShortestCommomSupersequence(string x,string y){

    int m = x.length();
    int n = y.length();

    int dp[m+1][n+1];

    //Initialisation
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i = m;
    int j = n;
    string s = "";
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }else{
            if(dp[i][j-1] > dp[i-1][j]){
                s.push_back(y[j-1]);
                j--;
            }else{
                s.push_back(x[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    
    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;
}



int main(){
    string x = "abac";
    string y = "cab";
    //cout<<LongestCommonSubsequence(x,y);
    //cout<<longestCommomSubstring(x,y);
    //cout<<printLongestCommonSubsequence(x,y);
    //cout<<shortestCommonSuperSequence(x,y);
    //cout<<minNumberOfOprationsToconvertStringAtoStringB(x,y);
    //cout<<longestPallindromicSubsequence("BBBAB");
    //cout<<minimumNumberofDeletionToMakeAPallindrome(x);
    cout<<printShortestCommomSupersequence(x,y);
    



}