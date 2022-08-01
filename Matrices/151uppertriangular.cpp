#include<iostream>
#include<stdio.h>
struct Matrix{
  int A[100];
  int n;  
};

int setrow(struct Matrix *m,int i,int j,int x){
  int result = (m->n*(i-1) + (i-2)*(i-1)/2) + j-i;
  if(i<=j){
    m->A[result] = x;
  }

}

int displayrow(struct Matrix m){
  int i,j;
  for(i=1;i<=m.n;i++){
    for(j=1;j<=m.n;j++){
      if(i<=j){
        printf("%d\t",m.A[m.n*(i-1) + (i-2)*(i-1) + j-i]);
      }else{
        printf("%d\t",0);
      }
    }
    printf("\n");
  }

}

int setcol(struct Matrix *m,int i,int j,int x){
  int result = j*(j-1)/2 +i-1;
  if(i<=j){
    m->A[result] = x;
  }
}

void displaycol(struct Matrix m){
  int i,j;
  for(i=1;i<=m.n;i++){
    for(j=1;j<=m.n;j++){
      if(i<=j){
        printf("%d\t",m.A[j*(j-1)/2 +i-1]);
      }else{
        printf("%d\t",0);
      }
    }
    printf("\n");
  }
}
int main(){
  struct Matrix m;
   m.n = 3;
  printf("upper triangular matrix by row major\n");
  setrow(&m, 1, 1, 12);
  setrow(&m, 1, 2, 45);
  setrow(&m, 1, 3, 15);
  setrow(&m, 2, 2, 72);
  setrow(&m, 2, 3, 32);
  setrow(&m, 3, 3, 69);
  displayrow(m);
  printf("Upper triangulat Matrix by coloum major\n");
  setcol(&m, 1, 1, 12);
  setcol(&m, 1, 2, 45);
  setcol(&m, 1, 3, 15);
  setcol(&m, 2, 2, 72);
  setcol(&m, 2, 3, 32);
  setcol(&m, 3, 3, 69);
  displaycol(m);


}
