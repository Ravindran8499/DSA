#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

int Push(node *st,int x){
    struct node *t = new node;
    if(t==NULL){
        cout<<"THe stack is Full!!"<<"\n";
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Pop(node *st){
    int x =-1;
    if(top==NULL){
        cout<<"The stack is empty!!"<<"\n";
    }else{
        struct node *p =top;
        top = top->next;
         x = p->data ;
        delete p;
    }
}

int display(node st){
    struct node *p = top;
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<"\n";
}

int main(){
     struct node st;
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
    Push(&st,6);
    display(st);
    Push(&st,7);
    display(st);
    Pop(&st);
    Pop(&st);
    Pop(&st);
    Pop(&st);
    display(st); 
}