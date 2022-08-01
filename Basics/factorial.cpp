#include<iostream>
#include<stdio.h>

int rec_factorial(int n){
  if(n==0)
   return 1;
   else{
     return n*rec_factorial(n-1);
   }
   
}


int factorial(int n){
  int i,fact = 1;
  for(i=1;i<=n;i++){
    fact = fact*i;
  }
  return fact;
}

int main(){
  int n;
  printf("Enter the number: ");
  scanf("%d",&n);
  printf("%d\n",rec_factorial(n));
  printf("%d\n",factorial(n));

}
