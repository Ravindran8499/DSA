#include<iostream>
#include<stdio.h>
int fun(int n){
  int x = 1,k;
  if(n==1)
   return 1;
  for(k=1;k<n;++k){
    x = x + fun(n)*fun(n-k);
  }
  return x;
}
int main(){
  printf("%d\n",fun(5));
}