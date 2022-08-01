#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
  float totalBalance;
  int  amountTobeWithdrawm;
  float extraCharges = 0.50;
  cin>>amountTobeWithdrawm>>totalBalance;

  if(amountTobeWithdrawm < totalBalance){
    if(amountTobeWithdrawm%5==0){
      cout<<float(totalBalance-amountTobeWithdrawm-extraCharges);

  }else{
    cout<<totalBalance;
  }
  }else{
    cout<<totalBalance;
  }
  

  

}