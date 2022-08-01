#include<iostream>
#include<stdio.h>

char reverse1(char string[],int length){
  char *B = (char *)malloc(length*sizeof(char));
  int i,j;
  //for loop for copying the elements from  A to B in reverse order 
  for(i=length-1,j=0;i>=0;i--,j++){
    B[j] = string[i];
  }
  //Copying it back to A is same order
  for(i=0;i<length;i++){
    string[i] = B[i];
  }
  printf("%s\n",string);
}

char reverse2(char string[],int length){
  int i,j;
  for(i=0,j=length-2;i<=j;i++,j--){
    char temp = string[i];
    string[i] = string[j];
    string[j] = temp;  
  }
  printf("%s\n",string);
}



int main(){
  char string[] = "Python";
  int i;
  for(i=0;string[i]!='\0';i++){

  }
  reverse1(string, i);
  reverse2(string, i);
}