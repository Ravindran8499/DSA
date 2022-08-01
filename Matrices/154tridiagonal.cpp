#include<iostream>
#include<stdio.h>
struct Matrix{
  int A[500];
  int n;

};

void set(struct Matrix *m,int i,int j,int x){
  
  if(i - j == 1){
    m->A[i-2] = x;
  }else if(i-j ==0){
    m->A[m->n+i-2] = x;
  }else if(i-j == -1){
    m->A[2*(m->n)+i-2] = x;
  }

}

int display(struct Matrix m){
  int i,j;
  for(i=0;i<=m.n;i++){
    for(j=0;j<=m.n;j++){
      if(i-j == 1){
        printf("%d\t",m.A[i-2]);
      }else if(i-j == 0){
        printf("%d\t",m.A[m.n + i-2]);
      }else if(i-j == -1){
        printf("%d\t",m.A[2*(m.n)+i-2]);
      }else{
        printf("%d\t",0);
      }
    }
    printf("\n");
  }
}


int main(){
  struct Matrix m;
  m.n = 4;
  set(&m,1,1,10);
  set(&m,2,2,1);
  set(&m,3,3,14);
  set(&m,4,4,17);
  set(&m,1,2,0);
  set(&m,2,3,2);
  set(&m,3,4,20);
  set(&m,2,1,40);
  set(&m,3,2,71);
  set(&m,4,3,69);
  display(m);

}