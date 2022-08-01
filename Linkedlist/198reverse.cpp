#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node *next;
};

struct node *head = NULL,*tail = NULL;

int insertinSortedList(int data){
  struct node*p = head,*q = NULL;
  struct node *t=  new node;
  t->data = data;
  while(p!=NULL && p->data < data){
    q=p;
    p=p->next;
  }
  if(p == head){
    t->next = head;
    head = t;
  }else{
    t->next = q->next;
    q->next = t;
  }
}

int display(){
  struct node *p = head;
  while(p!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<"\n";
}

int reverseUsingArray(struct node *p){
  
  int i =0,count = 0;
  while(p!=NULL){
    count++;
    p=p->next;
  }
  p=head;
  int A[count];
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

int recursieReverse(struct node *p){
  if(p!=NULL){
    recursieReverse(p->next);
    cout<<p->data<<"\t";
  }
}

int reverseLink(struct node *p){
  struct node *q = NULL,*r= NULL;
  while(p!=NULL){
    r=q;
    q=p;
    p=p->next;
    q->next = r;
  }
  head = q;
}



int main(){
insertinSortedList(78);
insertinSortedList(8);
insertinSortedList(7);
insertinSortedList(45);
insertinSortedList(12);
insertinSortedList(36);
insertinSortedList(96);
insertinSortedList(8);
display();
reverseUsingArray(head);
display();
reverseLink(head);
display();


}