#include<iostream>
#include<stdio.h>
char invalid(char string[]){
  int i;
  for(i=0;string[i]!='\0';i++){
    //Not belongs to both of them ::Thats why using and
    if(!((string[i]>='A' && string[i]<='Z') && (string[i]>='a' && string[i]<='z') && (string[i]>=48 && string[i]<= 57))){
      printf("Invalid\n");
      break;
    }else{
      printf("Valid\n");
      break;
    }
  }
}
int main(){
  char string[] = "Ravindran>>:>:";
  invalid(string);
}