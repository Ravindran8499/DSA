#include<stdio.h>
#include<iostream>

int factorial(int n){
  if(n==0)
   return 1;
  else{
    return n*factorial(n-1);

   }
}


int combination(int n,int r){
  int a,b,c,result;
  a = factorial(n);
  b = factorial(r);
  c = factorial(n-r);
  result = a/(c*b);
  return result;


}

int NCR(int n,int r){
  if(r==0 || n==r)
    return 1;
  return NCR(n-1,r-1) + NCR(n-1,r);
}

int main(){
  printf("%d\n",factorial(6));
  printf("%d\n",combination(6,2));
  printf("%d\n",NCR(6,2));
}