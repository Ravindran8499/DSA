#include<bits/stdc++.h>
using namespace std;


int maxsubArraysum(int A[],int n){
    int current = 0;
    int maxTillNow = INT16_MIN;
    for(int i=0;i<n;i++){
        current+=A[i];
        maxTillNow = max(current,maxTillNow);
        if(current<0){
            current = 0;
        }
    }
    return maxTillNow;
}


int main(){
    int A[] = {-1,-2,-3,-4};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<maxsubArraysum(A,n);

}