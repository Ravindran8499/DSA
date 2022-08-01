#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct Array {
  int A[300];
  int length;
  int size;
};

void swap(int *x,int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}


int linearSearch(struct Array *arr,int key){
  int i;
  for(i=0;i<arr->length;i++){
    if(key == arr->A[i]){
      printf("%d found at %d\n",key,i);
      swap(&arr->A[i],&arr->A[0]);
      
    }
  }
}


void display(struct Array arr){
  int i;
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}


int main(){
  struct Array arr = {{10,25,36,14,19,78,12,03,65,97,2,49},12,300};
  display(arr);
  linearSearch(&arr, 78);
  display(arr);


}