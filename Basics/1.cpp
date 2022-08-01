#include<iostream>
#include<stdio.h>
int fun(int n){
  static int i = 1;
  if(n>=5)
    return n;
  n = n + i;
  i++;
  return n;

}



int main(){
printf("%d\n",fun(1));
}






