#include<iostream>
#include<stdio.h>
int main(){
  int n,array[n];
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  int i;
  printf("Enter the elements of the array\n");
  for (i=0;i<n;i++){
    scanf("%d",&array[i]);
    }
    printf("The givenarray is : ");
    for (i=0;i<n;i++){
    printf("%d\t",array[i]);
    }
    int sum =0;
    for (i=0;i<n;i++){
    sum = sum+array[i];
    }
    printf("\n");
    printf("SUM: %d",sum);

}