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

// Check given list is sorted or not...
void isSorted(){
    Node *p = first;
    int max = INT32_MIN;
    int result = 0;
    while(p){
        if(p->data < max){
            cout<<"Given Linked List is not sorted."<<endl;
            result = 1;
            break;
        }
        max = p->data;
        p = p->next;
    }
    if(result == 0)
    cout<<"Given Linked List is sorted."<<endl;
}

int main()
{   
    int A[] = {3,5,7,10,11,15};
    create(A,6);
    isSorted();
    return 0;
}