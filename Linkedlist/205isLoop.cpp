#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  struct node *next;
};

struct node *head ,*tail = NULL;

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


int display(){
  struct node *p = head;
  while(p!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<"\n";
}

int isLoop(struct node *f){
  struct node *p = f;
  struct node *q = f;

  do{
    p=p->next;
    q=q->next;
    if(q!=NULL){
      q=q->next;
    }else{
      ;
    }
  }while(p!=NULL && q!=NULL && p!=q);

  if(p==q){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  addNode(78);
  addNode(7);
  addNode(8);
  addNode(84);
  addNode(7457);
  display();
  struct node *t1,*t2;
  t1 = head->next->next;
  t2 = head->next->next->next->next;
  t2->next = t1;
  cout<<isLoop(head)<<endl;

}