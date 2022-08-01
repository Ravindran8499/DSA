#include<iostream>
#include<stdio.h>

double tailor(int x,int n){              //recursive function
  static double p = 1,f = 1;
  double result;
  if(n==0)
   return 1;
  else{
    result = tailor(x,n-1);
    p = p*x;
    f = f*n;
    return result + p/f;

  }
}





double e1(int x,int n){         //recursive function horner'srule
  static double sum = 1;
  if(n==0)
   return sum;
   else{
     sum = 1 + x*sum/n;
   }
   return e1(x,n-1);
}




double e(int x,int n){
  double sum = 1;
  double num = 1,den = 1;

  int i;
  for(i=1;i<n;i++){
    num *=x;
    den *=i;
    sum = sum + num/den; 
  }
  return sum;
}


int main(){
  printf("%lf\n",tailor(1,10));
  printf("%lf\n",e1(1,10));
  printf("%lf\n",e(1,10));
  
}