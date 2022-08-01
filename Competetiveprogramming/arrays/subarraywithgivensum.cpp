#include<bits/stdc++.h>
using namespace std;


void subArraySum(int A[],int n,int x){
    /*
    
    returns the indices of the subarray i.e start and end of the subarray
    upto which it is equal to the sum
    Google Coding
    */
    int sum =A[0];
    int start = 0;
    int end = 1;
    while(end <= n){
        if(sum == x){
            cout<<start<<"   "<<end-1<<endl;
            return;
            
        }else if(sum < x && end<n){
            sum = sum +A[end];
            end++;
        }else if(sum > x && start < end){
            sum = sum - A[start];
            start++;
        }
    }

}




int main(){
    int A[10] = {10,3,5,8,6,12,20,15,31};
    subArraySum(A,sizeof(A)/sizeof(A[0]),31);
}

