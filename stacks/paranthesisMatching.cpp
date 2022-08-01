#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int size;
    int top = -1;
    char *A;
};

int createStack(Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->A = new char[size];
}

int Push(Stack *st, char x)
{
    if (st->top == st->size - 1)
    {
        cout << "Thst stack is full!!"
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
        cout << "Stack is empty!!"
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
    for (int i = st.top; i >= 0; i--)
    {
        cout << st.A[i] << "\t";
    }
    cout << "\n";
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

int isBalanced(char *B)
{
    int size = strlen(B);
    Stack st;
    createStack(&st, size);
    for (int i = 0; B[i] != '\0'; i++)
    {
        if (B[i] == '(')
        {
            Push(&st, B[i]);
        }
        else if (B[i] == ')')
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

int main()
{
    struct Stack st;
    // createStack(&st,10);
    // Push(&st,'a');
    // display(st);
    // Push(&st,'b');
    // display(st);
    // Push(&st,'c');
    // display(st);
    // Push(&st,'d');
    // display(st);
    // Push(&st,'e');
    // display(st);
    // Push(&st,'d');
    // display(st);
    // cout<<isEmpty(st);
    char A[] = "(a+b))*(a+b)*(a+b)";
    cout << isBalanced(A);
}
