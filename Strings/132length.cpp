#include<iostream>
#include<stdio.h>
int main(){
  char *name = "Ravindran";
  int i,count = 0;
  for(i=0;name[i]!='\0';i++){
    count++;
  }
  printf("Length: %d\n",i);
  printf("Length: %d",count);
}
