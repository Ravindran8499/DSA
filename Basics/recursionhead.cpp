#include<iostream>
#include<stdio.h>

int fun2(int n){
  if(n>0){
    fun2(n-1);
    printf("%d\t",n);
  }
}

int main(){
  int n = 3;
  fun2(n);
}