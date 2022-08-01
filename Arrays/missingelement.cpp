#include<iostream>
#include<stdio.h>

struct Array {
  int A[500];
  int length;
  int size;
};

int findMissingElement(struct Array arr,int l,int h,int n){
  int difference = l-0;
  for(int i=0;i<n;i++){
    if(arr.A[i] - i != difference){
      int missingElement = i + difference;
      printf("Missing element is : %d\n",missingElement);
      break;
    }
  }
}



int findMissingElements(struct Array arr,int l,int h,int n){
  int difference = l-0;
  for(int i=0;i<n;i++){
    if(arr.A[i] - i != difference){
      while(difference < arr.A[i]-i){
        printf("%d\n",i+difference);
        difference++;
      }
    }
  }
}

int missingElementsInUnsortedArray(struct Array arr,int l,int h,int n){
  int *H = (int *)malloc(h*sizeof(int));
  for(int i=0;i<h;i++){
    H[i] = 0;
  }
  for(int i=0;i<n;i++){
    H[arr.A[i]]++;
  }
  printf("Missing elements are: \n");
  for(int i=l;i<h;i++){
    if(H[i] == 0){
      printf("%d\n",i);
    }
  }

}
int main(){
  struct Array arr = {{13,14,1,5,6,7,10,12,8,9,},10,500};
  missingElementsInUnsortedArray(arr, 1,14, arr.length);
}
