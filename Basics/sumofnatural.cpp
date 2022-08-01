#include<stdio.h>
#include<iostream>
int rec_sum(int n){
  if(n==0){
    return 0;
  }
  return n + rec_sum(n-1);
  
}

int sum(int n){
  int s = 0;
  for(int i=1;i<=n;i++){
    s = s+i;
  }
  return s;


}


int main(){
  int d;
  printf("Enter the number: ");
  scanf("%d",&d); 
  int b = rec_sum(d);
  int c = sum(d);
  printf("%d\n",b);
  printf("%d\n",c);

}