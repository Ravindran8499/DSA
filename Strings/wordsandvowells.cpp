#include<iostream>
#include<stdio.h>

char numberOfvowellsAndConsonants(char string[]){
  int i,vowells = 0,consonants = 0;
  for(i=0;string[i]!='\0';i++){
    if(string[i] == 'A' ||string[i] == 'E' || string[i] =='I' || string[i]== 'O'||string[i]== 'U'||
    string[i] == 'a' ||string[i] == 'e' || string[i] =='i' || string[i]== 'o'||string[i]== 'u'){
      vowells++;
    }else if((string[i]>=65 && string[i]<=90) || (string[i] >=97 && string[i]<=122)){
      consonants++;
    }

  }
  printf("Vowells: %d\n",vowells);
  printf("Consonants: %d\n",consonants);

}

char numberOfWords(char string[]){
  int i,words = 0;
  for(i= 0;string[i]!='\0';i++){
    if(string[i]==' ' && string[i-1]!=' '){
      words++;

    }
  }
  printf("number of words: %d\n",words+1);
}



int main(){
  char string[] = "How are you";
  numberOfvowellsAndConsonants(string);
  numberOfWords(string);

}