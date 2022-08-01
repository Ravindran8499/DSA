#include<bits/stdc++.h>
using namespace std;
struct node {
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

bool isSorted(){
  int x =  -322768;
  struct node *p = head;
  while(p!=NULL){
    if(p->data < x){
      return false;
      break;
    }else{
       x = p->data; 
       p=p->next;
    }
   
  }
  return true;
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
  addNode(45);
  addNode(6);
  addNode(49);
  addNode(79);
  addNode(80);
  addNode(85);
  addNode(89);
  addNode(90);
  display();
  if(isSorted() == 1){
    cout<<"Sorted"<<endl;
  }else{
    cout<<"not sorted"<<endl;

  }
}