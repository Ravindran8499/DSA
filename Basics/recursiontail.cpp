#include<iostream>
#include<stdio.h>


int fun(int n){
  
  if(n>0){
    printf("%d\t",n);
    fun(n-1);
  }

}

int main(){
  int n=3;
  fun(n);
  printf("\n");


}
