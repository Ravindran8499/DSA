#include<iostream>
#include<stdio.h>

int exponent(int m,int n){
  int i,j;
  int answer = m;
  int increment = m;
  for(i=1;i<n;i++){
    for(j=1;j<m;j++){
      answer = answer+ increment;
    }
    increment = answer;
  }
  return answer;
}

int pow(int m,int n){
  if(n==0)
   return 1;
   else{
     return m*pow(m,n-1);
   }
}

 int fasterPower(int m,int n){
   if(n ==0)
    return 1;
  if(n%2==0){
    return fasterPower(m*m,n/2);
  }else{
    return m*fasterPower(m*m,(n-1)/2);
  }
 }


int main(){
  int x = 2 ,y = 9;
  printf("%d\n",fasterPower(x,y));
  printf("%d\n",exponent(x,y));
  printf("%d\n",pow(x,y));
  
}