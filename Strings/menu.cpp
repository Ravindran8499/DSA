#include<iostream>
#include<stdio.h>

int length(char *A){
  int i;
  for(i=0;A[i]!='\0';i++){

  }
  printf("%d\n",i);
}

char case1(char A[]){
  for(int i=0;A[i]!='\0';i++){
    if(A[i]>=65 && A[i]<=90){
      A[i]+=32;
    }else if(A[i]>=97 && A[i]<=122){
      A[i]-=32;
    }
  }
  printf("%s\n",A);

}

char wordsAndVowells(char A[]){
  int vowells = 0,consonants = 0,i;
  for(i=0;A[i]!='\0';i++){
    if(A[i] == 'A' ||A[i] == 'E' || A[i] =='I' || A[i]== 'O'||A[i]== 'U'||
    A[i] == 'a' ||A[i] == 'e' || A[i] =='i' || A[i]== 'o'||A[i]== 'u' ){
      vowells++;
    }else if((A[i]>=65 && A[i]<=90) ||(A[i]>=97 && A[i]<=122)){
      consonants++;
    }
  }
  printf("Vowells: %d\n",vowells);
  printf("Consonants: %d\n",consonants);
}

char reverse(char A[],int length){
  printf("Original String: %s\n",A);
  char *B = (char *)malloc(length*sizeof(char));
  int i,j;
  //coping from A to B
  for(i=length-1,j=0;i>=0;i--,j++){
    B[j] = A[i];
  }
  for(i=0;i<length;i++){
    A[i] = B[i];
  }
  
  printf("reversed string: %s\n",A);
  

}

char pallindrome(char A[],int n){
  printf("original string: %s\n",A);
  char *B = (char *)malloc(n*sizeof(char));
  int i,j;
  for(i=n-1,j=0;i>0;i--,j++){
    B[j] = A[i];
  }
  printf("Reversed string: %s\n",B);
  for(int i=0;i,n;i++){
    if(A[i] == B[i]){
      printf("Pallindrome!!");
      break;
    }else{
      printf("Not a Pallindrome!!");
      break;
    }
  }
}


char duplicateSmall(char string[]){
  char *H = (char *)malloc(26*sizeof(char));
  int i;
  //Initilising every element of "H" to zero
  for(i=0;i<26;i++){
    H[i] = 0;
  }
  //we cannot have a Hash array with size of 122 because its huge and we are going to start from 97 because of the ASCII value of a is 97.So from 0-97 its waste.So thats why we subtract 97 from each one and we get ann array of size 26 from 0-25.
  for(i=0;string[i]!='\0';i++){
    H[string[i]-97]++;
  }
  for(int i=0;i<26;i++){
    if(H[i]>1){
      printf("%c -%d times\n",i+97,H[i]);
      
    }
  }
}

char duplicateCapital(char string[]){
  char *H = (char*)malloc(26*sizeof(char));
  int i;

  //Initiliasing the array "H" to Zero
  for(i=0;i<26;i++){
    H[i] = 0;
  }
  //we do -65 because ASCII value for "A" is 65.So after subtracting 65 we will get the array of size 26 from 0-25
  for(i=0;string[i]!='\0';i++){
    H[string[i]-65]++;
  }


  for(i=0;i<26;i++){
    if(H[i]>1){
      printf("%c - %d times\n",i+65,H[i]);
    }
  }
}


int main(){
  char A1[] = "RAVINDRAN";
  char A2[] = "ravindran";
  char A3[] = "RAVINDRANravindran";
  char A4[] = "malayalam";
  duplicateSmall(A4);
  
  
}