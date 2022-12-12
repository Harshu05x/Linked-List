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
// Time -> O(n)     Space -> O(1)
void sum(Node *p){
    int count = 0;          // to count num of nodes in LL
    int sum = 0;            // to sum all ele in LL
    while(p != NULL){
        count++;
        sum += p->data;
        p = p -> next;
    }
    cout<<"Total no of nodes are: "<<count<<endl;
    cout<<"Sum of all ele is: "<<sum<<endl;
}

// Recursive Version
// Time -> O(n)     Space -> O(n)
int sum_01(Node *p){
    if(p == 0) 
        return 0;
    else 
        return sum_01(p->next)+p->data;
}
int count(Node *p){
    if(p) 
        return count(p->next)+1;
    else 
        return 0;
}

int main()
{
    int A[] = {3,5,7,9,11,15,12,8};
    create(A,8);
    // sum(first);
    cout<<"No of nodes are: "<<count(first)<<endl;
    cout<<"Sum of all ele is: "<<sum_01(first);
    return 0;
}