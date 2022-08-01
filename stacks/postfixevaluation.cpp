#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    char *A;
};

int createStack(Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->A = new char[size];
}

int push(Stack *st, char x)
{
    if (st->top == st->size - 1)
    {
        cout << "Stack is Full!!"
             << "\n";
    }
    else
    {
        st->top++;
        st->A[st->top] = x;
    }
}

char pop(Stack *st)
{
    char x;
    if (st->top == -1)
    {
        cout << "The stack is empty!!"
             << "\n";
    }
    else
    {
        x = st->A[st->top];
        st->top--;
    }
    return x;
}

int display(Stack st)
{
    if (st.top == -1)
    {
        cout << "The stack is empty!!"
             << "\n";
    }
    else
    {
        for (int i = st.top; i >= 0; i--)
        {
            cout << st.A[i] << "\t";
        }
        cout << "\n";
    }
}
int isEmpty(Stack st)
{
    if (st.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int isBalanced(char *A)
{
    struct Stack st;
    int size = strlen(A);
    createStack(&st, size);
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == '(')
        {
            push(&st, A[i]);
        }
        else if (A[i] == ')')
        {
            if (isEmpty(st))
            {
                return false;
            }
            pop(&st);
        }
    }
    return isEmpty(st) ? true : false;
}

// little bit wrong
int postFixEvaluation(char *postfix)
{
    struct Stack st;
    int size = strlen(postfix);
    createStack(&st, size);
    int i, r, x1, x2;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(&st, postfix[i] - '0');
        }
        else
        {
            x2 = pop(&st);
            x1 = pop(&st);
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                // push(&st,r);
                break;
            case '-':
                r = x1 - x2;
                // push(&st,r);
                break;
            case '*':
                r = x1 * x2;
                // push(&st,r);
                break;
            case '/':
                r = x1 / x2;
                // push(&st,r);
                break;
            }
            push(&st, r);
        }
    }
    return pop(&st);
}

int main()
{
    // struct Stack st;
    // char A[] = "(())(())";
    // cout<<isBalanced(A);
    char A[] = "35*62/+4-";
    cout << postFixEvaluation(A);
}
