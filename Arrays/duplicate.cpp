#include<iostream>
#include<stdio.h>
struct Array {
  int A[500];
  int length;
  int size;
};

int max(struct Array arr,int n){
  int max = arr.A[0];
  for(int i=0;i<n;i++){
    if(arr.A[i]>max){
      max = arr.A[i];
    }
  }
  printf("Max is %d",max);

}


int min(struct Array arr,int n){
  int min = arr.A[0];
  for(int i=0;i<n;i++){
    if(arr.A[i]<min){
      min = arr.A[i];
    }
  }
  printf("Min is %d",min);
}

//Function to find missing and Duplicate elements
int findDuplicateAndMissing(struct Array arr,int l,int h,int n){
  //initialising an Array H
  int *H = (int *)malloc(h*sizeof(int));
  //Initialising all the elements of the array to Zero
  for(int i=0;i<h;i++){
    H[i] = 0;
  }
  //Incrementing the array "H" elements according to the elements of "A"
  for(int i=0;i<n;i++){
    H[arr.A[i]]++;
  }
  //Printing the missing elements
  printf("The missing elements are: \n");
  for(int i=l;i<h;i++){
    if(H[i] == 0){
      printf("%d\n",i);
    }
  }
  //printing the duplicate elements
  printf("The duplicate Elements are: \n");
  for(int i=l;i<h;i++) {
    if(H[i]>1){
      printf("%d - %d times\n",i,H[i]);
    }
  }

}

//This can also be done Using Hash table as depicted above
int findSum(struct Array arr,int k){ 
  printf("\n");
  for(int i=0;i<arr.length-1;i++){
    for(int j=i+1;j<arr.length;j++){
      if(arr.A[i] + arr.A[j] == k){
        printf("%d + %d = %d\n",arr.A[i],arr.A[j],k);
      }
    }
  }
}

int findSumUsingHash(struct Array arr,int l,int h,int n,int k){
  //Creating a dynamic array in heap
  int *H = (int *)malloc(h*sizeof(int));
  //Initialising all the Array H elements to 0
  for(int i=0;i<h;i++){
    H[i] = 0;
  }

  for(int i=0;i<n;i++){
    H[arr.A[i]]++;
  }
  //finding the elements whose sum equals "K"
  for(int i=0;i<n;i++){
    if(H[k-arr.A[i]] !=0 ){
      printf("%d+%d = %d\n",arr.A[i],k-arr.A[i],k);  
    }
  }
}


int sumInsortedArray(struct Array arr,int k){
  int i=0;
  int j=arr.length-1;
  while(i<j){
    if(arr.A[i] + arr.A[j] == k){
      printf("%d + %d = %d\n",arr.A[i],arr.A[j],k);
      i++;
      j--;
    }else if(arr.A[i]+arr.A[j]<k){
      i++;
    }else if(arr.A[i]+ arr.A[j]>k){
      j--;
    }
  }

}

int minMax(struct Array arr){
  int min = arr.A[0];
  int max = arr.A[0];
  for(int i=0;i<arr.length;i++){
    if(arr.A[i]>max){
      max = arr.A[i];
    }else if(arr.A[i]< min){
      min = arr.A[i];
    }
  }
  printf("max: %d\n min: %d\n",max,min);
}
int main(){
  struct Array arr = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},20,500};
  findSumUsingHash(arr,1,20,20,10);
}