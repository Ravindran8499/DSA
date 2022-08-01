#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    char *A;
};

int createStack(Stack *st, int size){
    st->size = size;
    st->top = -1;
    st->A = new char[size];
};

int Push(Stack *st, char x)
{
    if (st->top == st->size - 1)
    {
        cout << "The stack is full!!"
             << "\n";
    }
    else
    {
        st->top++;
        st->A[st->top] = x;
    }
}

char Pop(Stack *st)
{
    char x;
    if (st->top == -1)
    {
        cout << "the stack is full!!"
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
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << st.A[i] << "\t";
    }
    cout << "\n";
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int precendence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        return 0;
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

int isBalanced(char *A)
{
    int size = strlen(A);
    struct Stack st;
    createStack(&st, size);
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == '(')
        {
            Push(&st, A[i]);
        }
        else if (A[i] == ')')
        {
            if (isEmpty(st))
            {
                return false;
            }
            Pop(&st);
        }
    }
    return isEmpty(st) ? true : false;
}

int stackTop(Stack st)
{
    if (st.top == -1)
    {
        return -1;
    }
    else
    {
        return st.A[st.top];
    }
}

char *infixtoPostfix(char *infix)
{
    int size = strlen(infix);
    struct Stack st;
    createStack(&st, size);
    char *postfix = new char[size];
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precendence(infix[i]) > precendence(stackTop(st)))
            {
                Push(&st, infix[i++]);
            }
            else
            {
                postfix[j++] = Pop(&st);
            }
        }
    }
    while (!isEmpty(st))
    {
        postfix[j++] = Pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
}

int evaluationOfPostfix(char *postfix)
{
    struct Stack st;
    int size = strlen(postfix);
    createStack(&st, size);
    int i, x1, x2, result;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            Push(&st, postfix[i] - '0');
        }
        else
        {
            x2 = Pop(&st);
            x1 = Pop(&st);
            switch (postfix[i])
            {
            case '+':
                result = x1 + x2;
                break;
            case '-':
                result = x1 - x2;
                break;
            case '*':
                result = x1 * x2;
                break;
            case '/':
                result = x1 / x2;
                break;
            }
            Push(&st, result);
        }
    }
    return Pop(&st);
}

int main()
{
    struct Stack st;
    char A[] = "3*5+6/2-4";
    cout << evaluationOfPostfix(infixtoPostfix(A));
}