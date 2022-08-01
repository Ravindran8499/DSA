#include<bits/stdc++.h>
using namespace std;




int calculate(int k,int A[],int size){
    int count = 0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(A[i]-A[j] == k || A[j]-A[i] == k){
                count++;
            }
        }
    }
    return count;
}

int  main(){
//Get Input From the user:------> Work to do
int A[] = {8,12,16,4,0,20};
int size = sizeof(A)/sizeof(A[1]);
cout<<calculate(4,A,size);


}