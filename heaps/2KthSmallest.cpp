#include<bits/stdc++.h>
using namespace std;


int KthSmallest(int A[],int n,int k){
    priority_queue<int> maxh;
    for(int i=0;i<n;i++){
        maxh.push(A[i]);
        if(maxh.size() > k){
            maxh.pop();
        }
    }
    return maxh.top();
}


int main(){
    int A[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(A)/sizeof(A[0]);
    int k = 3;
    cout<<KthSmallest(A,n,k);
}