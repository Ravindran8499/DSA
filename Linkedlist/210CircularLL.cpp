#include<bits/stdc++.h>
using namespace  std;


struct node{
  int data;
  struct node *next;
};

struct node *head,*tali;

int createCircularLinkedList(int A[],int n){
  struct node *last;
  
  head = new node;
  head->data =A[0];
  head->next = head;
  last = head;

  for(int i=1;i<n;i++){
    struct node *t = new node;
    t->data = A[i];
    t->next = last->next;
    last->next = t;
    last = t;

  }
}

int insertInAcircularLinkedList(int data,int pos){
  struct node *p = new node;
  struct node *q = head;
  p->data = data;
  for(int i=0;i<pos-1;i++){
    q=q->next;
  }
  p->next = q->next;
  q->next = p;
  
  

}

int insertNodebeforeHeadnode(int data){
  struct node *p = head;
  struct node *t = new node;
  t->data = data;
  while(p->next!=head){
    p=p->next;

  }
  t->next = p->next;
  p->next = t;

}


int display(struct node *p){
  do{
    cout<<p->data<<"\t";
    p=p->next;
  }while(p!=head);
  cout<<"\n";
}



int deleteComplete(int pos){
  if(pos == 1){
    struct node *p = head;
    while(p->next!=head){
      p=p->next;
    }
    if(p==head){
      delete head;
      head = NULL;
    }else{
      p->next = head->next;
      delete head;
      head = p->next;
    }
  }else{
    struct node *p = head,*q = NULL;
    for(int i=0;i<pos-1;i++){
      q=p;
      p=p->next;
    }
    q->next = p->next;
    delete p;
  }

}

int main(){
int A[5] = {1,2,3,4,5};
createCircularLinkedList(A,5);
display(head);
insertInAcircularLinkedList(12,3);
insertInAcircularLinkedList(17,3);
display(head);
insertNodebeforeHeadnode(45);
display(head);
insertNodebeforeHeadnode(42);
display(head);
deleteComplete(3);
display(head);
}
