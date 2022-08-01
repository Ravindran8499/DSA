#include<iostream>
#include<stdio.h>

struct Array {
  int A[500];
  int length;
  int size;
};
 int swap(int *x,int *y){
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
 }

int positiveTogether(struct Array arr){
  int i = 0;int j = arr.length-1;
  while(i<j){
    while(arr.A[i]<0){
      i++;
    }
    while(arr.A[j]>0){
      j--;
    }
    if(i<j){
      swap(&arr.A[i],&arr.A[j]);
    }
  }
  printf("New Array is : ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
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
  struct Array arr = {{-1,50,62,-74,-12,-96,85,36,71,70,-21,-3},12,500};
  display(arr);
  positiveTogether(arr);
}
