#include<bits/stdc++.h>
using namespace std;

struct Stack {
    int size;
    int top;
    char *A;
};

int createStack(Stack *st,int size){
    st->size = size;
    st->top = -1;
    st->A = new char[size];
}

int Push(Stack *st,char x){
    if(st->top == st->size-1){
        cout<<"Stack is full!!"<<"\n";
    }else{
        st->top++;
        st->A[st->top] = x;
    }
}

char Pop(Stack *st){
    char x;
    if(st->top == -1){
        cout<<"Stack is already empty!!"<<"\n";
    }else{
        x = st->A[st->top];
        st->top--;
    }
    return x;
}


int display(Stack st){
    int i;
    for(i=st.top;i>=0;i--){
        cout<<st.A[i]<<"\t";
    }
    cout<<"\n";
}


int isEmpty(Stack st){
    if(st.top == -1){
        return true;   //true = 1
    }else{
        return false;   //false = 0
    }
}

int isOperand(char x){
     if(x == '+' ||x == '-' ||x == '*' ||x == '/'  ){
         return false;
     }else{
         return true;
     }
}

int precendence(char x){
    if(x == '+' ||x == '-' ){
        return 1;
    }else if(x == '*' ||x == '/' ){
        return 2;
    }else{
        return 0;
    }
}

int stackTop(Stack st){
    if(st.top == -1){
        return 0;
    }else{
        return st.A[st.top];
    }
}

char * infixtopostfix(char *infix){  
    struct Stack st;
    int size = strlen(infix);
    createStack(&st,size);
    char *postfix = new char[size+1];
    int i=0;
    int j=0;
    while(infix[i] !='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            if(precendence(infix[i]) > precendence(stackTop(st))){
                Push(&st,infix[i++]);
            }else{
                postfix[j++] = Pop(&st);
            }
        }

    }
    while(!isEmpty(st)){
         postfix[j++]= Pop(&st);
    }
    postfix[j] = '\0';
    return postfix;

}

int main(){
    struct Stack st;
    createStack(&st,30);
    char A[] = "a*b+c/d-e";
    cout<<infixtopostfix(A);
}

