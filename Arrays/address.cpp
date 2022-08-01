#include<iostream>
#include<stdio.h>
int main(){
  int A[5] = {2,4,6,8,10};
  int *p;
  p = new int[15];
  p[0] = 1;
  p[1] = 3;
  p[2] = 5;
  p[3] = 7;
  p[4] = 7;

  for(int i=0;i<5;i++){
    printf("%d\t",A[i]);
  }
  printf("\n");
  
  for(int i=0;i<5;i++){
    printf("%d\t",p[i]);
  }
  
  for(int i=0;i<5;i++){
  // p[i] is bigger so everything from A[i] is copied to P[i]

    p[i] = A[i];
    printf("%d\t",p[i]);
  }
}