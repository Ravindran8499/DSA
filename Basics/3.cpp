#include<iostream>
#include<stdio.h>

int f(int &x,int c){
  c--;
  if(c==0)
   return 1;
   x++;
   return f(x,c)*x;
}

int main(){
int p=5;
printf("%d\n",f(p,p));

}