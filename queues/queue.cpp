#include<bits/stdc++.h>
using namespace std;


struct Queue{
    int size;
    int front;
    int rear;
    int *A;
};

int createQueue(struct Queue *q,int size){
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->A = new int[size];
}


int enQueue(struct Queue *q,int x){
    if(q->rear == q->size-1){
        cout<<"Queue is full!!"<<endl;
    }else{
        q->rear++;
        q->A[q->rear] = x;
    }
}


int Dqueue(struct Queue *q){
    int x  =-1;
    if(q->rear == q->front){
        cout<<"Queue is already empty!!"<<endl;
    }else{
        q->front++;
        x = q->A[q->front];
    }
}


int display(struct Queue q){
    int i;
    for(i=q.front+1;i<=q.rear;i++){
        cout<<q.A[i]<<"\t";
    }
    cout<<"\n";
}


int main(){
    struct Queue q;

    createQueue(&q,20);
    enQueue(&q,10);
    display(q);
    enQueue(&q,20);
    display(q);
    enQueue(&q,30);
    display(q);
    enQueue(&q,33);
    display(q);
    enQueue(&q,40);
    display(q);
    enQueue(&q,50);
    display(q);
    enQueue(&q,60);
    display(q);
    enQueue(&q,70);
    display(q);
    enQueue(&q,90);
    display(q);
    Dqueue(&q);
    display(q);
    Dqueue(&q);
    display(q);
    Dqueue(&q);
    display(q);
    Dqueue(&q);
    display(q);

}