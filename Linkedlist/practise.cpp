#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

node *head , *tail = NULL;

int insertNodeAtLast(int data){
    node *p = new node;
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

int insertNodeAtFirst(int data){
    node *p = new node;
    p->data = data;
    p->next = head;
    head = p;

}

int insertNodeAfteraGivenPosition(int data,int pos){
     struct node *p = new node;
  struct node *q = head;//this should not be null.
  p->data = data;

  for(int i=0;i<pos-1;i++){
    q=q->next;
  }
  p->next = q->next;
  q->next = p;
}

int insertNodeAtGivenposition(int data,int pos){
    node *q = head;
    node *p = new node;
    p->data = data;
    for(int i=0;i<pos-2;i++){
        q=q->next;
    }
    p->next = q->next;
    q->next = p;
}

int insertAtSortedPosition(int data){
    node *p = head;
    node *q = NULL;
    node *t = new node;
    t->data = data;
    if(p == NULL){
        head = t;
        tail = t;
    }
    while(p!=NULL && p->data < data){
        q=p;
        p=p->next;
    }
    if(p == head){
        t->next = head;
        head = t;

    }else{
        t->next = q->next;
        q->next = t;
    }
    
}

int removeDuplicatesFromSortedList(){
    node *p = head;
    node *q = head->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }else{
            p->next = q->next;
            delete q;
            q=p->next;
        }

    }

}

int reverseusingArray(){
    node *p = head;
    int count = 0;
    int i;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    int A[count];
    p=head;
    i=0;
    while(p!=NULL){
        A[i++] = p->data;
        p=p->next;
    }
    i--;
    p=head;
    while(p!=NULL){
        p->data = A[i--];
        p=p->next;
    }
}

int reverseUsingLinks(){
    node *p = head;
    node *q = NULL;
    node *r = NULL;

    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head = q;
}

int deleteFromFirst(){
    node *p = head;
    head = head->next;
    delete p;
}

int deleteFromAnywhereInTheList(int pos){
    int x = -1;
    if(pos == 1){
        deleteFromFirst(); 
    }else{
        node *p = head;
        node *q = NULL;
        for(int i=0;i<pos-1 && p;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next = p->next;
            x = p->data;
            delete p;
        }else{
            cout<<"Index out of Range";
        }
    }

}

int deleteLastNOde(){
    node *p = head;
    node *q = NULL;
    node *r = NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
    }
    r->next = NULL;
    delete q;
}

int deleteAlternatingNodes(){
    node *p = head;
    node *q = head->next;

    while(p!=NULL && q!=NULL){
        p->next = q->next;
        delete q;
        p = p->next;
        if(p!=NULL){
            q= p->next;
        }
    }
}

int IsSorted(){
    int x = -32768;
    node *p = head;
    while(p!=NULL){
        if(p->data < x){
            return false;
        }
        x = p->data;
        p=p->next;
    } 
    return true;
}

int  changedUsingArray(){
    /*getting correct answer but not returning
     node pointer */
    int count = 0;
    node *p = head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    int A[count];
    p=head;
    int i = 0;
    while(p!=NULL){
        A[i++] = p->data;
        p=p->next;
    }
    int sum = 0;
    int mul = 1;
    i--;
    for(;i>=0;i--){
        sum = sum +A[i]*mul;
        mul = mul*10;
    }
    sum = sum +1;

    i=0;
    p=head;
    while(sum > 0){
        int r = sum%10;
        A[i++] = r;
        sum = sum/10;
    }
    i=count-1;
    p=head;
    while(p!=NULL){
        p->data = A[i--];
        p=p->next;
    }


}

int  rotateList(node *head,int d){
    int count = 0;
    node *p = head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    p=head;
    int i=0;
    int A[count];

    while(p!=NULL){
        A[i++] = p->data;
        p=p->next;
    }
    reverse(A,A+d);
    reverse(A+d,A+count);
    reverse(A,A+count);

    p=head;
    i=0;
    while(p!=NULL){
        p->data = A[i++];
        p=p->next;
    }
    

}

int ispallindrome(node *head){
    node*p = head;
    int count = 0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    p=head;
    int A[count];
    int i=0;
    while(p!=NULL){
        A[i++] = p->data;
        p=p->next;
    }
    i=0;
    p=head;
    int sum1 = 0;
    int mul1 = 1;
    for(i=0;i<count;i++){
        sum1 = sum1 + A[i]*mul1;
        mul1 = mul1*10;
    }
    //return sum1;

    int temp1 = sum1;
    int sum2 = 0;
    while(temp1>0){
        int r = temp1%10;
        sum2 = sum2*10 +r;
        temp1 = temp1/10;
    }
   if(sum1 == sum2){
       return true;
   }else{
       return false;
   }



}

int findMidleElementInLinkedList(node *head){
    node *slow = head;
    node *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;

}

int findMiddleElementUsingArray(node *head){
    int count = 0;
    node *p = head;
    node *q = head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    p=head;
    if(count%2!=0){
        int middleElement = ceil(count/2)+1;
        for(int i=0;i<middleElement-1;i++){
            q=q->next;
        }
        return q->data;
    }else{
        int middleElement = (count/2) +1;
        for(int i=0;i<middleElement-1;i++){
            q=q->next;
        }
        return q->data;
    }
}

int floydCycleFindingAlgorithm(node *head){
    //This algorithm tell us that whether there is cycle present in the list or not
    node*p = head;  //move fast
    node *q = head; // move slow
    while(p!=NULL && p->next!=NULL && q!=NULL){
        p=p->next->next;
        q=q->next;
        if(p==q){
            return true;
        }
    }
    return false;
}

int reverseInGroups(node *head,int k){
    int count = 0;
    node *p = head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    p=head;
    int i=0;
    int A[count];
    while(p!=NULL){
        A[i++] = p->data;
        p=p->next;
    }
    for(i=0;i<count;i=i+k){
        int start = i;
        int end = min(i+k-1,count-1);
        while(start < end){
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
            start++;
            end--;
        }
    }
    i=0;
    p=head;
    while(p!=NULL){
        p->data =A[i++];
        p=p->next; 
    }
}

int display(){
    node *p = head;
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<"\n";
}

int main(){
    insertNodeAtLast(1);
    //display();
    insertNodeAtLast(2);
    //display();
    insertNodeAtLast(2);
    insertNodeAtLast(4);
    insertNodeAtLast(5);
    insertNodeAtLast(6);
    insertNodeAtLast(7);
    insertNodeAtLast(8);
    //insertNodeAtLast(5);
    //insertNodeAtLast(6);
    //insertNodeAtLast(7);
    //insertNodeAtLast(8);
    display();
    reverseInGroups(head,4);
    display();
    //cout<<ispallindrome(head); 
    //cout<<floydCycleFindingAlgorithm(head);
    //reverseUsingLinks();
    //display();
    //cout<<ispallindrome(head)<<endl;
    // insertNodeAtLast(4);
    // display(); 
    // insertNodeAtLast(5);
    // display();  
    // rotateList(head,2);
    //display();
    //changedUsingArray();
    //cout<<"\n";
    //display();
    // insertNodeAtLast(40);
    // display();
    // insertNodeAtLast(50);
    // display();
    // insertNodeAtLast(60);
    // display();
    // insertNodeAtLast(70);
    // display();
    // insertNodeAtLast(80);
    // display();
    // insertNodeAtFirst(9);
    // display();
    // insertNodeAtFirst(8);
    // display();
    // deleteLastNOde();
    // display();
    // insertAtSortedPosition(11);
    // display();
    // insertAtSortedPosition(22);
    // display();
    // deleteAlternatingNodes();
    // display();
    // removeDuplicatesFromSortedList();
    // display();
    // insertNodeAfteraGivenPosition(13,4);
    // display();
    // insertNodeAfteraGivenPosition(12,4);
    // display();
    // insertNodeAtGivenposition(11,4);
    // display();
    // insertNodeAfteraGivenPosition(12,4);
    // display();
    // insertNodeAfteraGivenPosition(11,4);
    // display();
    // deleteFromFirst();
    // display();
    // deleteFromAnywhereInTheList(3);
    // display();
    // deleteFromAnywhereInTheList(3);
    // display();
    // deleteFromAnywhereInTheList(1);
    // display();
   
}
