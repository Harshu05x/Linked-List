#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;                    

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
void create2(int A[], int n){
    int i;
    struct Node *t,*last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i = 1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(Node *p){
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}
// It will join 1st and 2nd LL...
void concatinate(Node *p){
    third = p;
    while(p->next) p = p->next;
    p->next = second;
}
// It will merge first and second LL (both LL must be sorted)
// TC--> O(m+n).
void merge(Node *p, Node *q){
    Node *last;
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p) last->next = p;
    else last->next = q;
}
int main()
{   
    int A[] = {10,30,50,70,90};
    int B[] = {2,40,60,80,100};
    create(A,5);
    create2(B,5);
    cout<<"1st--> ";
    display(first);
    cout<<endl;
    cout<<"2nd--> ";
    display(second);
    cout<<endl;
    // concatinate(first);
    merge(second,first);
    cout<<"3rd--> ";
    display(third);    
    return 0;
}