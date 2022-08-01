#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[] = {1,2,6,9,510,23,7};
    int n = sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n-1;i++){
        if(i<n-1){
            A[i+1] = A[i];
        }else{
            A[0]=A[n];
        }
    }
    for(int i=0;i<n;i++){
        cout<<A[i];
    }
}