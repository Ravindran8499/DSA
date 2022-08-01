#include<stdio.h>
#include<iostream>




int max(int array[],int n){
  int i;
  int max = 0;
  for(i=0;i<n;i++){
    if(array[i]>max){
      max = array[i];
    }

  }
  
}



int main(){
  int n,array[n],i;
  printf("Enter the size of the array");
  scanf("%d",&n);
  printf("Enter the elements of the array\n");
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  max(array,n);
}