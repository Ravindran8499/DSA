#include<iostream>
#include<stdio.h>
int fun(int n){
  if(n>100){
    return n-10;

  }else{
    fun(fun(n+11));

  }
}
int main(){
  printf("%d",fun(95));
}