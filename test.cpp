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
int main()
{   
    int A[] = {3,5,7,9,11,15};
    create(A,6);
       
    return 0;
}