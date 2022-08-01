#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int > v;
  for(int i=0;i<10;i++){
    v.push_back(i);
  }
  cout<<v.size();
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<"\t";
  }
}