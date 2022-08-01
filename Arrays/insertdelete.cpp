#include<iostream>
#include<stdio.h>
struct Array {
  int A[100];
  int length;
  int size;
};

void insert(struct Array *arr ,int index,int x){
  int i;
  if(index>=0 && index <=arr->length){
    for(i=arr->length;i>index;i--){
      
      arr->A[i] = arr->A[i-1];

    }
    arr->A[index] = x;
    arr->length++;

  }
  

}

void Append(struct Array *arr,int x)
 {
 if(arr->length<arr->size)
 arr->A[arr->length++]=x;
 }

void remove(struct Array *arr,int index){
  int x = 0;
  int i;
  for(i=index;i<arr->length-1;i++){
    x = arr->A[index];
    arr->A[i] = arr->A[i+1];
  }
  arr->length--;

}

void display(struct Array arr){
  int i;
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
}

int main(){
  struct Array arr = {{1,2,3,4,5,6,10,40,52,79},10,100};
  display(arr);
  insert(&arr,3,81);
  insert(&arr,3,90);
  insert(&arr,3,11);
  insert(&arr,3,471);
  insert(&arr,3,9);
  printf("\n");
  display(arr);
  Append(&arr, 100);
  printf("\n"); 
  remove(&arr,4);
  remove(&arr,4);
  remove(&arr,4);
  remove(&arr,4);
  display(arr);
  printf("\n");
}