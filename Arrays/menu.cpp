#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//Structure Array: 
struct Array {
  int A[500];
  int length;
  int size;
  
};


//Swapping Function
int swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}



//Normal Display Function
int display(struct Array arr){
  int i;
  
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}


//Maximum function
int max(struct Array arr){
  int i;
  int max = arr.A[0];
  for(i=0;i<arr.length;i++){
    if(arr.A[i]>max){
      max = arr.A[i];
    }
  }
  printf("MAX: %d",max);
  printf("\n");
}


//Minimum function
int min(struct Array arr){
  int i;
  int min = arr.A[0];
  for(i=0;i<arr.length;i++){
    if(arr.A[i]<min){
      min = arr.A[i];
    }
  }
  printf("MIN: %d",min);
  printf("\n");
}



//Revers function with the help of new Array created in Heap
int reverse1(struct Array arr){
  int *arr2 = (int *)malloc(arr.length*sizeof(int));
  int i,j;
  for(i=arr.length-1,j=0;i>=0;i--,j++){
    arr2[j] = arr.A[i];
  }
  for(i=0;i<arr.length;i++){
    arr.A[i] = arr2[i];
  }

  printf("Reversed Array (reverse 1): ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}


//Reversing the array without creating a new Array in heap
int reverse2(struct Array arr){
  int i,j;
  for(i=0,j=arr.length-1;i<=j;i++,j--){
    int temp = arr.A[i];
    arr.A[i] = arr.A[j];
    arr.A[j] = temp;
  }
  printf("Reversed Array (reverse 2): ");
  for(i=0;i<arr.length;i++){
    printf("%d\t",arr.A[i]);
  }
  printf("\n");
}


//Linearsearch
int linearSearch(struct Array arr,int key){
  int i;
  for(i=0;i<arr.length;i++){
    if(key == arr.A[i]){
      printf("%d found at position %d(linear search)",key,i);    
    }
  }
 
  printf("\n");

}

//Insertion function in non sorted array
int insert(struct Array *arr,int index,int x){
  int i;
  for(i=arr->length-1;i>=index;i--){
    arr->A[i+1] = arr->A[i];
  }
  arr->A[index] = x;
  arr->length = arr->length + 1;

}


//Delete function
int deleteElement(struct Array *arr,int index){
  int i;
  for(i=index;i<arr->length;i++){
    arr->A[i] = arr->A[i+1];
  }
  arr->length = arr->length-1; 

}

//Append function
int append(struct Array *arr,int x){
  int i;
  for(i=0;i<arr->length;i++){
    arr->A[arr->length] = x;
  }
  arr->length = arr->length + 1;
}


//Get index function
int getIndex(struct Array arr,int x){
  int i;
  for(i=0;i<arr.length;i++){
    if(arr.A[i] == x){
      printf("Index of %d is %d\n",x,i);
      break;
    }
  }
  return -1;
}

//Normal sum
int sumNormal(struct Array arr){
  int sum = 0,i;
  for(i=0;i<arr.length;i++){
    sum = sum+arr.A[i];
  }
  printf("SUM: %d",sum);
}

//Negative to one side and positive to other side
int negativesort(struct Array *arr){
  int i,j;
  i = 0,j = arr->length-1;
  while (i<j){
    while(arr->A[i]<0){
      i++;
    }
    while (arr->A[j]>=0){
      j--;
    }
    if(i<j){
      swap(&arr->A[i],&arr->A[j]);
    }
  }
  printf("Array: ");
  for(i=0;i<arr->length;i++){
    printf("%d\t",arr->A[i]);
  }
  printf("\n");
}




//Merge function
int merge(struct Array arr1,struct Array arr2){
  int m = arr1.length;
  int n = arr2.length;
  int i = 0, j = 0, k = 0;
  int *B = (int *)malloc((m+n)*sizeof(int));
  while(i<m && j<n){

    if(arr1.A[i] < arr2.A[j]){
      B[k++] = arr1.A[i++];
    }
    else{
      B[k++] = arr2.A[j++];
      
    }
  }

  for(;i<m;i++){
    B[k++] = arr1.A[i];

  }
  
  for(;j<n;j++){
    B[k++] = arr2.A[j];

  }

  k = m+n;
  printf("Merged array:\t");
  for(i=0;i<k;i++){
    printf("%d\t",B[i]);
  }
  printf("\n");

}


//Union of two integers using merging concept
int Union(struct Array arr1,struct Array arr2){
  int m = arr1.length;
  int n = arr2.length;
  int i=0 ,j = 0,k = 0;
  int *B = (int *)malloc((m+n)*sizeof(int));
  while(i<m && j<n){
    if(arr1.A[i]<arr2.A[j]){
      B[k++]  = arr1.A[i++];
    }else if(arr2.A[j]<arr1.A[i]){
      B[k++] = arr2.A[j++];
    }else if(arr1.A[i] == arr2.A[j]){
      B[k++] = arr1.A[i++];
      j++;
      
    }

  }
  
  for(;i<m;i++){
    B[k++] = arr1.A[i];

  }
  
  for(;j<n;j++){
    B[k++] = arr2.A[j];

  }

  printf("Union:\t");
  for(i=0;i<k;i++){
    printf("%d\t",B[i]);
  }
  printf("\n");
  
}



//Intersection of 2 Arrays using merging concept
int intersection(struct Array arr1,struct Array arr2){
  int m = arr1.length;
  int n = arr2.length;
  int i = 0 ,j = 0,k = 0;
  int *B = (int *)malloc((m+n)*sizeof(int));
  while(i<m && j<n){
    if(arr1.A[i]<arr2.A[j]){
      i++;
    }else if(arr1.A[i]>arr2.A[j]){
      j++;
    }else if(arr1.A[i] == arr2.A[j]){
      B[k++] = arr1.A[i++];
      j++;
    }
  }

  printf("Intersection:\t");
  for(i=0;i<k;i++){
    printf("%d\t",B[i]);
  }
  printf("\n");
}



//Difference of two integers using merging concept
int difference(struct Array arr1,struct Array arr2 ){
  int i = 0,j = 0,k = 0;
  int m = arr1.length;
  int n = arr2.length;
  int *B = (int *)malloc((m+n)*sizeof(int));
  while(i<m && j<n){
    if(arr1.A[i]<arr2.A[j]){
      B[k++] = arr1.A[i++];

    }else if (arr1.A[i]>arr2.A[j]){
      j++;
    }else{
      i++;j++;
    }
  }

  for(;i<m;i++){
    B[k++] = arr1.A[i];
    
  }


  printf("A - B: \t");
  for(i=0;i<k;i++){
    printf("%d\t",B[i]);
  }
  printf("\n");

}



int main(){
  struct Array arr1 = {{4,5,6,7,8,9,10,1,2,3},10,500};
  struct Array arr2 = {{10,11,20,21,31,64,97,85,96,49,78,30,40,99,50,60,70,80,90,100},20,500};
  printf("1.Swap\n2.display\n3.max\n4.min\n5.Reverse\n6.Linear Search.\n7.Insert\n8.Delete\n9.append\n10.GetIndex\n11.Sum\n12.NegativeSort\n13.Merge\n14.Union\n15.Intrsection\n16.Difference\n");
  printf("\n\n");
  
  int choice;
  do{ 
    
    printf("\nEnter the choice:\t");
    scanf("%d",&choice);
    switch(choice){
        case 1:

        int num1,num2;
        printf("Enter 1st number: ");
        scanf("%d",&num1);
        printf("Enter num2");
        scanf("%d",&num2);
        swap(&num1, &num2);
        break;

        case 2:

        display(arr1);
        printf("\n");
        display(arr2);
        break;

        case 3: 

        max(arr1);
        break;

        case 4:

        min(arr1);
        break;

        case 5:
        reverse1(arr1);
        break;

        case 6:
        
        int key1;
        printf("Enter the number to be searched:");
        scanf("%d",&key1);
        linearSearch(arr1, key1);
        if(linearSearch(arr1, key1) == -1){
          printf("not found!");
        }
        break;
        
        case 7:

        printf("Enter Number: ");
        int index,x;
        scanf("%d",&x);
        printf("Enter index: ");
        scanf("%d",&index);
        insert(&arr1,index,x);
        break;

        case 8:

        int index1;
        printf("Enter the Index: ");
        scanf("%d",&index1);
        deleteElement(&arr1,index1);
        break;

        case 9:

        int element;
        printf("Enter the Number: ");
        scanf("%d",&element);
        append(&arr1, element);
        break;

        case 10:

        int element1;
        printf("Enter the element: ");
        getIndex(arr1, element1);
        break;

        case 11:
        sumNormal(arr1);
        break;

        case 12:
        negativesort(&arr1);
        break;

        case 13:
        merge(arr1,arr2);
        break;

        case 14:
        Union(arr1, arr2);
        break;
        case 15:
        intersection(arr1,arr2);
        break;
        case 16:
        difference(arr1,arr2);
        break;
        case 17:
        printf("EXIT");
        break;

        default:
        printf("Please enter valid choice 1/2/3/4/5/6/7/8/9/10/11/12/13/14");
        
        }

  }while(choice!=14);
   
}