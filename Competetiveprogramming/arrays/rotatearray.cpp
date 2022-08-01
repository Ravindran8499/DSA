//wrong hai

#include<bits/stdc++.h>
using namespace std;

int reverseArray(int A[],int start,int end){
    int i;
    int j;
    int temp;
    while(start < end){
        temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }

}

int rotate(int A[],int n,int d){
    reverseArray(A,0,d-1);
    reverseArray(A,d,n-1);
    reverseArray(A,0,n-1);
    
    // reverseArray(A,d,n);
    // reverseArray(A,0,n);

    for(int i=0;i<n;i++){
        cout<<A[i]<<"\t";
    }
    cout<<"\n";

}



int main(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(A[0]);
    //reverseArray(A,n);
    rotate(A,n,2);



}