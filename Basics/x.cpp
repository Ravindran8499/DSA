#include<bits/stdc++.h>
using namespace std;

int number(int n){
  if(n>0){
    number(n-1);
    cout<<n<<"\t";
  }
}



int main(){
  number(100);

}