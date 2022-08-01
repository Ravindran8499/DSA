#include<bits/stdc++.h>
using namespace std;


struct Queue{
    int size;
    int front;
    int rear;
    int *A;
};


int  createQueue(struct Queue *q,int size){
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->A = new int[size];
}

int enQueue(struct Queue *q,int x){
    if(q->rear == q->size-1){
        cout<<"Queue is Full!!"<<endl;
    }else{
        q->rear++;
        q->A[q->rear] = x;
    }
}

int deQueue(struct Queue *q){
    int x = -1;
    if(q->front==q->rear){
        cout<<"Queue is Empty!!";
    }else{
        q->front++;
        x = q->A[q->front];
    }
    return x;

}

int display(struct Queue q){
    for(int i=q.front+1;i<=q.rear;i++){
        cout<<q.A[i]<<"\t";
    }
    cout<<"\n";

}





int main(){
    struct Queue q;
    createQueue(&q,5);
    enQueue(&q,5);
    display(q);
    enQueue(&q,4);
    display(q);
    enQueue(&q,3);
    display(q);
    enQueue(&q,2);
    display(q);
    enQueue(&q,1);
    display(q);
    enQueue(&q,0);
    display(q);
    enQueue(&q,0);
    display(q);
    deQueue(&q);
        display(q);
    deQueue(&q);
        display(q);
    deQueue(&q);
        display(q);
    deQueue(&q);
        display(q);
    deQueue(&q);
        display(q);
    deQueue(&q);

}