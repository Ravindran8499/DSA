#include<bits/stdc++.h>
using namespace std;

struct node{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head,*tail = NULL;


int insertAtEnd(int data){
  struct node * p  = new node;
  p->prev = NULL;
  p->data = data;
  p->next = NULL;
  if(head == NULL){
    head = p;
    tail = p;
  }else{
    tail->next = p;
    p->prev=tail;
    tail = p;
  }
}
int insertAtThebegining(int data){
  struct node *p = new node;
  p->prev = NULL;
  p->data = data;
  p->next = head;
  head->prev = p;
  head = p;
}

int insertAtAnyGivenposition(int data,int pos){
  struct node *p = new node;
  struct node *q = head;
  p->prev = NULL;
  p->data = data;
  p->next = NULL;
  for(int i=0;i<pos-1;i++){
    q=q->next;
  }
  p->next = q->next;
  p->prev = q;
  if(q->next!=NULL){
    q->next->prev = p;
  }
  q->next = p;


}

int display(){
  struct node *p = head;
  while(p!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<endl;
}

int main(){
  insertAtEnd(15);
  insertAtEnd(16);
  insertAtEnd(13);
  insertAtEnd(1);
  insertAtEnd(125);
  display();
  insertAtThebegining(20);
  display();


}

