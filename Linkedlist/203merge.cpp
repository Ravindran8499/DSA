#include<bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node *next;
};

struct node *first=NULL,*second=NULL;
struct node *last = NULL;
struct node *third = NULL;

//This function creates the First Linked List
int addNodefirst(int data){
  struct node *p = new node;
  p->data  = data;
  p->next = NULL;

  if(first == NULL){
    first = p;
    last = p;
  }else{
    last->next = p;
    last = p;

  }
}

//This function creates the second Linked List
int addNodesecond(int data){
  struct node *p = new node;
  p->data  = data;
  p->next = NULL;

  if(second == NULL){
    second = p;
    last = p;
  }else{
    last->next = p;
    last = p;

  }
}

int merge(){
  
  last = NULL;
  if(first->data < second->data){
    third = first;
    last = first;
    first = first->next;
    last->next = NULL;
  }else{
    third = second;
    last = second;
    second = second->next;
    last->next = NULL;
  }
  while(first!=NULL && second!=NULL){
    if(first->data < second->data){
      last->next = first;
      last = first;
      first = first->next;
      last->next = NULL;
    }else{
      last->next = second;
      last = second;
      second = second->next;
      last->next = NULL;
    }
  }
  if(first!=NULL){
    last->next = first;
  }else{
    last->next = second;
  }

}

int displayfirst(){
struct node *p = first;
while(p!=NULL){
  cout<<p->data<<"\t";
  p=p->next;
 }
cout<<"\n";
}


int displaysecond(){
  struct node *p = second;
  while(p!=NULL){
  cout<<p->data<<"\t";
  p=p->next;
 }
cout<<"\n";
}


int displaythird(){
  struct node * p = third;
  while(p!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<"\n";
}

int main(){

  addNodefirst(78);
  addNodefirst(84);
  addNodefirst(89);
  addNodefirst(95);
  addNodefirst(100);
  displayfirst();
  addNodesecond(79);
  addNodesecond(85);
  addNodesecond(86);
  addNodesecond(90);
  addNodesecond(96);
  displaysecond();
  merge();
  cout<<"After merging: "<<"\t";
  displaythird();
}

