#include<iostream>
#include<stdio.h>
#include<stdlib.h>
int main(){

  int *b[3];
  b[0] = (int *)malloc(4*sizeof(int));
  b[1] = (int *)malloc(4*sizeof(int));
  b[2] = (int *)malloc(4*sizeof(int));
  b[0][1] =  5;
  b[0][2] =  15;
  b[0][3] =  17;
  b[1][2] =  71; 
  b[1][3] =  5;

  int i,j;
  for(i=0;i<3;i++){
    for(j=0;j<4;j++){
      printf("b[%d][%d] = %d\n",i,j,b[i][j]);

    }
    
  }
}