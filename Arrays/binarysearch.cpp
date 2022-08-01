#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct Array {
  int A[300];
  int length;
  int size;
  
};


int RbinarySearch(struct Array arr,int l,int h,int key){
  
  if(l<=h){
    int mid = (l+h)/2;
    int i;
    if(key == arr.A[mid]){
      printf("%d found at index %d \n",key,mid);
    }else if(key < arr.A[mid]){
      RbinarySearch( arr, l, mid-1, key);
    }else if (key > arr.A[mid]){
      RbinarySearch(arr, mid+1, h,key);
    }
  }
  return -1;

}

void display(struct Array arr){
  int i;
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}




int main(){
  struct Array arr = {{120,12,36,8,74,95,15,19,39,20,71,50,56},13,300};
  display(arr);
  RbinarySearch(arr, 0,12,36);
  printf("\n");
  
}