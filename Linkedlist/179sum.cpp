#include<iostream>
struct node{
  int data;
  struct node *next;
};

struct node *head ,*tail = NULL;



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

int display(){
  struct node *p = head;
  if(p == NULL){
    printf("\nThe linked list is empty\n");
  }
  while(p!=NULL){
    printf("%d\t",p->data);
    p=p->next;
  }
  printf("\n");
}

//this function will initilise the pointer p to head. therefore it will calculation of sum will start from the beginging or the first node. Best function is sum2()
int sum1(){
  int sum = 0;
  struct node *p = head;

  while(p!=NULL){
    sum = sum + p->data;
    p = p->next;
  }
  printf("Sum: %d\n",sum);

}

int sum2(struct node *p){
   int sum = 0;
   while(p!=NULL){
     sum = sum +p->data;
     p=p->next;
   }
  printf("Sum: %d\n",sum);

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
  display();
  sum1();
  sum2(head);
}