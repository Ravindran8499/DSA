#include<bits/stdc++.h>
using namespace std;
int display(vector <int> &v){
  for(int i=0;i<v.size();i++){
    cout<<v[i];
  }

}

int main(){
  vector <int> v1;
  int number;
  for(int i=0;i<10;i++){
    cin>>number;
    v1.push_back(number);
  }
  
  display(v1);
}