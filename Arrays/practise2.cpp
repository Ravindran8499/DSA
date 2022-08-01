#include <bits/stdc++.h>
using namespace std;

int negativeSort(int A[], int size)
{
    int i, j;
    i = 0;
    j = size - 1;
    while (i < j)
    {
        while (A[i] < 0)
        {
            i++;
        }
        while (A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(A[i], A[j]);
        }
    }
}






int display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << "\t";
    }
    cout << "\n";
}

/*
   
   Merging procedure and its applications ----->

*/
int mergeTwoSortedArrays(int A[],int n,int B[],int m){
    int i,j,k;
    i=0;
    j=0;
    k=0;
    int *C = new int[m+n];
    while(i,n && j<m){
        if(A[i] < B[j]){
            C[k++] = A[i++];
        }else{
            C[k++] = B[j++];
        }
    }
    for(;i<n;i++){
        C[k++] = A[i];
    }
    for(;j<m;j++){
        C[k++] = B[j];
    }

    for(int s=0;s<k;s++){
        cout<<C[s]<<"\t";
    }
    cout<<"\n";

}

int UnionOfTwoArrays(int A[], int m, int B[], int n){
    int i,j,k;
    i=0;
    j=0;
    k=0;
    int *C = new int[m+n];
    while(i<n && j<m){
        if(A[i] < B[j]){
            C[k++] = A[i++];
        }else if(B[j]<A[i]){
            C[k++]=B[j++];
        }else{
            C[k++] = A[i++];
            j++;
        }
    }

    for(;i<n;i++){
        C[k++] = A[i];
    }
    for(;j<m;j++){
        C[k++] = B[j];
    }


    for(int s=0;s<k;s++){
        cout<<C[s]<<"\t";
    }
    cout<<"\n";

}

int findmissingElement(int A[],int size){
    int l = A[0];
    int difference = l-0;
    for(int i=0;i<size;i++){
        if(A[i]-i!=difference){
            return i+difference;
            break;
        }
    }

}

int findMultipleMissingElements(int A[],int size){
    int l = A[0];
    int difference = l-0;
    for(int i=0;i<size;i++){
        if(A[i]-i!=difference){
            while(difference < A[i]-i){
                cout<<i+difference<<"\t";
                difference++;
            }
        }
    }


}

int findMissingElementsUsingHashing(int A[],int size){
    int max = A[0];
    int min = A[0];
    for(int i=0;i<size;i++){
        if(A[i] >max){
            max = A[i];
        }
    }

    for(int i=0;i<size;i++){
        if(A[i] < min){
            min = A[i];
        }
    }

    int  *H = new int[max];

    for(int i=0;i<max;i++){
        H[i] = 0;
    }

    for(int i=0;i<size;i++){
        H[A[i]]++;
    }


    for(int i=min;i<max;i++){
        if(H[i] == 0){
            cout<<i<<"\t";
        }
    }
    cout<<"\n";




}

//Sorted arrays
int findDuplicates(int A[],int size){
    int lastDuplicate = 0;
    int count = 0;
    for(int i=0;i<size;i++){
        if(A[i] == A[i+1] && A[i]!=lastDuplicate){
            cout<<A[i]<<"\t";
            lastDuplicate = A[i];
            count++;
        }
    }
    cout<<"\n";
    cout<<count;
} 

int findDuplicatesUsingHashing(int A[],int size){
    int max = A[0];
    int min = A[0];

    for(int i=0;i<size;i++){
        if(A[i] > max ){
            max = A[i];
        }
    }
    
    for(int i=0;i<size;i++){
        if(A[i] < min ){
            min = A[i];
        }
    }

    int *H = new int[max];

    for(int i=0;i<max;i++){
        H[i] = 0;
    }
    for(int i=0;i<size;i++){
        H[A[i]]++;
    }

    for(int i=min;i<=max;i++){
        if(H[i]>1){
            cout<<i<<"\t";
        }
    }
    cout<<"\n";

}

int findDuplicatesinUnsortedArrayDirectly(int A[],int size){
    for(int i=0;i<size-1;i++){
        int count = 1;
        if(A[i]!=-1){
            for(int j=i+1;j<size;j++){
                if(A[i] == A[j]){
                    count++;
                    A[j] = -1;
                }
            }
            if(count>1){
                cout<<A[i]<<"\t"<<count<<" times"<<"\n";
            }
        }

    }

}

//Sum is equal to k in sorted array--->
int sumEqualToKInSortedArray(int A[],int size,int k){
    int i=0;
    int j = size-1;
    while(i<j){
        if(A[i] + A[j] == k){
            cout<<A[i] <<" + "<<A[j]<<" = "<<k<<"\n";
            i++;
            j--; 
        }else if(A[i]+A[j]<k){
            i++;
        }else{
            j--;
        }
    }
}


int main()
{
    int A[] = {23, 65, 98, -96, 41, 23, 89, 74, -33, -33, -46, -9};
    int B[] = {21,23,25,26,27,};
    int C[] = {22,23,24,25,26};
    int D[] = {10,11,12,13,14,15,17,18,19,20};
    int E[] = {10,11,12,13,17,18,19,20,25};
    int F[] = {10,10,12,13,17,17,19,19,19};
    int G[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);
    int n = sizeof(C) / sizeof(C[0]);
    int k = sizeof(D) / sizeof(D[0]);
    int j = sizeof(E) / sizeof(E[0]);
    int l = sizeof(F) / sizeof(F[0]);
    int h = sizeof(G) / sizeof(G[0]);

    // display(A,size);
    cout << "\n";
    // merge(B,m,C,n);
    // unionofTwoArraysinSortedArrays(B,m,C,n);
    //intersectionofTwoSortedArrays(B, m, C, n);
    //mergeTwoSortedArrays(B, m, C, n);   
    //UnionOfTwoArrays(B, m, C, n);
   //cout<<findmissingElement(D,k);
   //findMultipleMissingElements(E,j);
   //findMissingElementsUsingHashing(E,j);
   //findDuplicates(F,l);
   //findDuplicatesUsingHashing(F,l);
   //findDuplicatesinUnsortedArrayDirectly(F,l);
   sumEqualToKInSortedArray(G,h,6);
}