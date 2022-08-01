#include<iostream>
#include<stdio.h>
struct Array {
  int A[500];
  int length;
  int size;
};


int reverse1(struct Array arr){
  int i,j,temp;
  for(i=0,j=arr.length-1;i<=j;i++,j--){
    temp = arr.A[i];
    arr.A[i] = arr.A[j];
    arr.A[j] = temp;
  }
  printf("Reversed array is (reverse 1): ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}

int reverse2(struct Array arr){
  int *B = (int *)malloc(arr.length*sizeof(int));
  int i,j;
  for(i=arr.length-1,j=0;i>=0;i--,j++){
   B[j] = arr.A[i];
  }
  for(i=0;i<arr.length;i++){
    arr.A[i] = B[i];
  }
  printf("reversed ayyay is(reverse 2) : ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}

int display(struct Array arr){
  int i;
  printf("Given array is : ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}
int main(){
  struct Array arr = {{14,25,36,74,85,96,40,50,60,12},10,500};
  display(arr);
  reverse1(arr);
  reverse2(arr);

}