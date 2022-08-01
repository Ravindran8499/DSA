#include<bits/stdc++.h>
using namespace std;

int isBalanced(char *A){
    stack<char> st;
    int size = strlen(A);
    for(int i=0;A[i]!='\0';i++){
        if(A[i]  == '('){
            st.push(A[i]);
        }else if(A[i] == ')'){
            if(st.empty()){
                return false;
            }
            st.pop();
        }
    }
    return st.empty()?true:false;
}

int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return false;
    }else{
        return true;
    }
}

int precendence(char x){
    if(x=='+' || x=='-' ){
        return 1;
    }else if(x=='*' || x=='/'){
        return 2;
    }else{
        return 0;
    }
}

char *infixtoPosfix(char * infix){
    int size = strlen(infix);
    char *postfix = new char[size+1];
    stack<char> st;
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            if(precendence(infix[i]) > precendence(st.top())){
                st.push(infix[i++]);
            }else{
                postfix[j++] = st.top();
                st.pop();
            }
        }
    }

    while(!st.empty()){
        postfix[j++] = st.top();
        st.pop();
    }
    postfix[j] = '\0';
    return postfix;

    

}


int main(){
    char infix[] = "a+b*c-d/e";
    char B[] = "((()))()(())";
    cout<<isBalanced(B);
    cout<<infixtoPosfix(infix);
 
}
