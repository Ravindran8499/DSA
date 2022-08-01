#include<bits/stdc++.h>
using namespace std;


int findMax(int A[],int n){
    int max = A[0];
    for(int i=0;i<n;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int findMin(int A[],int n){
    int min = A[0];
    for(int i=0;i<n;i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int countSort(int A[],int n){

    int max =  findMax(A,n);
    int C[max+1];
    for(int i=0;i<max+1;i++){
        C[i] = 0;
    }
    for(int i=0;i<n;i++){
        C[A[i]]++;
    }


    int i=0,j=0;
    while(i<max+1){
        if(C[i]>0){
            A[j++]=i;
            C[i]--;
        }else{
            i++;
        }
    }
    for(int s=0;s<n;s++){
        cout<<A[s]<<"\t";
    }
    cout<<endl;
}

int oddOneSideEvenOneSide(int A[],int n){
    int i=0,j=n-1;
    while(i<j){
        while(A[i] < 0){
            i++;
        }
        while(A[j] > 0){
            j--;
        }
        if(i<j){
            swap(A[i],A[j]);
        }
    }
    i=0;
    for(i=0;i<n;i++){
        cout<<A[i]<<"\t";
    }
    cout<<endl;
}

int mergeTwoSortedArrays(int A[],int B[],int m,int n){
     int i=0;
     int j =0;
     int k = 0;
    int C[m+n];
     while(i<m && j<n){
         if(A[i] < B[j]){
             C[k++] = A[i++];
         }else{
             C[k++] =B[j++];
         }
     }
     for(;i<m;i++){
         C[k++] =A[i];
     }
     for(;j<n;j++){
         C[k++] = B[j];
     }

     for(i=0;i<m+n;i++){
         cout<<C[i]<<"\t";
     }
     cout<<"\n";
}

int unionOfTwoArrays(int A[],int B[],int m,int n){
    int i=0;
    int j = 0;
    int k = 0;
    int C[m+n];
    while(i<m && j<n){
        if(A[i] < B[j] ){
            C[k++] = A[i++];
        }else if(A[i] > B[j]){
            C[k++] = B[j++];
        }else if(A[i] == B[j]){
            C[k++] = A[i++];
            j++;
        }
    }
    for(;i<m;i++){
        C[k++] = A[i];
    }
    for(;j<n;j++){
        C[k++] = B[j];
    }
    for(int s=0;s<k;s++){
        cout<<C[s]<<"\t";
    }
}

int intersectionOfTwoArrays(int A[],int B[],int m,int n){

    int i=0;
    int j = 0;
    int k  =0;
    int C[m+n];
    while(i<m && j<n){
        if(A[i] < B[j]){
            i++;
        }else if(B[j] < A[i]){
            j++;
        }else if(A[i] == B[j]){
            C[k++] = A[i++];
            j++;
        }
    }
    for(int s=0;s<k;s++){
        cout<<C[s]<<"\t";
    }

}

int differenceOfTwoArrays(int A[],int B[],int m,int n){
    int i=0;
    int j = 0;
    int k = 0;
    int C[m+n];
    while(i<m && j<n){
        if(A[i] < B[j]){
            C[k++] = A[i++];
        }else if(B[j] < A[i]){
            j++;
        }else{
            i++;j++;
        }
    }
    for(int s=0;s<k;s++){
        cout<<C[s]<<"\t";
    }
    cout<<"\n";
}

//Missing elements
int missingElements(int A[],int n){
    int l = 11;
    int h = 21;
    int difference = l-0;
    for(int i=0;i<n;i++){
        if(A[i]-i!=difference){
            while(difference < A[i]-i){
                cout<<i+difference<<"\t";
                difference++; 
            }
        }
    }

}

int findMissingElementsInunsortedArray(int A[],int n){
    int l = findMin(A,n);
    int h = findMax(A,n);
    int C[h];
    for(int i=0;i<h;i++){
        C[i] = 0;
    }
    for(int i=0;i<n;i++){
        C[A[i]]++;
    }
    for(int i=l;i<h;i++){
        if(C[i] == 0){
            cout<<i<<"\t";
        }
    }
    cout<<"\n";
}

//Finding duplicates
int tradiditionalMethodFindFuplicatesInSortedArray(int A[],int n){
    int lastDuplicate = 0;
    for(int i=0;i<n;i++){
        if(A[i] == A[i+1] && A[i]!=lastDuplicate){
            cout<<A[i]<<"\t";
            lastDuplicate = A[i];
        }
    }

}

int countingtheNumberofDuplicates(int A[],int n){
    for(int i=0;i<n;i++){
        if(A[i] == A[i+1]){
            int j = i+1;
            while(A[j] == A[i]){
                j++;
            }
            cout<<A[i]<<"------------"<<j-i<<" times"<<"\n";
            i=j-1;
        }
    }

}

int findDuplicateElements(int A[],int n){
    int l = findMin(A,n);
    int h = findMax(A,n);
    int C[h];
    for(int i=0;i<h;i++){
        C[i] = 0;
    }
    for(int i=0;i<n;i++){
        C[A[i]]++;
    }
    for(int i=0;i<h;i++){
        if(C[i] > 1){
            cout<<i<<"----"<<C[i]<<"\t";
        }
    }
}

int nonrepeatingElement(int A[],int n){
    int l = findMin(A,n);
    int h = findMax(A,n);
    int C[h];

    for(int i=0;i<h;i++){
        C[i] = 0;
    }
    
    for(int i=0;i<n;i++){
        C[A[i]]++;
    }

    for(int i=0;i<h;i++){
        if(C[i] == 1){
            return i;
        }
    }

}

int replacefiveswithzeros(int n){
    vector<int> v;
    int number = n;
    while(number > 0){
        int r = number%10;
        v.push_back(r);
        number = number/10;
    }
    for(int i=0;i<v.size();i++){
        if(v[i]!=0){
            continue;
        }else if(v[i] == 0){
            v[i] = 5;
        }
    }
    int sum = 0;
    int mul = 1;
    for(int i=0;i<v.size();i++){
        sum = sum+v[i]*mul;
        mul = mul*10;
    }
    cout<<sum;

}

int x(int A[],int n){
    //Time consuming.....so use Kades algo
    int sum = INT_MIN;
    int sum1 = 0;
    int end = 0;
    while(end < n){
        sum1 = sum1+A[end];
        sum = max(sum,sum1);
        end++;
    }
    return sum;
}

int samAndKelly(int samDaily,int kellyDaily,int difference){
    int count =1 ;
    int samTotal  =  difference + samDaily;
    int kellyTotal = kellyDaily;
    while(kellyTotal <= samTotal){
        kellyTotal+=kellyDaily;
        samTotal+=samDaily;
        count++;
    }
    return count;

}


int solve(int a,int b,int c){
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> vt;
    vector<int> vh;
    vector<int> vtens;
    vector<int> vunits;
    vector<int> final;
    
    while(a>0){
         int r = a%10;
         v1.push_back(r);
         a=a/10;
    }
    while(b>0){
        int r = b%10;
        v2.push_back(r);
        b = b/10;
    }
    while(c>0){
        int r = c%10;
        v3.push_back(r);
        c = c/10;
    }
    int v1Size = v1.size();
    int v2Size = v2.size();
    int v3Size = v3.size();
    
    vt.push_back(v1[v1Size-1]);
    vt.push_back(v2[v2Size-1]);
    vt.push_back(v3[v3Size-1]);
    cout<<v1[v1Size-1];
    
    int minT = vt[0];
    for(int i=0;i<vt.size();i++){
        if(vt[i] < minT){
            minT = vt[i];
        }
    }
    
    vh.push_back(v1[v1Size-2]);
    vh.push_back(v2[v2Size-2]);
    vh.push_back(v3[v3Size-2]);
    
    int maxH = vh[0];
    for(int i=0;i<vh.size();i++){
        if(vh[i] > maxH){
            maxH = vh[i];
        }
    }
    
    vtens.push_back(v1[v1Size-3]);
    vtens.push_back(v2[v2Size-3]);
    vtens.push_back(v3[v3Size-3]);
    
    int minTens = vtens[0];
    for(int i=0;i<vtens.size();i++){
        if(vtens[i] <minTens ){
            minTens = vtens[i];
        }
    }
    vunits.push_back(v1[v1Size-4]);
    vunits.push_back(v2[v2Size-4]);
    vunits.push_back(v3[v3Size-4]);
    
    int maxUnits = vunits[0];
    for(int i=0;i<vunits.size();i++){
        if(vunits[i] > maxUnits){
            maxUnits = vunits[i];
        }
    }
    
    final.push_back(minT);
    final.push_back(maxH);
    final.push_back(minTens);
    final.push_back(maxUnits);
    
    int sum = 0;
    int mul = 1;
    for(int i=final.size();i>=0;i--){
        cout<<final[i]<<"\t";
    }
    
}



int main(){
    //int A[] = {-12,45,10,-33,70,90,-80,33,-1,-2,0};
    int A[] = {-1,-2,-3,-4};
    int B[] = {11,13,15,17,19,20,21};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
    solve(3251,2452,1352);
   
    //countSort(A,n);
    //oddOneSideEvenOneSide(A,n);
    //mergeTwoSortedArrays(B,C,m,n);
   //unionOfTwoArrays(A,B,m,n);
    cout<<"\n";
    //intersectionOfTwoArrays(A,B,m,n);
    cout<<"\n";
    //differenceOfTwoArrays(A,B,m,n);
    //cout<<missingElements(B,n)<<endl;
    //findMissingElementsInunsortedArray(A,m);
    //findDuplicateElements(A,m);
    //tradiditionalMethodFindFuplicatesInSortedArray(A,m);
   // countingtheNumberofDuplicates(A,m);
   //cout<<nonrepeatingElement(A,n);
 //cout<<x(A,m);
//  cout<<samAndKelly(3,5,5);
}