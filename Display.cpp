#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL;                     // creating structure here itself.

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
// first -> 3 -> 5 -> 7 -> 9 -> 11 -> 15(last)

// Itreative version -->
//Time -> O(n)     Space -> O(1)
void display(struct Node *p){       
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}
// Recursive version -->
//Time -> O(n)     Space -> O(n)
void dispaly_01(struct Node *p){    
    if(p != NULL){
        cout<<p->data<<" ";
        dispaly_01(p->next);
    }
}
                   
int main()
{
    int A[] = {3,5,7,9,11,15};
    create(A,6);
    display(first);
    cout<<endl;
    dispaly_01(first);
     
    return 0;
}