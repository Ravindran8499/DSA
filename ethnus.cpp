#include<bits/stdc++.h>
using namespace std;


int calculateWage(int age[],int size){
    int sum = 0;
    
    if(size > 20){
        cout<<"Doctor only sees 20 patients for the day"<<endl;
    }else{
        for(int i=0;i<size;i++){
            if(age[i]<0 || age[i]>120){
               cout<<"The Age should be between 0 and 120"<<endl;
               break;
            }else if(age[i]<17){
                sum = sum+200;
            }else if(age[i]>=17 && age[i]<40){
                sum = sum+400;
            }else if(age[i] >= 40){
                sum = sum+300;
            }

        }
    }
    return sum;
}


int  countgreaterThanPreviousElements(int A[],int size){
    int count = 1;
    for(int i=0;i<size-1;i++){
        if(A[i]<A[i+1]){
            count++;
        }
    }
    return count;
}


int main(){
    // double i = (1.1,2.2,3.3);
    // printf("%f",i);
    // return 0;
    //     int prep = 3;
    //     printf("%d",(++ethy)++);
    //     return 0;

    // int i,j,x = 0;
    // for(i=0;i<5;i++){
    //     for(j=0;j<5;j++){
    //         x = (i+j-1);
    //         cout<<x;
    //         break;
    //     }
    //     cout<<x;
    // }
        //  int k = 5;
        //  int *p = &k;
        //  int **m = &p;
        //  printf("%d%d%d",k,*p,**m);

        // char *p = NULL;
        // char *q = 0;
        // if(p){
        //     printf("p");
        // }else{
        //     printf("Nullp");
        // }
        // if(q){
        //     printf("q");
        // }else{
        //     printf("nullq");
        // }

        // int x,y = 5 ,z = 5;
        // x=y==z;
        // printf("%d",x);

    // int age[] = {20,30,40,50,2,3,14};
    // int size = sizeof(age)/sizeof(age[0]);
      //cout<<calculateWage(age,size)<<endl;



    // int N = 10;
    // int k = 5;
    // int input;
    // cout<<"Enter the number of candies you want: "<<"\t";
    // cin>>input;
    // if(input==0 || input > N){
    //     cout<<"INVALID INPUT"<<"\n";
    //     cout<<"NUMBER OF CANDIES AVAILABLE: "<<N<<"\n";
    // }
    // else if(N-input<5){
    //     cout<<"Invalid input!!"<<endl;
    // }else{
    //     cout<<"NUMBER OF CANDIES SOLD: "<<input<<"\n";
    //     cout<<"NUMBER OF CANDIES AVAILABLE: "<<N-input<<"\n";
    // }



//     int a[3][3];
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             cin>>a[i][j];
//         }
//     }
//     int average1 = 0;
//     int average2 = 0;
//     int average3 = 0;

//     for(int i=0;i<3;i++){
//             average1 = average1+a[i][0];
//             cout<<"\n";
//             cout<<"\n";
//             cout<<"\n";
//             cout<<a[i][0]<<"\n";
//             average1 = average1/3;
//             average2 = average2+a[i][1];
//             average2 = average2/3;
//             average3 = average3+a[i][2];
//             average3 = average3/3;
//     }
// cout<<"\n";
// cout<<"\n";
// cout<<"\n";
//      cout<<average1<<endl;
//      cout<<average2<<endl;
//      cout<<average3<<endl; 
         









        //  int A[] = {3,6,2,8,9};
        //  cout<<countgreaterThanPreviousElements(A,5);

        int weight;
        cout<<"Enter weight: "<<"\t";
        cin>>weight;
        if(weight)





















 }
