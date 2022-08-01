#include<bits/stdc++.h>
using namespace std;


struct node {
  int data;
  struct node *next;
};

struct node *head, *tail = NULL;

int addNode(int data){
  struct node *p  = new node;
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


int deleteNode(int pos){
  if(pos == 1){
    struct node *p = head;
    head = head->next;
    int x = p->data;
    delete p;
  }else{
    struct node*p = head,*q = NULL;
    for(int i=0;i<pos-1 && p;i++){
      q=p;
      p=p->next;
    }
    if(p){
    q->next = p->next;
    int x = p->data;
    delete p;
    }else{
      cout<<"Index out of Range!"<<endl;
    }
  }

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
  addNode(10);
  addNode(20);
  addNode(30);
  addNode(40);
  addNode(50);
  addNode(60);
  addNode(70);
  addNode(80);
  addNode(90);
  addNode(100);
  display();
  deleteNode(25);
  display();
  
}