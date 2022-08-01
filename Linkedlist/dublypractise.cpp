#include<bits/stdc++.h>
using namespace std;


struct node{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head,*tail = NULL;

int insertAtBegining(int data){
  node * p = new node;
  p->prev = NULL;
  p->data = data;
  p->next = head;
  head->prev = p;
  head = p;
}

int insertAtEnd(int data){
   struct node *p = new node;
  p->prev = NULL;
  p->data = data;
  p->next = NULL;
  if(head == NULL){
    head = p;
    tail = p;
  }else{
    tail->next = p;
    p->prev = tail;
    tail = p;
  }
}

int display(){
  node *p = head;
  while(p!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<"\n";
}

int insertAfterGivenPosition(int data,int pos){
  node *t = new node;
  node *q = head;
  for(int i=0;i<pos-1;i++){
    q=q->next;
  }
  t->data = data;
  t->next = q->next;
  t->prev = q;
  if(q->next!=NULL){
    q->next->prev = t;
  }
  q->next = t;
}

int deleteFirstNode(){
  node *p = head;
  head = head->next;
  p->next = NULL;
  int x = p->data;
  delete p;

  if(head!=NULL){
    head->prev = NULL;
  }

}

int deleteFromGivenPosition(int pos){
  node *p = head;
  for(int i=0;i<pos-1;i++){
    p=p->next;
  }
  p->prev->next = p->next;
  if(p->next!=NULL){
    p->next->prev = p->prev;
  }
  delete p;

}

int reverseDoubly(){
  node *p = head;
  int count = 0;
  while(p!=NULL){
    count++;
    p=p->next;
  }
  int A[count];
  p=head;
  int i;
  i=0;
  while(p!=NULL){
    A[i++] = p->data;
    p=p->next;
  }

  p=head;
  i--;
  while(p!=NULL){
    p->data = A[i--];
    p=p->next;
  }
}


int main(){
  insertAtEnd(10);
  display();
  insertAtEnd(9);
  display();
  insertAtEnd(8);
  display();
  insertAfterGivenPosition(15,2);
  display();
  insertAtEnd(7);
  display();
  insertAtEnd(6);
  display();
  insertAfterGivenPosition(5,3);
  display();
  insertAtEnd(18);
  display();
  insertAtEnd(28);
  display();
  insertAtEnd(12);
  display();
  deleteFirstNode();
  display();
  deleteFromGivenPosition(3);
  display();
  reverseDoubly();
  display();
}


