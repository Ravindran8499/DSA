#include<bits/stdc++.h>
using namespace std;



int isEqualSumPartition2(int A[],int n,int sum){
    //base condition
    if(sum == 0){
        return true;
    }

    if(n==0){
        return false;
    }

    if(A[n-1] <=sum){
        return isEqualSumPartition2(A,n-1,sum-A[n-1])
        ||
        isEqualSumPartition2(A,n-1,sum);
    }
    if(A[n-1] > sum){
        return isEqualSumPartition2(A,n-1,sum);
    }
}

int isEqualSumPartition1(int A[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum+A[i];
    }
    if(sum%2 == 0){
        isEqualSumPartition2(A,n,sum/2);
    }else{
        return false;
    }
}




int main(){
int N = 4;
int A[] = {1,5,11,5};
cout<<isEqualSumPartition1(A,N);
}