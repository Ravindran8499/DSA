#include<iostream>
#include<stdio.h>
int main(){
  char string[] ="WELcome";
  for(int i=0;string[i]!='\0';i++){
    if(string[i]>='A' && string[i]<='Z'){
      string[i]+=32;
    }else if(string[i]>='a' && string[i]<='z'){
      string[i]-=32;
    }
  }
  printf("%s\n",string);
  
}