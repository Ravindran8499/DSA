#include<iostream>
#include<stdio.h>
using namespace std;
struct node {
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
    tail->next = p;
    tail = p;
  }
}

int display(struct node *p){
  if(p==NULL){
    cout<<"The linked List is empty";
  }

  while(p!=NULL){
    printf("%d\t",p->data);
    p = p->next;

  }
  printf("\n");
}

int max(struct node *p){
  int max = INT32_MIN; //built in data which willbe the least value in 32 bit compiler
  while(p!=NULL){
    if(p->data>max){
      max = p->data;
    }
    p = p->next;
  }
  printf("Max: %d\n",max);
}

int min(struct node *p){
  int min = INT32_MAX; //built in data which will be the max value in 32 bit compiler
  while(p!=NULL){
    if(p->data<min){
      min = p->data;
    }
    p = p->next;
  }
  printf("MIN: %d\n",min);
}

int main(){
  addNode(1);
  addNode(2);
  addNode(3);
  addNode(4);
  addNode(5);
  addNode(6);
  addNode(7);
  addNode(8);
  addNode(9);
  addNode(10);
  addNode(11);
  addNode(12);
  display(head);
  max(head);
  min(head);
}