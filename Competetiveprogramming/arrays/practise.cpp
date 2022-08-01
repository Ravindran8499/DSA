#include<bits/stdc++.h>
using namespace std;

int num(int A[],int n,int k){
    vector<int> v;
    for(int i=0;i<n;i++){
        while(A[i] > 0){
            int r = A[i]%10;
            v.push_back(r);
            A[i] = A[i]/10;
        }
    }
    int count = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]==k){
            count++;
        }
    }
    return count;

}

int main(){
   int A[] = {11,12,13,14,15};
   int n  = sizeof(A)/sizeof(A[0]);
   int  k=1;
   cout<<num(A,n,k);

}