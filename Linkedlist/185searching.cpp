#include<iostream>
#include<stdio.h>

using namespace std;

struct node{
  int data;
  struct node *next;
};
struct node *head,*tail = NULL;


int addNode(int data){
  struct node *p = (struct node *)malloc(sizeof(struct node));
  p->data = data;
  p->next = NULL;

  if(head == NULL){
    head = p;
    tail = p;
  }else{
    tail->next =p;
    tail = p;
  }
}



int display(struct node *p){
  if(p==NULL){
    cout<<"the linked list is empty"<<endl;
  }
  while(p!=NULL){
    printf("%d\t",p->data);
    p = p->next;
  }
  printf("\n");
}



struct node *improvedLinearSearch(struct node *p,int key){
  struct node *q = NULL;

  while(p!=NULL){
    if(key == p->data){
      q->next = p->next;
      p->next = head;
      head = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;


}



int main(){
 for(int i=0;i<10;i++){
   addNode(i);
 }
  display(head);
  struct node*t;
  t = improvedLinearSearch(head,9);
  if(t){
    cout<<"Element  found!";
  }else{
    cout<<"Key is not found!";
  }

  display(head);
 
}