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

// Here we reversing elements
void reverse(Node *p){
    p = first;
    int A[6];
    int i = 0;
    while(p){                   
        A[i++] = p->data;       // It will copy all ele of LL in array...
        p = p->next;
    }
    p = first; i--;
    while (p){
        p->data = A[i--];       // It will copy all ele of array in LL in reverse order...
        p = p->next;
    }
    
}

// Here we revesring Links...        imp--> revesring links is always prefered.
// we use sliding pointers here
void reverse_01(){
    Node *p = first;
    Node *q = NULL,*r = NULL;
    // p q r this sliding pointers
    while(p){
        r = q;             
        q = p;
        p = p->next;
        q->next = r;            // It wil reverse links
    }
    first = q;
}

// Its a recursive version...
void reverse_02(Node *q,Node *p){
    if(p){
        reverse_02(p,p->next);
        p->next = q;
    }
    else first = q;

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
    int A[] = {3,5,7,9,11,15};
    create(A,6);

    reverse_02(NULL,first);
    display();
       
    return 0;
}