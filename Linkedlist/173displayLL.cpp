#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};


struct node *head,*tail = NULL;

int addNode(int data){
  struct node *newNode = (struct node *)malloc(sizeof(struct node));

  newNode->data = data;
  newNode->next = NULL;

  if(head == NULL){
    head = newNode;
    tail = newNode;
  }else{
    tail->next = newNode;
    tail = newNode;
  }
}


int display(){
  struct node *p = head;
  int count = 0;
  if(p == 0){
    printf("\nThe linked list is empty\n");
    return 0;
  }
  while(p!=0){
    count++;
    printf("%d\t",p->data);
    p = p->next;
  }
  printf("\nNo of nodes: %d\n",count);
}

//recursive display of linked list .If printf comes after the call then it will become head recursion and print the reversed link list
int Rdisplay(struct node *p){
  
  if(p!=NULL){
    Rdisplay(p->next);
    printf("%d\t",p->data);
  }
}

int main(){
  addNode(15);
  addNode(89);
  addNode(99);
  addNode(9);
  addNode(36);
  addNode(89);
  addNode(74);
  addNode(9);
  addNode(79);
  addNode(23);
  addNode(56);
  addNode(39);
  display();
  Rdisplay(head);
  printf("\n");



}


