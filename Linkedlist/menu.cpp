#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node *next;

};

struct node *head,*tail = NULL;


int insertNodeAtLast(int data){
  struct node *p = new node;
  p->data = data;
  p->next = NULL;

  if(head == NULL){
    head = p;
    tail = p;
  }else{
    tail->next = p;
    tail = p;
  }
}


int insertNodeAtbegining(int data){
  struct node *p = new node;
  p->data = data;
  p->next = head;
  head = p;
}



int insertNodeAtaGivenPosition(int data,int pos){
  struct node *p = new node;
  p->data = data;
  struct node *q = head;
  for(int i=0;i<pos-1;i++){
    q=q->next;
  }
  p->next = q->next;
  q->next = p;

}



int deleteNodeAtbegining(){
  struct node *p = head;
  head = head->next;
  delete p;
}


int deleteNodeAtGivenPosition(int pos){
  struct node *p  = head;
  struct node *q = NULL;
  for(int i=0;i<pos-1;i++){
    q=p;
    p=p->next;
  }
  q->next = p->next;
  delete p;

}


int insertInASortedList(int data){
  struct node *p = head;
  struct node *q = NULL;
  struct node *t = new node;
  t->data = data;
  if(head == NULL){
    head = t;
    tail = t;
  }else{
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
}

int reverseUsinganArray(struct node *p){
  int count = 0;
  int i=0;
  while(p!=NULL){
    count = count+1;
    p=p->next;
  }
  int A[count];
  p=head;
  while(p!=NULL){
    A[i++] = p->data;
    p=p->next;
  }
  p=head;
  i--;
  while(p!=NULL){
    p->data  = A[i--];
    p=p->next;
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

int Rdisplay(struct node *p){
  if(p!=NULL){
    Rdisplay(p->next);
    cout<<p->data<<"\t";
  }
}

int removeDuplicates(){
  struct node *p = head;
  struct node *q = head->next;

  while(q!=NULL){
    if(p->data !=q->data){
      p=q;
      q=q->next;
    }else{
      p->next = q->next;
      delete q;
      q=p->next;
    }
  }

}


int main(){
  cout<<"\n\t1.Insert Node at the end\n\t"
}