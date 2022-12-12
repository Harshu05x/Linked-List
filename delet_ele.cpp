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

void delet(int pos){
    Node *p = first,*q = NULL;
    int x;
    if(pos == 0){
        first = first->next;
        x = p->data;
        delete p;
    }
    else{
        for(int i = 0;i < pos && p;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
    }    
    delete p;
    cout<<x<<" deleted.";
}
int main()
{   
    int A[] = {3,5,7,9,11,15};
    create(A,6);
    cout<<"Enter index: ";
    int pos;
    cin>>pos;

    delet(pos);
       
    return 0;
}