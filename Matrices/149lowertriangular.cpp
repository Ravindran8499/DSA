#include<iostream>
#include<stdio.h>
struct Matrix{
  int A[100] ;
  int n;
};



void setrow(struct Matrix *m,int i,int j,int x){
  int result = ((i*(i-1))/2) +j-1;
  if(i>=j){
    m->A[result] = x;
  }
}

int displayrow(struct Matrix m){
  int i,j;
  for(i=1;i<=m.n;i++){
    for(j=1;j<=m.n;j++){
      if(i>=j){
        printf("%d\t",m.A[(i*(i-1)/2) + j-1]);
      }else{
        printf("%d\t",0);
      }   
    }
    printf("\n");
  }

}

void setcol(struct Matrix *m,int i,int j,int x){
  int result = (m->n*(j-1) + (j-2)*(j-1))+i-j;
  if(i>=j){
    m->A[result] = x;
  }

}
 int displaycol(struct Matrix m){
   int i,j;
   for(i=1;i<=m.n;i++){
     for(j=1;j<=m.n;j++){
       if(i>=j){
         printf("%d\t",m.A[(m.n*(j-1) + (j-2)*(j-1))+i-j]);
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
  setcol(&m, 1, 1, 12);
  setcol(&m, 2, 1, 45);
  setcol(&m, 2, 2, 15);
  setcol(&m, 3, 1, 72);
  setcol(&m, 3, 2, 32);
  setcol(&m, 3, 3, 69);
  displaycol(m);



}