#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
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

// Itreative version
void max_min(Node *p){
    int max = INT32_MIN;
    int min = INT32_MAX;
    while(p){
        if(p->data > max) max = p->data;
        if(p->data < min) min = p->data;
        p = p->next;
    }
    cout<<"Maximum no is: "<<max<<endl;
    cout<<"Minimum no is: "<<min<<endl;

}
// Recursive version
int max(Node *p){
    int x = 0;
    if(p == NULL) return INT32_MIN;
    else{ 
        x = max(p->next);
        return x > p->data ? x:p->data;
    }
}
int min(Node *p){
    int x = 0;
    if(p == NULL) return INT32_MAX;
    else{
        x = min(p->next);
        // below statement is called as Ternary Opertor
        return x < p->data ? x:p->data;         // If x is less than p->data 
                                                // then return x otherwise return p->data
    }
}
int main()
{
    int A[] = {3,5,7,9,11,15};
    create(A,6);
    max_min(first);
    cout<<"Maximum no is: "<<max(first);
    cout<<endl;
    cout<<"Minimum no is: "<<min(first);
     
    return 0;
}