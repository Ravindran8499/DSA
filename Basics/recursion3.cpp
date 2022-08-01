#include<iostream>
#include<stdio.h>


int fun(int n){
  
  if(n>0){
  
      return fun(n-1)+n;
  }
}




int main(){

int a = 5;
printf("%d",fun(a));

}


