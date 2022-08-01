#include<bits/stdc++.h>
using namespace std;

struct node{
  struct node *prev;
  int data;
  struct node *next;

};
struct node *head,*tail = NULL;

int addNode(int data){
  struct node *p = new node;
  p->prev = NULL;
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

int display(){
  struct node *p = head;
  while(p!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<"\n";
}

int insertinAgivenPosition(int data,int pos){
  struct node *p = new node;
  struct node *q = head;
  p->data = data;
  p->prev = NULL;
  p->next = NULL;
  for(int i=0;i<pos-1;i++){
    q=q->next;
  }
  p->next = q->next;
  q->next = p;
}
int insertingAtFirst(int data){
  struct node*p = new node;
  p->data = data;
  p->next = head;
  head = p;

  
}

int main(){
  addNode(45);
  addNode(0);
  addNode(9);
  addNode(2);
  addNode(36);
  addNode(90);
  addNode(4);
  display();
  insertinAgivenPosition(12,3);
  display();
  insertinAgivenPosition(16,3);
  display();
  insertingAtFirst(33);
  display();

}