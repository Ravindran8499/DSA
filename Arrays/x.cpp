#include<iostream>
#include<stdio.h>
struct Array{
  int A[500];
  int length;
  int size;
};

int xyz(struct Array arr,int n){
  int count = 0;
  for(int i=0;i<n;i++){
    if(arr.A[i]>10){
      count++;
    }

  }
  printf("Count: %d",count);
}



int main(){
  struct Array arr = {{11,12,13,9,8,7,15,6,4,5,1,2},12,500};
  xyz(arr, 12);
  }