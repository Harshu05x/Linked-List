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
int isLoop(Node *f){
    Node *p,*q;
    p = q = f;
    do{
        p = p->next;
        q = q->next;
        q = q ? q = q->next : q;
    }while(p && q && p != q);
    return p == q ? 1 : 0;
}
int main()
{   
    struct Node *t1,*t2;    
    int A[] = {3,5,7,9,11};
    create(A,5);
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;                      // it will create loop in LL.

    isLoop(first) == 1 ? cout<<"It's Loop." : cout<<"It's Linear LL.";
    return 0;
}