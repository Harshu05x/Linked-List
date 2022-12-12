#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL;                    

void create(int A[], int n){
    int i;
    struct Node *t,*last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void removeDuplicates(){
    Node *p = first;
    Node *q = first->next;

    while(q){
        if(p->data != q->data){
            p = q;
            q = q->next; 
        }
        else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void display(){
    Node *p = first;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main()
{   
    int A[] = {1,1,2,3,3,3,3,3,4,5,6,7,8,9,9,9};
    create(A,16);
    removeDuplicates();
    display();       
    return 0;
}