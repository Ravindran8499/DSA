#include<iostream>
#include<stdio.h>

struct Array {
  int A[500];
  int length;
  int size;
};

struct Array* Merge(struct Array arr1,struct Array arr2)
{
 int i,j,k;
 i=j=k=0;
struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

 while(i<arr1.length && j<arr2.length)
 {
 if(arr1.A[i]<arr2.A[j]){
   arr3->A[k++]=arr1.A[i++];
   }
  
 else{
   arr3->A[k++]=arr2.A[j++];
   }
 }
 
 
 for(;i<arr1.length;i++){
   arr3->A[k++]=arr1.A[i];

 }
  
 for(;j<arr2.length;j++){
   arr3->A[k++]=arr2.A[j];
   
 }
 
 arr3->length = arr1.length + arr2.length;
 

 printf("The given array is : ");
 for(i=0;i<arr3->length;i++){
   printf("%d\t",arr3->A[i]);
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
  struct Array arr1 = {{10,20,13,48,25,36,40},7,500};
  struct Array arr2 = {{70,30,52,15},4,500};
  display(arr1);
  display(arr2);
  Merge(arr1,arr2);

}
