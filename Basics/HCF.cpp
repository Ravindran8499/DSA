#include<bits/stdc++.h>

int HCF(int n,int m){
  while(m!=n){
    if(m>n){
      m=m-n;
    }else{
      n=n-m;
    }
  }
}

int main(){
printf("%d",HCF(60, 30));
}