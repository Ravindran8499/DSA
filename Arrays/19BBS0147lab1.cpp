#include<iostream>
#include<stdio.h>
struct Array {
  int A[100];
  int length;
  int size;
};
int binarySearch(struct Array arr,int low,int high,int key){
  int mid = (low + high)/2;
  if(low<=high){
    
    if(key == arr.A[mid]){
      printf("%d found at %d",key,mid);
    }else if(key < arr.A[mid]){
      binarySearch(arr, low, mid-1,key);
    }else if(key>arr.A[mid]){
      binarySearch(arr,mid+1,high,key);
    }
  }
  return -1;
  printf("\n");
}

int display(struct Array arr){
  int i;
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}

int main(){

  struct Array arr = {{10,20,30,40,50,60,70,80,90,100},10,100};
  display(arr);
  binarySearch(arr,0, 9,30);
  printf("\n");
  

}