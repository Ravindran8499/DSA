#include<bits/stdc++.h>
using namespace std;

int reverseArryInGroups(int A[],int n,int k){
    int i;
    for(i=0;i<n;i=i+k){
        int start = i;
        int end = min(i+k-1,n-1);
        while(start< end){
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
            start++;
            end--;
        }
    }
    for (i=0;i<n;i++) {
        cout<<A[i]<<"\t";
    }
    cout<<"\n";
    

}


int main(){
    int A[] = {1,2,3,4,5,6,7};
    int n = sizeof(A)/sizeof(A[0]);
    int k=3;
    reverseArryInGroups(A,n,k);

}