#include<bits/stdc++.h>
using namespace std;

struct Stack {
  int size;
  int top;
  int *A;
};

int createStack(struct Stack *st,int size){
  st->size = size;
  st->top = -1;
  st->A = new int[size];
}

int Push(Stack *st,int x){
  if(st->top == st->size-1){
    cout<<"Stack is full!!"<<endl;
  }else{
    st->top++;
    st->A[st->top] =  x;
  }
}

int Pop(Stack *st){
  int x = -1;
  if(st->top == -1){
    cout<<"Stack is empty"<<endl;
  }else{
    x = st->A[st->top];
    st->top--;
  }
  return x;
}


int display(Stack st){
  if(st.top == -1){
    cout<<"The stack is empty!!"<<endl;
  }
  else{
    for(int i=st.top;i>=0;i--){
      cout<<st.A[i]<<"\t";
    }
    cout<<"\n";
  }
}



int main(){
  struct Stack st;
  createStack(&st,10);
  Push(&st,1);
  display(st);
  Push(&st,2);
  display(st);
  Push(&st,3);
  display(st);
  Push(&st,4);
  display(st);
  Push(&st,5);
  display(st);
  Pop(&st);
  display(st);
  Pop(&st);
  display(st);
  Pop(&st);
  display(st);
}