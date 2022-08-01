#include<bits/stdc++.h>
using namespace std; 

struct node {
  int data;
  struct node *next;

};

struct node *head,*tail = NULL;

int sortedList(int data){
  struct node *p = head,*q = NULL;
  struct node *t = new node;
  t->data = data;

  if(head == NULL){
    head = t;
    tail = t;
  }else{
    while(p!=NULL && p->data < data ){
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

int display(){
  struct node *p = head;
  while(p!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<"\n";
}



int main(){
  sortedList(235);
  display();
  sortedList(2);
  display();
  sortedList(22);
  display();
  sortedList(90);
  display();
  sortedList(55);
  display();
  sortedList(45);
  display();
  sortedList(25);
  display();
  sortedList(15);
  display();
  sortedList(5);
  display();
  sortedList(55);
  display();
  display();
  sortedList(25);
  display();
  sortedList(250);
  display();
  sortedList(89);
  display();





  }