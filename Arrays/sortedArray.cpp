#include<iostream>
#include<stdio.h>

struct Array {
  int A[100];
  int length;
  int size;

};


int swap(int *x,int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}


int insertIntoSortedArray(struct Array *arr,int x){
  int i = arr->length-1;
  while(i>=0 & arr->A[i]>x){
    arr->A[i+1] = arr->A[i];
    i--;
  }
  arr->A[i+1] = x;
  arr->length++;
  printf("New array is : ");
  for(i=0;i<arr->length;i++){
    printf("%d\t",arr->A[i]);
  }
  printf("\n");
}

int reverseArray(struct Array arr){
  int i,j,temp;
  for(i=0,j=arr.length-1;i<=j;i++,j--){
    temp = arr.A[i];
    arr.A[i] = arr.A[j];
    arr.A[j] = temp;

  }
  printf("Reversed array is : ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
}

int negativesort(struct Array arr){
  int i,j;
  i = 0,j = arr.length-1;
  while (i<j){
    while(arr.A[i]<0){
      i++;
    }
    while (arr.A[j]>=0){
      j--;
    }
    if(i<j){
      swap(&arr.A[i],&arr.A[j]);
    }
  }
  printf("Array: ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}


int display(struct Array arr){
  int i;
  printf("Given array is: ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}

int main(){
  struct Array arr = {{-23,12,10,-24,45,46,57,68,79,-80},10,300};
  display(arr);
  insertIntoSortedArray(&arr,42);
  insertIntoSortedArray(&arr,100);
  insertIntoSortedArray(&arr,2);
  negativesort(arr);
  

}