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

// Itreative version
void linear_search(Node *p, int key){
    int count = 0,result = 0;
    while(p){
        if(p->data == key){
            cout<<"Ele is found at address "<<p<<endl;
            result = 1;
            break;
        }
        count++;
        p = p->next;
    }
    if(result == 0)
        cout<<"Ele not found"<<endl;
}

// Recursive version
Node *linear_search_01(Node *p, int key){
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return linear_search_01(p->next,key);
}

// Improved Linear search-->
// by Move To Head method...
Node *linear_search_02(Node *p, int key){
    Node *q = NULL;
    while(p){
        if(key == p->data){
            q->next = p->next;                  // q will point on p
            p->next = first;                    // p will point on first
            first = p;                          // first will move to p...
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
int main()
{   
    int A[] = {3,5,7,9,11,15};
    create(A,6);
    int key;
    cout<<"Enter ele u wanna search: ";
    cin>>key;
    // linear_search(first,key);
    Node *temp;
    temp = linear_search_02(first,key);
    
    if(temp) cout<<"Ele is found at address "<<temp;
    else cout<<"Ele is not found";

    return 0;
}