#include<iostream>
#include<stdio.h>




char pallindrome1(char A[],int n){
  printf("Original string: %s\n",A);
  char *B = (char*)malloc(n*sizeof(char));
  int i,j;
  for(i=n-1,j=0;i>=0;i--,j++){
    B[j] = A[i];
  }
  printf("Reversed string is: %s\n",B);
  for(i=0;i<n;i++){
    if(A[i] == B[i]){
      printf("Pallindrome!\n");
      break;
    }else{
      printf("not a pallindrome!!\n");
      break;
    }
  }
  printf("\n");

}



int main(){
  char A[] = "madam";
  int i;
  for(i=0;A[i]!='\0';i++){

  }
  pallindrome1(A,i);
}