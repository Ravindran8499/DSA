#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct Array{
  int A[300];
  int length;
  int size;
};



void display(struct Array arr){
  int i;
  printf("The given array is : \t ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}
int sum(struct Array arr){
  int i,sum = 0;
  for(i=0;i<arr.length;i++){
    sum =sum+arr.A[i];
  }
  printf("SUM: %d\n",sum);
}

int getIndex(struct Array arr,int x){
  int i;
  for(i=0;i<arr.length;i++){
    if (x == arr.A[i]){
       printf("element %d found at location %d\n",x,i);
       break;
    }
  }
}


int max(struct Array arr){
  int i;
  int max = arr.A[0];
  for(i=0;i<arr.length;i++){
    
    if(arr.A[i]>max){
      max = arr.A[i];
    }
  }
  printf("MAX: %d\n",max);
}


int min(struct Array arr){
  int i;
  int min = arr.A[0];
  for(i=0;i<arr.length;i++){
    
    if(arr.A[i]<min){
      min = arr.A[i];
    }
  }
  printf("MIN: %d\n",min);
}

float  avg(struct Array arr){
  int total = 0,i;
  for(i=0;i<arr.length;i++){
    total = total+arr.A[i];
  }
  float average = (total)/(arr.length);
  printf("AVERAGE: %f\n",average);
}

int recursiveSum(struct Array arr,int n){
  if(n<0)
  return 0;
  else{
    return recursiveSum(arr,n-1) + arr.A[n]; 
  }
}
int main(){
  struct Array arr = {{20,30,10,97,84,891,12,6,49,617,95,3,120},13,300};
  display(arr);
  getIndex(arr, 10);
  max(arr);
  min(arr);
  sum(arr);
  printf("SUM BY RECURSION: %d\n",recursiveSum(arr, arr.length));
  avg(arr);

}