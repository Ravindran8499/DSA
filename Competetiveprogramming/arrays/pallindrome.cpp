#include<bits/stdc++.h>
using namespace std;

int isPallindrome(int a){
    int num = a;
    int sum = 0;
    while(a>0){
        int r = a%10;
        sum = sum*10 +r;
        a=a/10;
    }
   //cout<<sum;
   if(sum == num){
       return 1;
   }else{
       return 0;
   }

}




int main(){
    cout<<isPallindrome(12321);
}