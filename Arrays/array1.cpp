#include<iostream>
#include<stdio.h>
struct Array {
  int *A;
  int length;
  int size;
};

void display(struct Array arr){
  int i;
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
}
int main(){
  struct Array arr;
  int i,n;
  printf("Enter the size of the array: ");
  scanf("%d",&arr.size);
  arr.A = (int *)malloc(arr.size*(sizeof(int)));
  arr.length = 0;

  printf("Enter the number of elements: ");
  scanf("%d",&n);
  
  printf("Enter the elements of the array: ");
  for(i=0;i<n;i++){
    scanf("%d",&arr.A[i]);
  }

  arr.length = n;
  printf("\n");

  display(arr);
}
