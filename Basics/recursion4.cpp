#include<iostream>
#include<stdio.h>

int fun1(int n){
  if(n>0){
    printf("%d\t",n);
    fun1(n-1);
  }

}


int fun2(int n){
  while(n>0){
    printf("%d\t",n);
    n--;
  }
}

int fun3(int n){
  do{
    printf("%d\t",n);
    n--;
  }while(n>0);
}



int factorial(int n){
  int i,fact = 1;
  for(i=1;i<=n;i++){
    fact = fact*i;
  }
  printf("%d",fact);
}

// int fact(int n){
  
//   if(n==1 || n==0){
//     return 1;
//   }else{
//     return (n*fact(n - 1));
//   }
  
// }
int main(){
  int x = 6;
  fun1(x);
  printf("\n");
  fun2(x);
  printf("\n");
  fun3(x);
  printf("\n");
  factorial(x);
  printf("\n");
  // fact(x);
}