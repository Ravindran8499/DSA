#include<iostream>
#include<stdio.h>
struct Array {
  int A[500];
  int n;

};

void set(struct Array *arr,int i,int j,int x){
  if(i==j){
    arr->A[i-1] = x;
  }
}
 

int display(struct Array arr){
  int i,j;
  for(i=0;i<arr.n;i++){
    for(j=0;j<arr.n;j++){
      if(i==j){
        printf("%d\t",arr.A[i]);
      }else{
        printf("%d\t",0);
      }
      
    }
    printf("\n");
  }
}


int main(){
  struct Array matrix;
  matrix.n = 5;
  set(&matrix, 1,1, 12);
  set(&matrix, 2,2, 22);
  set(&matrix, 3,3, 42);
  set(&matrix, 4,4, 27);
  set(&matrix, 5,5, 71);
  display(matrix);

}