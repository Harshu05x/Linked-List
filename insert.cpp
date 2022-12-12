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

// Inserting given ele at given index-->
void insert(int pos, int x){
    Node *t,*p;
    if(pos == 0){                                   // inserting ele at first pos
        t = new Node;                               // create a new node
        t->data = x;                                // store ele in node
        t->next = first;                            // new node will point on first
        first = t;                                  // first will point on new node...
    }
    else if(pos > 0){                               // inserting ele after 0th index
        p = first;                                  // create a pointer which will traverse through LL
        for(int i = 0;i < pos-1 && p ;i++){         // move p upto (p != null) and (p is on pos-1)
            p = p->next;                            
        }
        if(p){
            t = new Node;                           // create new node
            t->data = x;                            // store data in node
            t->next = p->next;                      // new node will point on p's next node
            p->next = t;                            // p will point on t
        }
    }
}

void display(Node *p){
    cout<<"Linked List--> ";
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}

// Inserting given ele in a sorted LL
void insert_sort(Node *p,int x){
    Node *t,*q;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if(first == NULL) first = t;
    else{
        while(p && p->data < x){
            q = p;
            p = p->next;
        }
        if(p == first){
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }

}
int main()
{   
    // int A[] = {3,5,7,9,11,15};
    // create(A,6);
    int pos = 0, x;
    int n;
    cout<<"How many no u want to insert: ";
    cin>>n;
    for(int i = 0; i<n;i++){
        cout<<"Enter next ele: ";
        cin>>x;
        insert(pos,x);
        pos++;
    }

    display(first);
    cout<<endl;
    cout<<"Enter an ele u want to insert: ";
    cin>>x;
    insert_sort(first,x);
    display(first);

    return 0;
}