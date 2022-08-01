#include<stdio.h>
#include<iostream>

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


//Little bit error
char duplicateCapitalSmall(char string[]){
  char *H = (char *)malloc(52*sizeof(char));
  int i;

  //initiliasing all the array H members to Zero
  for(i=0;i<52;i++){
    H[i]=0;
  }
  
  for(i=0;string[i]!='\0';i++){
    if(string[i]>=97 && string[i]<=122){
      H[string[i]-97]++;
    }else if(string[i]>=65 && string[i]<=90){
      //+ 26 because if we donot do it will increment the previous places wich was registerd and incremented fot the small letters. like A and a will be incremented.Thats not what we want.
      H[string[i] - 65 + 26]++;
      
    }
  }

  for(i=0;i<52;i++){
    if(H[i]>1){
      printf("%c -%d times\n",i+97,H[i]);
      printf("%c -%d times\n",i+65,H[i]);
    }
  }
  
}

int main(){
  char string1[] = "ravindranaqwqasq"; 
  char string2[] = "RAVINDRANAQWQAA";
  char string3[] = "RrAaVvIiNnDdRrAaNn";

  duplicateCapitalSmall(string3);

}