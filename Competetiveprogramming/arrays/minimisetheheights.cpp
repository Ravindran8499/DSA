#include<bits/stdc++.h>
using namespace std;



int x(int A[], int n, int k){
    int max2 = A[0];
        for(int i=0;i<n;i++){
            if(A[i] > max2){
                max2 = A[i];
            }
        }
        int C[max2+1];
        for(int i=0;i<max2+1;i++){
            C[i] = 0;
        }
        for(int i=0;i<n;i++){
            C[A[i]]++;
        }
        int i=0;
        int j = 0;
        while(i<max2+1){
            if(C[i] > 0){
                A[j++] = i;
                C[i]--;
            }else{
                i++;
            }
        }
        
        int r = A[n-1]-A[0];
        for(i=1;i<n;i++){
            if(A[i]>=k){
                int max1 = max(A[i-1]+k,A[n-1]-k);
                int min1 = min(A[i]-k,A[0]+k);
                r = min(r,max1-min1);
            }else{
                continue;
            }
            return r;
        }
}

int main(){
    int A[] = {2, 6 ,3, 4, 7, 2, 10, 3, 2, 1};//1,2,2,2,3,3,4,6,7,10
    cout<<x(A,10,5);
    
}