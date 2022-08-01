#include<iostream>
using namespace std;


struct node{
  int data;
  struct node *next;

};

struct node *head,*tail = NULL;




int addNode(int data){
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


int insertNodeatFirst(int data){
  struct node *p = new node;
  p->data = data;
  p->next = head;
  head = p;

}




int insertNodeatposition(int data,int pos){
  //This code will work insertion after the first node as well as insertion after the last node also

  struct node *p = new node;
  struct node *q = head;//this should not be null.
  p->data = data;

  for(int i=0;i<pos-1;i++){
    q=q->next;
  }
  p->next = q->next;
  q->next = p;

}





int display(){
  struct node*p = head;
  while(p!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<"\n";
}


int main(){
  for(int i=0;i<100;i+=10){
    addNode(i);
  }
  display();
  cout<<"\n";
  insertNodeatFirst(30);
  insertNodeatposition(93,4);
  display();
  insertNodeatposition(39,4);
  display();
  insertNodeatposition(48,4);
  display();
  insertNodeatposition(12,4);
  insertNodeatposition(11,1);
  display();

}