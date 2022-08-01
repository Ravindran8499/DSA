#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int size;
    int top;
    char *A;
};

int createStack(Stack *st,int size){
    st->size = size;
    st->top = -1;
    st->A = new char[size];
}

int PUSH(Stack *st,char x){
    if(st->top == st->size -1){
        cout<<"The stack is full!!"<<endl;
    }else{
        st->top++;
        st->A[st->top] = x;
    }
}

char POP(Stack *st){
    char x;
    if(st->top == -1){
        cout<<"The stack is Empty!!"<<endl;
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
    cout<<endl;
}

int isEmpty(Stack st){
    if(st.top == -1){
        return true;
    }else{
        return false;
    }
}

int Isbalanced(char *A){
    int size = strlen(A);
    struct Stack st;
    createStack(&st,size);
    int i;
    for(i=0;A[i]!='\0';i++){
        if(A[i] =='(' || A[i] == '{' || A[i] == '['){
            PUSH(&st,A[i]);
        }else if(A[i] ==')' || A[i] == '}' || A[i] == ']'){
            if(isEmpty(st)){
                return false;
            }
            POP(&st);         
        }
    }
    if(isEmpty(st)){
        return true;
    }else{
        return false;
    }

}

int isOperand(char x){
    if(x== '+'||x== '-'||x== '*'||x== '/'){
        return false;
    }else{
        return true;
    }
}

int precendence(char x){
    if(x=='+' || x == '-'){
        return 1;
    }else if(x == '*' || x == '/'){
        return 2;
    }else{
        return 0;
    }
}

int stackTop(Stack st){
    if(st.top == -1){
        return -1;
    }else{
        return st.A[st.top];
    }
}

char *convertFromInfixTOPostfix(char *infix){
    int size = strlen(infix);
    struct Stack st;
    createStack(&st,size);
    char *postfix = new char[size+1];
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            if(precendence(infix[i]) > precendence(stackTop(st))){
                PUSH(&st,infix[i++]);
            }else{
               postfix[j++] =  POP(&st);
            }
        }
    }
    while(!isEmpty(st)){
        postfix[j++] = POP(&st);
    }
    postfix[j] = '\0';
    return postfix;
}

int evaluationOfPostifx(char *postfix){
    int size = strlen(postfix);
    struct Stack st;
    createStack(&st,size);
    int i,x1,x2,result;
    for(i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            PUSH(&st,postfix[i]-'0');
        }else{
            x2 = POP(&st);
            x1 = POP(&st);
            switch(postfix[i]){
                case '+':result = x1+x2;
                PUSH(&st,result);
                break;
                case '-':result = x1-x2;
                PUSH(&st,result);
                break;
                case '*':result = x1*x2;
                PUSH(&st,result);
                break;
                case '/':result = x1/x2;
                PUSH(&st,result);
                break;
            }
        }
    }
    return POP(&st);
}

int main(){
    struct Stack st;
    // createStack(&st,10);
    // PUSH(&st,'a');
    // display(st);
    // PUSH(&st,'b');
    // display(st);
    // PUSH(&st,'c');
    // display(st);
    // PUSH(&st,'d');
    // display(st);
    // PUSH(&st,'e');
    // display(st);
    // PUSH(&st,'f');
    // display(st);
    // POP(&st);
    // display(st);
    char A[] = "6+5+3*4";
    cout<<Isbalanced(A)<<endl;
    cout<<convertFromInfixTOPostfix(A)<<endl;
    cout<<evaluationOfPostifx(convertFromInfixTOPostfix(A))<<endl;
}