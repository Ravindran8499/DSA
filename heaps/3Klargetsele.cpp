#include<bits/stdc++.h>
using namespace std;


vector<int> kLargestElements(int A[],int n,int k){
    priority_queue<int , vector<int> ,greater<in>>  minh;
    for(int i=0;i<n;i++){
        minh.push(A[i]);
        if(minh.size() > k){
            minh.pop();
        }
    }

    vector<int> v;
    while(!minh.empty()){
        v.push_back(minh.top());
        minh.pop();
    }
    return v;
}

int main(){
int n = 5

int k = 2;
int A[] = {12, 5, 787, 1, 23};
cout<<kLargestElements(A,n,k);
   
}