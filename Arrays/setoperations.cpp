#include<iostream>
#include<stdio.h>
struct Array {
  int A[500];
  int length;
  int size;
};


struct Array * union1(struct Array *arr1 ,struct Array *arr2){
 int i = 0,j = 0,k = 0;
struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j]){
      arr3->A[k++] = arr1->A[i++];
    }else if(arr1->A[j]<arr2->A[i]){
      arr3->A[k++] = arr2->A[j++]; 
    }else {
      arr3->A[k++] = arr1->A[i++];
      j++;
    }
  }
  for(;i<arr1->length;i++){
    arr3->A[k++] = arr1->A[i]; 

  }
  
  for(;j<arr2->length;j++){
    arr3->A[k++] = arr1->A[j]; 

  }
  arr3->length =k;
  printf("Union of two arrays is : ");
  for(i=0;i<arr3->length;i++){
    printf("%d\t",arr3->A[i]);
  }
  printf("\n");

}




struct Array *intersection(struct Array arr1,struct Array arr2){
  int i = 0;int j = 0;int k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  while(i<arr1.length && j<arr2.length){
    if(arr1.A[i]<arr2.A[j]){
      i++;
    }else if(arr2.A[j]<arr1.A[i]){
      j++;
    }
    else if(arr1.A[i] == arr2.A[j]){
      arr3->A[k++] = arr1.A[i++];
    }
  }
  arr3->length = k;
  printf("Intersection: ");
  for(i=0;i<arr3->length;i++){
    printf("%d\t",arr3->A[i]);
  }
  printf("\n");

}



struct Array *difference(struct Array arr1,struct Array arr2){
  int i = 0,j = 0,k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  while(i<arr1.length && j<arr2.length){
    if(arr1.A[i]<arr2.A[j]){
      arr3->A[k++]  = arr1.A[i++];
    }else if(arr2.A[j]<arr1.A[i]){
      j++;
    }else if(arr1.A[i] == arr2.A[j]){
      i++;
      j++;
    }
  
  }
  for(;i<arr1.length;i++){
    arr3->A[k++]=arr1.A[i];
    }
 
  


  arr3->length = k;
  printf("Difference : ");
  for(i=0;i<arr3->length;i++){
    printf("%d\t",arr3->A[i]);
  }
  printf("\n");


}



int display(struct Array arr){
  int i;
  printf("The given array is : ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}




int main(){
  struct Array arr1 = {{10,13,12,17,18,20,22,28},8,500};
  struct Array arr2 = {{11,13,15,17,18,19,28},7,500};
  display(arr1);
  display(arr2);
  union1(&arr1,&arr2);
  difference(arr1,arr2);
  intersection(arr1,arr2);
  
}