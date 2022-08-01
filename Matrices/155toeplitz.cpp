#include<iostream>
#include<stdio.h>
struct Matrix{
  int A[100];
  int n;
};
void set(struct Matrix *m,int i,int j,int x){
  if(i<=j){
    m->A[j-i] =x;
  }else if(i>j){
    m->A[i-j-1+m->n] = x;
  }
}

int display(struct Matrix m){
  int i,j;
  for(i=1;i<=m.n;i++){
    for(j=1;j<=m.n;j++){
      if(i<=j){
        printf("%d\t",m.A[j-i]);
      }else if(i>j){
        printf("%d\t",m.A[i-j-1+m.n]);
      }
    }
    printf("\n");
  }
}



int main(){
  struct Matrix m;
  m.n = 4;
  set(&m, 1, 1, 1);
  set(&m, 1, 2, 2);
  set(&m, 1, 3, 3);
  set(&m, 1, 4, 4);
  set(&m, 2, 1, 5);
  set(&m, 3, 1, 6);
  set(&m, 4, 1, 7);
  display(m);

}