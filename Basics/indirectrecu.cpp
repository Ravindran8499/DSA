#include<iostream>
#include<stdio.h>
 //because funB is not declared  before its beingused.
int funB(int n);                 //declaration of the function

int funA(int n){                //definition of the function
  if(n>0){
    printf("%d\t",n);
    funB(n-1);
  }
}

int funB(int n){
  if(n>0){
    printf("%d\t",n);
    funA(n/2);
  }
}

int main(){
int x = 20;  
funA(x);

}