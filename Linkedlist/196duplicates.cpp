#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *next;

};

struct node *head,*tail = NULL;

int insertinSortedList(int data){
  struct node *p =head,*q = NULL;
  struct node *t = new node;
  t->data = data;
  while(p!=NULL && p->data <data){
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


int removeDuplicates(){
struct node *p = head;
struct node *q = p->next;
while(q!=NULL){
  if(p->data !=q->data){
    p=q;
    q=q->next;
  }else{
    p->next = q->next;
    delete q;
    q= p->next;
  }
}





}

int main(){
  insertinSortedList(16);
  insertinSortedList(2);
  insertinSortedList(2);
  insertinSortedList(1);
  insertinSortedList(6);
  insertinSortedList(79);
  insertinSortedList(90);
  insertinSortedList(10);
  insertinSortedList(3);
  insertinSortedList(2);
  insertinSortedList(90);
  insertinSortedList(100);
  display();
  removeDuplicates();
  display();
}