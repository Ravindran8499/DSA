#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node *front = NULL;
struct node *rear = NULL;

int enqueue(int data){
    node *p = new node;
    if(p==NULL){      //If the New Node is only not getting created then heap is full!!...The queue is full simply doesnot make any sense because we can keep on adding nodes
        cout<<"Queue is full!!"<<endl;
    }else{
        p->data = data;
        p->next = NULL;
        if(front == NULL){
            front = p;
            rear = p;
        }else{
            rear->next = p;
            rear = p;
        }
    }

}

int deQueue(struct node *p){
    int x = -1;
    if(front == NULL){
        cout<<"Queue is Empty!!"<<endl;
    }else{
        p=front;
        front = front->next;
        x = p->data;
        delete p;

    }
    return x;
}


int display(node *p){
    p = front;
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<"\n";

}


int main(){
    struct node p;
    enqueue(12);
    display(&p);
    enqueue(22);
    display(&p);
    enqueue(32);
    display(&p);
    enqueue(12);
    display(&p);
    enqueue(42);
    display(&p);
    deQueue(&p);
    display(&p);
    deQueue(&p);
    display(&p);


}