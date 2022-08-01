#include<iostream>
#include<stdio.h>

int fibonacci(int range){     //'n' th term
  int a=0,b=1,c=0;
  int i;
  if(range<=1){
    return range;
  }else{
    for(i=2;i<=range;i++){
    c = a+b;
    a=b;
    b=c;
    printf("%d\t",c);
    }
  }
  printf("\n");
  }




int fib1(int range){    //Direct range 
  int a=0,b=1,c=0;
  while(c<=range){
    c = a+b;
    if(c<=range){
      printf("%d\t",c);
      a = b;
      b = c;
    }
  }
   printf("\n");
}

// int fib2(int n){             //advanced  recursive function
//   static int f[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//   if(n<=1){
//     f[n]=n;
//     return n;
//   }else{
//     if(f[n-2] == -1){
//       f[n-2] == fib2(n-2);
//     }
      
//     if(f[n-1] == -1){
//       f[n-1] == fib2(n-1);
//     }
//       return f[n-2] + f[n-1];
//   }
// }


int rfib(int n){
  if(n<=1){
    return n;
  }
  else{
    return rfib(n-2) + rfib(n-1);
  }
}
int main(){
  fibonacci(9);             //nth term
  fib1(34);                //value of the nth term
  //fib2(9);
  rfib(9);
}